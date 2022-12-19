### 解题思路
只有小写字母，建立哈希表存储不同字符个数，再跟据赎金信一个个减

### 代码

```c
bool canConstruct(char * ransomNote, char * magazine){
    int hash[26]={0};
    for(char* iter=magazine;*iter!='\0';++iter)
        ++hash[*iter-'a'];
    for(char* iter=ransomNote;*iter!='\0';++iter)
        if(--hash[*iter-'a']<0)
            return false;
    return true;
}
```