### 解题思路
此处撰写解题思路

### 代码

```c
bool canConstruct(char * ransomNote, char * magazine){
    int mark1[26]={0};//模拟HASH
    char mark[26];
    int i,j,length1=strlen(ransomNote),length2=strlen(magazine),length=0;
    if(length1==0)
    return true;
    if(length1>length2)
    return false;
    for(j=0;j<length2;j++)
    {   
        if(j<length2)
            mark1[magazine[j]-'a']++;//记录第二个字符串中的元素的个数
    }


    //妙啊 减少一个表
    for(i=0;i<length1;i++)
    {   
        mark1[ransomNote[i]-'a']--;
        if(mark1[ransomNote[i]-'a']<0)
        return false;
    }
    return true;
}
```