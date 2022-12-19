### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char * s){
    int letter[52]={0};
    int num=0,MaxLength=0;
    for(char *p=s;*p!='\0';p++)
    {
        if(*p>='A'&&*p<='Z') letter[*p-'A']++;
        if(*p>='a'&&*p<='z') letter[*p-'a'+26]++;
        num++;
    }
    for(int i=0;i<52;i++)
        MaxLength+=letter[i]/2*2;
    if(MaxLength<num)
        return MaxLength+1;
    else
        return MaxLength;
}
```