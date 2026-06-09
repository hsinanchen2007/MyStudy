**解题思路：**
1、滑动窗口：指针i, j; i指向窗口前端，j指向后端，s[i]与s[j]不同，j++,如果相同，i++
原理：当遇到相同时，窗口内只有i,j指向的元素相同，i++后，窗口内任然不同
2、hash方法：当要插入一个元素，如果原本hash中已经是1了，那么就有重复了

方法1：代码
int lengthOfLongestSubstring(char * s){
int i,j,k=0,max=0,cnt=0;
for(i=0;s[i]!='\0';i++){
for(j=k;j<i;j++){
if(s[i]==s[j]){
if(cnt>max)max=cnt;
cnt=i-j;
k=j+1;
break;
}
}
if(j==i)cnt++;
if(cnt>max)max=cnt;
}
return max;
}

方法二：代码
int lengthOfLongestSubstring(char * s){
    
    int i, j, len, maxLen = 0, k, index;
    int hash[95];    //数字、下划线、大写字母、小写字母
    memset(hash, 0, sizeof(int) * 95);
    
    len = strlen(s);
    if (len == 1) 
        return 1;
    else if (len == 0)
        return 0;

    for (i = 0; i < len; i++)
    {
        k = 0;
        for (j = i; j < len; j++)
        {
           index = s[j] - 32;
           if (hash[index] == 1)
                break;
            else {
                hash[index] = 1;
                ++k;
            }
        }
        if (k > maxLen)
            maxLen = k;
        memset(hash, 0, sizeof(int) * 95);
    }
    return maxLen;
}