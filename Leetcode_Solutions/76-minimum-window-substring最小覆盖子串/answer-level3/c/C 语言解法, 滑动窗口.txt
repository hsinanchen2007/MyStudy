### 解题思路
参考大佬[@labuladong](/u/labuladong/)的算法思想，写出 C lang 的版本

![image.png](https://pic.leetcode-cn.com/4a8d1049c28904c30a107b715600250898a5e8ea2c59b3d71f55d792ccc418a4-image.png)

### 代码

```c
#define LEN  125
char* minWindow(char* s, char* t)
{
    int hash[LEN] = {0};
    int start=0, end=0, tLen=strlen(t), sLen=strlen(s);
    int minStart=0, minLen=INT_MAX;
    /*
		利用 hash 表判断字母是否在 t 串中:
		1、对于不属于 t 串的字母 赋予最小值
		2、属于的则统计

    */
    for(int i = 0; i < LEN; i++) hash[i] = -999; //不能直接赋值 INT_MIN,后续还要自减呢，会溢出
    for(int i = 0; t[i]; i++) hash[t[i]] = 0; 	
    for(int i = 0; t[i]; i++) hash[t[i]]++;	//统计 t 串字母出现的次数
    while(end < sLen)
    {
    	//若 s 串有 t 串的字母，则对应的哈希表减一，tlen 也减一
        if(hash[s[end]]-- > 0) tLen--; 
        end++; //窗口继续滑动
        while(tLen == 0) //当匹配到一个有效的子串
        {
            if(end-start < minLen) //更新最小串
                minStart=start, minLen=end-start;
            hash[s[start]]++;//开始缩小窗口
            //若 s[start] 在 t 串中，则 tlen 要++,说明缩小之后，当前窗口不存在有效的子串了
            if(hash[s[start]] > 0) tLen++; 
            start++; //接着移动
        }
    }
    if(minLen != INT_MAX)//若找得到
    {
    	// 写法一：
        // char* t = (char*)malloc(sizeof(char)*(minLen+1));
        // *t = '\0';
        // strncat(t, s+minStart, minLen);
        // return t;
        // 写法二：emmm~ 这个写法会小一丢丢的空间复杂度
        s[minStart+minLen] = '\0';
        return s+minStart;
    }
    return "";//那就找不到啦
} 