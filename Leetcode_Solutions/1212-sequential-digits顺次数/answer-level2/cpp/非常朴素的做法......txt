思路就是一个个找。。。
```
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int gap=0, base=0;
        int n = low;
        while (n) {
            base = (base%10+1) + base*10;
            gap = gap*10 + 1;
            n /= 10;
        }
        int cur = base;
        while (cur < low) {
            if (cur%10 == 9) {
                base = (base%10+1) + base*10;
                gap = gap*10 + 1;
                cur = base;
            } else {
                cur += gap;
            }
        }
        while (cur < high) {
            result.emplace_back(cur);
            if (cur%10 == 9) {
                base = (base%10+1) + base*10;
                gap = gap*10 + 1;
                cur = base;
            } else {
                cur += gap;
            }
            
        }
        return result;
    }
};
```
![Screen Shot 2019-12-15 at 5.41.11 PM.png](https://pic.leetcode-cn.com/c61e86d3d76b0e5270010baef21b3d40c5b0b67f103b9a8097cc40bb99ef2bfd-Screen%20Shot%202019-12-15%20at%205.41.11%20PM.png)
