### 解题思路
用一个数组存储每个字母出现的次数

### 代码

```c
int firstUniqChar(char * s){
    int a[26];
    int i;
    for(i=0;i<26;i++)a[i]=0;
    for(i=0;i<strlen(s);i++){
        a[s[i]-97]++;
    }
    for(i=0;i<strlen(s);i++)
        if(a[s[i]-97]==1)return i;
     return -1;   
}
```