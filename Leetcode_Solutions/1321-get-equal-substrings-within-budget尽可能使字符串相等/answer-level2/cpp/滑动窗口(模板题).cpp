### 同类型题：
[424.替换后的最长字符串](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)
[1052.爱生气的花点老板](https://leetcode-cn.com/problems/grumpy-bookstore-owner/)

### 解题思路
- 题目给出清楚要求，“**子字符串**”，子字符串要求连续。可以看出这是一道可以用滑动窗口解决的题目
- 使用变量`ans`记录当前可以转化的最大长度。
- 该题只要维护一个窗口，使得该窗口变更字符串时产生的cost**不大于**最大预算maxCost，然后计算该窗口大小。如果该窗口的大小比`ans`还大，则更新`ans`，直到比对完所有的字符串
- 代码易懂，看代码

### 代码

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) { 
        // 初始ans为0
        int ans = 0, cost = 0;
        int len = s.size();
        int left = 0, right=0;
        while(right < len){
            //扩大窗口
            cost += abs(t[right] - s[right]);
            //如果当前窗口的cost大于maxCost，右移left，缩小窗口，直到窗口的cost不大于maxCost
            while(cost > maxCost){
                cost -= abs(t[left] - s[left]);
                left ++;
            } 
            //如果当前窗口大小比上一次计算的ans还大，更新ans
            ans = max(ans, right-left+1);
            right++;            
        }
        return ans;
    }
};
```