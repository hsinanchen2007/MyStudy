### 解题思路
注意：各位含有0的数字都需要排除

### 代码

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++){
            int t = i;
            while (t){
                if (t % 10 == 0)
                    break;
                if (i % (t % 10) != 0)
                    break;
                t /= 10;
            }
            if (t == 0)
                res.push_back(i);
        }
        return res;
    }   
};
```