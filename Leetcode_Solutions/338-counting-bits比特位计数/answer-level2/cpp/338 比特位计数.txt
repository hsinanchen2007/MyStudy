### 解题思路
![image.png](https://pic.leetcode-cn.com/56f0f0f3947448f9224b79c9d7285f163b1cbfcb63913c9a0d210da3ee478d8d-image.png)
静态变量存储临时值

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        static vector<int> mm;
        int len = mm.size();
        for (int i = len; i <= num; i++) {
            int t = i;
            int count = 0;
            while (t) {
                if(t & 1) count++;
                t = t >> 1;
            }
            mm.push_back(count);
        }
        vector<int> res(mm.begin(), mm.begin() + num + 1);
        return res;
    }
};
```