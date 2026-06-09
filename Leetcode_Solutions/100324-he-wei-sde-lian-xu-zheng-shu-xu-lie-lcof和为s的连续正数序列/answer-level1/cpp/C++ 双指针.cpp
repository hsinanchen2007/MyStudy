
![捕获.JPG](https://pic.leetcode-cn.com/fdffa9ebd81a39a0619f8382a8c8fbb61cc967d0cd89221b52362bab1edaedaa-%E6%8D%95%E8%8E%B7.JPG)

直接计算出上界范围，然后用双指针

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target < 3) return {}; 
        int min_tail = (-1 + sqrt(1+8*target)) / 2;
        int max_tail = (target % 2) > 0 ? target / 2 + 1 : target / 2;

        
        vector<vector<int>> res;
        for(int i = min_tail, j = 1; i <= max_tail && j < i;) {
            int sum = ((j+i) * (i-j+1)) / 2;
            if(sum < target) i++;
            else if(sum > target) j++;
            else {
                vector<int> tmp;
                for(int k = j; k <= i; k++) {
                    tmp.push_back(k);
                }
                res.push_back(tmp);
                i++;
            }
        }

        return res;
    }
};
```