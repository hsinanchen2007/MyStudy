### 解题思路
思路有点像快排。
### 代码

```c
char * reverseVowels(char * s){
    int i=0;
    int j=strlen(s)-1;
    while(i<j)
    {
        while(i<j&&s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'&&s[j]!='A'&&s[j]!='E'&&s[j]!='I'&&s[j]!='O'&&s[j]!='U')
        {
            j--;
        }
        while(i<j&&s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U')
        {
            i++;
        }
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    return s;
}
```