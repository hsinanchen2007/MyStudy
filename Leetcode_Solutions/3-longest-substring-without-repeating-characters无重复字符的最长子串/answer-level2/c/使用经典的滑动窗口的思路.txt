### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int maxnum=0;//store the max different nunber
    int temp=0;//store the temp number if diffrent string
    int hash[128]={0};
    int length = strlen(s);
    char *i,*num;
    i=num=s;
    if(s==NULL)return 0;
    while(i<s+length)
    { 
        if(hash[*i]==0)
        {
            temp++;
             hash[*i]=1;
             i++;
             if(maxnum<temp)
             maxnum = temp;
        }
        else
        {
            while(*num!=*i)
            {
                hash[*num]=0;
                num++;
                temp--;
            }
            i++;
            num++;
        }
    }
    return maxnum;
}
```