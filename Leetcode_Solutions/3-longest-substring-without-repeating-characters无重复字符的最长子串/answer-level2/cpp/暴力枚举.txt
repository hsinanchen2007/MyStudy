### 解题思路
以每个字母开头进行枚举，然后选出最大值。再枚举每个字母i时，比较字母i+1,i+2..直到有相同字母为止，记录为该字母开头的最大不同字母串。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int flag = 0;
        int res = 1;
        int max = 1;
        if(l == 0){
            return 0;
        }
        for(int i = 0; i<l;i++){
            for(int j = i+1;j<l;j++){
                for(int k = i;k<j;k++){
                    if(s[j] == s[k]){
                        flag = 0;
                        break;
                    }
                    else{
                        flag = 1;
                    }
                }
                if(flag==1){
                    res= res+1;
                }
                else if(flag == 0){
                    
                    break;
                }
            }
            if(max < res){max = res;}
            res = 1;
        }
        return max;
    }
};
```