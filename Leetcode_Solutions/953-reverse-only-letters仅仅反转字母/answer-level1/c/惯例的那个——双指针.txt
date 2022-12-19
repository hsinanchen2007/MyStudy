```
int isWord(char ch) //判断字符是否为字母
{
    if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z'))
        return 1;
    return 0;
}

char * reverseOnlyLetters(char * S){
    char ch1,ch2;
    int i,j;

    i =0,j = strlen(S)-1;

    while(i<j)
    {
        ch1 = S[i];
        ch2 = S[j];

        if(isWord(ch1)&&isWord(ch2))
        {
            char temp = ch1;
            S[i] = S[j];
            S[j] = temp;
            i++,j--;
        }

        //若字符非字母，移动指针位置
        if(!isWord(ch1)) 
            i++;
        if(!isWord(ch2))
            j--;
    }
    
    return S;
}

```
