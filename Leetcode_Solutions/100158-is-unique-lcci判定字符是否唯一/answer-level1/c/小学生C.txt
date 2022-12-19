### 解题思路
此处撰写解题思路

### 代码

```c
bool isUnique(char* astr){
    int i,j,size=0;
    while(astr[size]!=NULL)
    {
        size++;
    }
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
        {
            if(astr[i]==astr[j])
                return false;
        }
    return true;

}
```