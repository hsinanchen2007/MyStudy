### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void* a,const void* b){
    return *(char*)a - *(char*)b;
}

bool canConstruct(char * ransomNote, char * magazine){
    if(strlen(ransomNote)==0)
        return true;
    if(strlen(magazine)==0)
        return false;
    
    qsort(ransomNote,strlen(ransomNote),sizeof(char),cmp);
    qsort(magazine,strlen(magazine),sizeof(char),cmp);
    int i=0,j=0;
    for(;j<strlen(magazine);){
        if(ransomNote[i]==magazine[j])
        {
            if(i==strlen(ransomNote)-1)
                return true;
            i++;j++;
        }else {
            j++;
        }
    }
    return false;
}
```