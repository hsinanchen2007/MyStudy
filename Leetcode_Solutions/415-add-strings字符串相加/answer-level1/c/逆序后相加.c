代码有点长
```c
void reverseString(char* s, int sSize) {
    int i = 0;
    int j = sSize-1;
    int tmp;
    while(i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

char * addStrings(char * num1, char * num2){
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    reverseString(num1, len1);
    reverseString(num2, len2);

    int k = 0;
    char * r ;
    if(len1 >= len2)
    {
        r = malloc(len1+2);
        memset(r, 0, len1+2);
    }
    else
    {
        r = malloc(len2+2);
        memset(r, 0, len2+2);
    }
    

    for ( ; *num1 && *num2 ; num1++, num2++)
    {
        r[k++] = ((*num1-0x30) + (*num2-0x30) + carry)%10 + 0x30;
        if((*num1-0x30) + (*num2-0x30) + carry>= 10)
            carry = 1;
        else 
            carry = 0;
    }

    if( (*num1 == '\0') && (*num2 == '\0'))
    {
        if(carry)
            r[k++] = carry+0x30;
    }
    else
    {
        for(;*num1 != '\0'; num1++)
        {
            r[k++] = (*num1 - 0x30 + carry)%10 + 0x30;
            if(*num1 - 0x30 + carry >= 10)
                carry = 1;
            else 
                carry = 0;
        }
        for(; *num2 != '\0'; num2++)
        {
            
            r[k++] = (*num2 - 0x30 + carry)%10 + 0x30;
            if(*num2 - 0x30 + carry >= 10)
                carry = 1;
            else 
                carry = 0;
        }
        if(carry)
            r[k] = 0x31;
    }
    reverseString(r, strlen(r));
    return r;
}
```