### 解题思路
首先重复肯定错误。然后将所有可能的情况模拟一遍，看看是否是顺子，极其暴力。

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int hash[14] = {0};
        for(auto e: nums){
            hash[e]++;
            if(hash[e] > 1 && e != 0){
                return false;
            }
        }
        for(int i = 1; i <= 9; i++){
            int cnt = 0;
            int joker = hash[0];
            for(int j = i; j <= i + 4; j++){
                if(hash[j] == 1){
                    cnt++;
                }
                else if(joker != 0){
                    cnt++;
                    joker--;
                }
            }
            if(cnt == 5) return true;
        }
        return false;
    }
};
```