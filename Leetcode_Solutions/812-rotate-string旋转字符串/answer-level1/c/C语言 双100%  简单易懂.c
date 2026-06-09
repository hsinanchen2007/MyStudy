```
bool rotateString(char * A, char * B){
    int i, len = strlen(A);
    if(strcmp(A, B) == 0)
        return true;
    for(i = 0;i < len;i++)
    {
        char a = A[0];
        for(int j = 1;j < len;j++)
        {
            A[j - 1] = A[j];
        }
        A[len - 1] = a;
        if(strcmp(A, B) == 0)
        {
            return true;
        }
    }
    return false;
}
```
