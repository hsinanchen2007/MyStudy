### 解题思路
从平方根开始，挨个减1，只要满足能被整除就跳出。

### 代码

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int seed1 = sqrt(num+1);
        int seed2 = sqrt(num+2);
        int minval1 = INT_MAX;
        int minval2 = INT_MAX;
        bool b1 = true;
        bool b2 = true;
        vector<int> min1;
        vector<int> min2;
        for (int i=0; i<max(seed1, seed2); i++) {
            if (b1 && seed1>i && (num+1)%(seed1-i)==0) {
                b1 = false;
                minval1 = abs((num+1)/(seed1-i)-(seed1-i));
                min1.push_back((num+1)/(seed1-i));
                min1.push_back(seed1-i);
            }
            if (b2 && seed2>i && (num+2)%(seed2-i)==0) {
                b2 = false;
                minval2 = abs((num+2)/(seed2-i)-(seed2-i));
                min2.push_back((num+2)/(seed2-i));
                min2.push_back(seed2-i);
            }
            if (!b1 && !b2) break;
        }
        return minval1 < minval2 ? min1 : min2;
    }
};
```