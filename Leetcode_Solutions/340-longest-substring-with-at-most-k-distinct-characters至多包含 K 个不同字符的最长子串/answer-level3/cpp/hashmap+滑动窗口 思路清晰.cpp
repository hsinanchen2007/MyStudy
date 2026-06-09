### 解题思路
hashmap+滑动窗口
不明白的可以在评论留言，一起讨论。
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.size();
        int left=0,right=0,maxCount=0,maxLen = 0;
        unordered_map<char,int> unique;
        while(right < len){
            if(!unique.count(s[right])){
                maxCount++;
            }
            unique[s[right]]++;

            while(maxCount > k){
                if(unique[s[left]]==1){
                    maxCount--;
                    unique.erase(s[left]);
                }else{
                    unique[s[left]]--;
                }
                left++;
            }

            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};
```