### 解题思路
1. 建立26个大写字母的映射，用于记录窗口中字符出现的次数，将`A`存到数组的`0`号下标的位置
2. 初始窗口指针`left`，`right`都为`0`，移动`right`，增大窗口，同时更新当前最长重复字符的长度。直到窗口长度过长，即不能通过替换`k`次形成重复字符时(此时可以通过`k+1`次替换满足)。收缩窗口，`left++`。但是这里可以不必更新`max_count`，因为当我们找到`max_count`之后，就一定能找到一个长度为`d`的区间使得`max_count + k = d`。我们只需要算出这个满足条件的`d`即可(这里通过right-left+1计算)。
3. 一直更新当前最长重复字符的长度，直到`right`指针遍历完字符串`s`

【注】还是看不懂的话，看[评论区](https://leetcode-cn.com/problems/longest-repeating-character-replacement/comments/)

### 代码

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0, right = 0, max_count =0;
        int alpha[26] = {0};
        while(right < s.size()){
            char c = s[right];
            alpha[c-'A']++;
            //max_count为某次扫描后，重复字母出现最多的次数
            max_count = max(max_count, alpha[c-'A']);
            if(right - left + 1 - max_count > k){
                alpha[s[left]-'A']--;
                left ++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};


```