参照英文版leetcode,@sniffsky@KidOptimo两位的[题解](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87739/Java-Strict-O(N)-Two-Pointer-Solution)写的滑窗解法，时间复杂度O(26\*n\*window_size)近似O(n);

```
class Solution {
public:
    int longestSubstring(string s, int k) {//sliding window
        int longstr=0;
        for(int needalpha=1;needalpha<=26;needalpha++){//在需要不同字符的前提下用sliding window
            unordered_map<char,int> map;
            int left=0,right=0;
            int windowalpha=0,nolessthank=0;
            while(right<s.size()){
                if(map[s[right]]++==0) windowalpha++;
                if(map[s[right]]==k) nolessthank++;
                right++;
                while(windowalpha>needalpha){
                    if(map[s[left]]--==k) nolessthank--;
                    if(map[s[left]]==0) windowalpha--;
                    left++;
                }
                if(windowalpha==needalpha&&nolessthank==windowalpha){
                    longstr=max(longstr,right-left);
                }    
            }
        }
        return longstr;
    }
};
```
