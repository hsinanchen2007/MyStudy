**题解：**
字符表来表示窗口，**窗口的大小与新字符的最大计数之间的差值表示可以替换的字符个数**，当可以替换的字符个数大于k时，我们需要缩小窗口，也就是left右移，直到可以替换的字符个数等于k时，我们可以得到结果。

**关于maxCount的解释（感谢评论下方的小伙伴）：**
因为我们只对最长有效的子字符串感兴趣，所以我们的滑动窗口不需要收缩，即使窗口可能覆盖无效的子字符串。我们可以通过在右边添加一个字符来扩展窗口，或者将整个窗口向右边移动一个字符。而且我们只在新字符的计数超过历史最大计数(来自覆盖有效子字符串的前一个窗口)时才增长窗口。也就是说，我们不需要精确的当前窗口的最大计数;我们只关心最大计数是否超过历史最大计数;这只会因为新字符而发生。

**补充：**
同样的解法也适用于[1004. 最大连续1的个数 III](https://leetcode-cn.com/problems/max-consecutive-ones-iii/solution/hua-dong-chuang-kou-de-chang-gui-jie-fa-by-xiaonen/)。

**推荐：**[leetcode刷题总结之滑动窗口](https://blog.csdn.net/qq_43152052/article/details/102840715)

**代码如下：**
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26]={0};//建立字符->字符数量的映射
        
        int left=0,right=0,result=0,maxCount=0;
        
        while(right<s.size())
        {
            count[s[right]-'A']++;
            maxCount=max(maxCount,count[s[right]-'A']);//当前窗口内的最多字符的个数
            if(right-left+1-maxCount>k){//需要替换的字符个数就是当前窗口的大小减去窗口中数量最多的字符的数量
                count[s[left]-'A']--;//缩小窗口
                left++;
            }
            //当窗口内可替换的字符数小于等于k时，我们需要根据该窗口长度来确定是否更新result
            result=max(result,right-left+1);
            right++;
        }
        
        return result;
    }
};
```
