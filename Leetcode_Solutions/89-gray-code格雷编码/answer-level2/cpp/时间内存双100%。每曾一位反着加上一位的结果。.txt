### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/10dddd003d4a099751676d8913b0c7fef4af487c0274c8031b1bdc411d7d1bd4-image.png)

### 代码

```cpp

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        if (n==0) {
            return res;
        }
        res.emplace_back(1);
        if (n==1) {
            return res;
        }

        for (int i = n -1; i > 0; i--) {
            int x = 1 << (n - i);
            // cout<< "x:  "<<x << endl;
            size_t size = res.size() ;
            for (int m = size - 1; m >=0 ; m--) {
                // cout<<"   x+m:  " <<x+res[m] << endl;
                res.emplace_back(x + res[m]);
            }
        }
        return res;
    }
};
```