# 至多包含K个不同字符的字串
## 使用尺取法，4ms，6.7mB
```
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int st[256] = {0}, len = s.length();
        int l = 0, r = 0, cnt = 0, ans = 0;
        while(true){
            while(r < len){
                if(st[s[r]] == 0){
                    if(cnt + 1 > k){
                        break;
                    }
                    else{
                        cnt ++;
                    }
                }
                st[s[r ++]] ++;
            }
            ans = max(ans, r - l);
            if(r == len){
                break;
            }
            if((-- st[s[l ++]]) == 0){
                cnt --;
            } 
        }
        return ans;
    }
};
```
