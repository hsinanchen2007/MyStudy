```
char * removeDuplicates(char * S)
{
    if(S == NULL)
    {
        return NULL;
    }
    int s_len;
    s_len = strlen(S);
    if(1 == s_len)
    {
        return S;
    }
    char * stack_arr;
    stack_arr = (char *)malloc((s_len+2)*sizeof(char));
    stack_arr[s_len+1] = '\0';
    int i = 1;
    int top  = 1;
    int k = 0;
    stack_arr[top] = S[0];
    while(i<s_len)
    {
        //printf("%c %c\n",S[i], stack_arr[top]);
        if(S[i] != stack_arr[top])
        {
           // printf("%c %c %d %d\n",S[i], stack_arr[top],i,7);
            stack_arr[top+1] = S[i];
            top++;
            i++;
            //printf("%d %d %c %c %c\n",i,top,stack_arr[top-1],stack_arr[top],S[i]);
        }
        else
        {
            top--;
            //printf("%d %d\n",i,top);
            if(top == 0)
            {
                i++;
                top++;
                stack_arr[top] = S[i];
               //printf("%d %d %c %c\n",i,top,stack_arr[top],S[i]);
            }
            i++;
            //printf("%d %d %c\n",i,top,stack_arr[top]);
        }
    }
    stack_arr[top+1] = '\0';
    //printf("%d\n",top);
    
    char *res = (char *)malloc((top+1)*sizeof(char));
    res[top] = '\0';
    for(i=0; i<top; i++)
    {
        res[i] = stack_arr[i+1];
    }
        
        return res;

}
```
