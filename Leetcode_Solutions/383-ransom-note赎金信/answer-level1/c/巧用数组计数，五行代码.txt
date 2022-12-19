### 解题思路
此处撰写解题思路

### 代码

```c
bool canConstruct(char * ransomNote, char * magazine){
    int i,  a[30]={0}, b[30]={0};
    for(i=0;i<strlen(ransomNote);i++) a[ransomNote[i]-'a']++;
    for(i=0;i<strlen(magazine);i++) b[magazine[i]-'a']++;
    for(i=0;i<30;i++)  if(a[i]>b[i]) return false;
    return true;
}
```