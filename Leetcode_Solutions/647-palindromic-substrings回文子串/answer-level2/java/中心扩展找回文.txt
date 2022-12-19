# 解题思路 中心扩展

- 有字符串`S = A0, A1, A2, A3 ... Aj, Aj+1 ... An`
- 从题目要求来看, 容易想到使用中心扩展法. 分别以`A0, A1, A2 ... An`为中心确认回文串, 每确认一个, 回文串数量cnt+1
- 当S长度为奇数时, 如`abbaeabba`, 回文串中心在`e`. 
- 当S长度为偶数时, 如`abba`, 回文串中心在`bb`.
- 所以整个字符串的回文子串, 需要分别统计中心为**一个点**和中心为**两个点**的情况. 

# Java Code
```java
class Solution {
    public int countSubstrings(String s) {
        int maxCount = 0;
        int s_len = s.length();
        // 每个长为N的字符串都有2N-1个中心
        for(int i = 0; i < s_len; i++){
            int oddPa = getPalindromeCnt(s, s_len, i, i);
            int evenPa = getPalindromeCnt(s, s_len, i, i+1);
            maxCount += oddPa + evenPa;
        }
        return maxCount;
    }
    
    public int getPalindromeCnt(String s, int s_len, int start, int end){
        int cnt = 0;
        // 每次中心确定相等后, 都确定了一个回文串. 随意回文开始结束的位置发生变化, 另一个新的回文串确认过程开始了.
        while(start >= 0 && end < s_len && s.charAt(start)==s.charAt(end)){
            start -= 1;
            end += 1;
            cnt++;
        }
        return cnt;
    }
}
```

# 复杂度

- 时间复杂度: 2 * (1 + 2 + 3 + ... + N) = O(2N^2)
- 空间复杂度: O(1)

# 执行效率

![image.png](https://pic.leetcode-cn.com/1ae66bc405c504d454069860ed17ebea6f50cd8b698f49a915fb4e4391ed16a1-image.png)
