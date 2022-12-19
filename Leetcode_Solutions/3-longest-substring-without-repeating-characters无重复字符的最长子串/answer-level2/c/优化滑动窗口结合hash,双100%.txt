### 解题思路
用start储存子串起始下标，每当发现重复字符或字符串遍历完成就计算一遍当前子串长度
![QQ截图20200327184702.png](https://pic.leetcode-cn.com/44f30b7a58104102a0ac73df3fd9356cc7655e829fe320db0467aa9ec0d013d2-QQ%E6%88%AA%E5%9B%BE20200327184702.png)


### 代码

```c
int lengthOfLongestSubstring(char * s){
    int i, j = 0, count = 0, max = 0, index[128] = {0}, start = 0;
    for(i=0;s[i]!='\0';i++)     
    {
        if(index[s[i]]>start)   //index用来储存出现重复字符时
        {                       //子串起始下标应移动到的地方
            count = i-start;
            if(count>max)
            {
                max = count;
            }
            start = index[s[i]];
        }
        index[s[i]] = i+1;
    }
    count = i-start;
    return count>max?count:max;
}
```