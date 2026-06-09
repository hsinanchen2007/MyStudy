### 解题思路
**利用双指针**
**switch匹配**
左边 右边两个指针在非元音时候彼此向中间移动
在左边遇到元音停止，右边遇到元音停止，然后两者交换


**注意**：
元音包括大写和小写两者
并不是对称交换
### 代码

```c
int IsVowel(char ch){
        switch(ch){
        case'a':
        case'e':
        case'i':
        case'o':
        case'u':
        case'A':
        case'E':
        case'I':
        case'O':
        case'U':
            return 1;
        default:
            return 0;
            }
}
char * reverseVowels(char * s){
    int i ,j;
    char *temp;
    j=strlen(s) - 1;
    i=0;
    while( i<j)
    {   
        while(!IsVowel(s[i]) && i<j) 
               { i++;} 
        while(!IsVowel(s[j]) && i<j)  
               { j--;}
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
            
    }
    return s;
}
```