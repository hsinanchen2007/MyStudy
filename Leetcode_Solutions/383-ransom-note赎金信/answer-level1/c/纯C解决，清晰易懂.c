利用两个hash分别记录两个字符串的元素的个数，这道题的本质其实就是第一个字符串中的元素的个数都要小于或者等于第二个元素的个数，根据这一点，得到第一个字符串中的每个元素的个数，然后和第二个元素的个数去比较即可。
```

bool canConstruct(char * ransomNote, char * magazine){
    int mark1[26]={0},mark2[26]={0};//模拟HASH
    char mark[26];
    int i,j,length1=strlen(ransomNote),length2=strlen(magazine),length=0;
    if(length1==0)
    return true;
    if(length1>length2)
    return false;
    for(i=0,j=0;i<length1||j<length2;i++,j++)
    {   
        if(i<length1)//记录第一个字符串中的元素的个数
            {
                mark1[ransomNote[i]-'a']++;
                if( mark1[ransomNote[i]-'a']==1)
                mark[length++]=ransomNote[i];
            }
        if(j<length2)
            mark2[magazine[j]-'a']++;//记录第二个字符串中的元素的个数
    }
    for(i=0;i<length;i++)
    {
        if(mark1[mark[i]-'a']>mark2[mark[i]-'a'])
        return false;
    }
    return true;
}
```
优化一下，利用一个hash表来保存，只记录第二个字符串的元素个数。时间效率再提升！
```

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
    for(i=0;i<length1;i++)
    {   
        mark1[ransomNote[i]-'a']--;
        if(mark1[ransomNote[i]-'a']<0)
        return false;
    }
    return true;
}
```

