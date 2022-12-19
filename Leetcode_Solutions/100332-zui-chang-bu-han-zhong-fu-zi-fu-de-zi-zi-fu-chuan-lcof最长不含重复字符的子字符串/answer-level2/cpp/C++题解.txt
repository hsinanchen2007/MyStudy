采用滑动窗口的思想
问题的关键在于，当移动的过程中，遇到相同的元素要如何处理！
```
class Solution {
public:
    bool map[256];
    int left=0,right=0,maxlength=0,len;
    int lengthOfLongestSubstring(string s) {
        len = s.size();
        while(right < len){
            if(map[s[right]] == true){
                while(s[left] != s[right]){
                    map[s[left++]] = false;
                }
                left++;
            }else{
                map[s[right]] = true;
            }
            right++;
            maxlength = max(maxlength,right-left);
        }
        return maxlength;
    }
};
```
