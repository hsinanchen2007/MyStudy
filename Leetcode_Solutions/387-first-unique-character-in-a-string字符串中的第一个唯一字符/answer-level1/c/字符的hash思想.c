```
#define charnumber 26
int firstUniqChar(char * s)
{
    if(s == NULL)return -1;
    if(strlen(s) == 1)return 0;
    int len = strlen(s);
    int nums[charnumber] = {0};
    for(int i=0;i<len;i++)
    {
        nums[s[i]-'a']++;   
    }
    for(int i=0;i<len;i++)
    {
        if(nums[s[i]-'a'] == 1)return i;
    }
    return -1;
}
```
