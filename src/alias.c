// Macro definition
#define USES_ALIAS
#define USES_OPERAND

#include "riskxvii.h"

// Default size for the alias array
#define DEFAULT_ALIAS_SIZE 8

// add a new alias to the alias array
void addalias(aliasarr_t *a, uint32_t ln, Token *word, Token *reg)
{
    uint16_t index = a->ind;
    // If the current index is equal to the capacity of the array, double its capacity
    if (index == a->cap)
    {
        a->cap *= 2;
        a->arr = (alias_t *)realloc(a->arr, a->cap * sizeof(alias_t));
    }
    // Set the fields of the new alias
    a->arr[index].count = 0;
    a->arr[index].ln = ln;
    a->arr[index].word = (Token *)malloc(sizeof(Token));
    copytoken(a->arr[index].word, word);
    a->arr[index].reg = (Token *)malloc(sizeof(Token));
    copytoken(a->arr[index].reg, reg);
    ++a->ind;
}

// find an alias in the alias array
int32_t findalias(aliasarr_t *a, Token *word)
{
    // Iterate over all aliases in the array
    for (uint16_t i = 0; i < a->ind; i++)
    {
        if (strcmp(word->str, a->arr[i].word->str) == 0)
        {
            return i;
        }
    }
    // If the word is not found, return -1
    return -1;
}

// Function to initialize the alias array
aliasarr_t *initaliasarr(void)
{
    // Allocate memory for the alias array
    aliasarr_t *a = (aliasarr_t *)malloc(sizeof(aliasarr_t));
    a->ind = 0;
    a->cap = DEFAULT_ALIAS_SIZE;
    a->arr = (alias_t *)malloc(a->cap * sizeof(alias_t));
    // Return initialized array
    return a;
}

// Function to free the memory used by the alias array
void freealiasarr(aliasarr_t *a)
{
    // If the alias array is null, return
    if (a == 0)
        return;
    for (uint16_t i = 0; i < a->ind; i++)
    {
        // Free the memory used by the word and register tokens of each alias
        if (a->arr[i].word)
            freetoken(a->arr[i].word);
        if (a->arr[i].reg)
            freetoken(a->arr[i].reg);
    }
    // Free the memory used by the alias array
    free(a->arr);
    free(a);
}
