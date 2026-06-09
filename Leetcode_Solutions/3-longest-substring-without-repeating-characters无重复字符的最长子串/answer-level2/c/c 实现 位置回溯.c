
用hash存储每一个字母的位置，需要回溯时，直接取这个值即可
但整体效率不是很高
```
int lengthOfLongestSubstring(char * s){
    int hash[127]={-1};//创建哈希表
    int flag=0;//子串初始长度
    int temp=0;//记录子串最长长度
    memset(hash,-1,127*sizeof(int));
    for(int i=0;s[i]!='\0';i++)
    {
        if(hash[s[i]%127]>=0)//如果当前元素在子串中存在
        {
            flag=0;//重置长度
            i=hash[s[i]];//回溯到上一个相同位置处，注意此处不需要+1，因为此轮循环结束后要+1
            memset(hash,-1,127*sizeof(int));
            continue;
        }
        else
        {
                flag++;
                hash[s[i]%127]=i;//设置此字母的位置，便于回溯
                if(flag>temp)temp=flag;//更新最长长度
        }
    }
    return temp;
}
```
