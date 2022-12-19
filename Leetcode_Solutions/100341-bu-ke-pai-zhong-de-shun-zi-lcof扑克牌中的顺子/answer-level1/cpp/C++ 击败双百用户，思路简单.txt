### 解题思路
哈希表
![image.png](https://pic.leetcode-cn.com/f5cefda891ade8f1018ed3857e50949c30f94c4d355f25853eee7dd36c642cec-image.png)


### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> hash(14, 0);
        int zero_num = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_num++;
            } else {
                hash[nums[i]] = nums[i];
            }
        }
        int left = 0;
        int right = 13;
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] > 0) {
                left = i;
                break;
            }
        }
        for (int i = hash.size()-1; i >=0; i--) {
            if (hash[i] > 0) {
                right = i;
                break;
            }
        }
        for (int i = hash.size()-1; i >=0; i--) {
            if (hash[i] > 0) {
                count++;
            }
        }

        if (right-left <= 4 && count + zero_num >= 5) {
            return true;
        }
        return false;
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/c084b9c3a4bdfa879c3d3640d9cbb1b26acca9bc92cf814d97ac2126b26dbac9-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
