```
void DGletterCombinations(char * digits, int* returnSize,char **letters,char *result,char **res,int idig)
{
    if(idig == strlen(digits))
    {
        res[(*returnSize)] = (char*)calloc(strlen(digits) + 1, sizeof(char));
        strcpy(res[(*returnSize)], result);
        res[(*returnSize)][strlen(digits)] = '\0';
        (*returnSize)++;  
        return ;
    }
    else
    {
        
        for(int ilet = 0; ilet < strlen(letters[digits[idig] - 50]); ilet++)
        {
            result[idig] = letters[digits[idig] - 50][ilet];
            DGletterCombinations(digits, returnSize, letters, result, res, idig + 1);
        }
    }
    
}
char **letterCombinations(char * digits, int* returnSize)
{
    (*returnSize) = 0;
    if(strlen(digits) == 0)
    {
        return NULL;
    }
    char *LetterBox[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char *result = (char*)calloc(strlen(digits) + 1,sizeof(char));
    int lenth = strlen(LetterBox[digits[0] - 50]);
    for(int i = 1; i < strlen(digits); i++)
    {
        lenth *= strlen(LetterBox[digits[i] - 50]);
    }
    char **res = (char**)malloc(lenth*sizeof(char*));
    DGletterCombinations(digits, returnSize, LetterBox, result, res, 0);
    return res;
}
```
