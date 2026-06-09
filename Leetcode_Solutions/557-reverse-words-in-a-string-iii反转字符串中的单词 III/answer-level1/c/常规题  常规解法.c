### 解题思路
此处撰写解题思路

### 代码

```c
char * reverseWords(char * s){
    int len=strlen(s);
    int i=0,j=0;
    while(j<len){
        i=j;
        while(s[j]!='\0'&&s[j]!=' ')
            j++;
        int low=i;
        int high=j-1;
        while(low<high){
            char temp=s[low];
            s[low]=s[high];
            s[high]=temp;
            low++;
            high--;
        }
        j++;
    }
    return s;
}
```