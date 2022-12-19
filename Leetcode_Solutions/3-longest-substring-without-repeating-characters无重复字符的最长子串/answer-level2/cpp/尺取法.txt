### 解题思路
尺取法，是一种典型的枚举区间的方法，一般就是枚举一对下标，保持区间内的数据满足一定规律，找最长、最短等等。
这种做法很常见，用于解决有一定规律的区间枚举问题。
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //尺取法
        int num[300] ;
        for(int i=0;i<300;i++){
            num[i] = 0 ;
        }
        int ans = 0 ;
        int l = 0 ;
        for(int i=0;i<s.length();i++){
            if(num[s[i]]>=1){
                while(l<s.length()){
                    num[s[l]]-- ;
                    l++;
                    if(num[s[i]]<=0){
                        break ;
                    }
                }
                i--;
            }else{
                ans = max(ans, i-l+1) ;
                num[s[i]]++ ;
            }
        }
        return ans ;
    }
};
```