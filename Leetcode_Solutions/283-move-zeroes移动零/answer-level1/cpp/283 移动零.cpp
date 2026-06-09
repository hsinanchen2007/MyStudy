### 解题思路
双指针
![image.png](https://pic.leetcode-cn.com/dac0f3f16e91af76fe0f2156f952d7205884e28acf04a7242a90ea4c76cc27ec-image.png)


### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num = 0;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                it = nums.erase(it);
                num++;
            } else {
                it++;
            }
        }
        while (num-- > 0) {
            nums.push_back(0);
        }
    }
};
```