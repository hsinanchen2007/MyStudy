### 解题思路
哈希表
![码农黑板报.png](https://pic.leetcode-cn.com/1a30daa058ee424cb7b7b69e25186f416f0a1ce291cbbf83745a2cd8740a8906-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
![image.png](https://pic.leetcode-cn.com/48b4082bf3fe8284eb507da09ad94804346efd2e0a79cc801438f53bf42eb1ab-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> hash(101, 0);
        vector<int> tmp = nums;
        std::sort(tmp.begin(), tmp.end());
        int count = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (i > 0 && tmp[i] > tmp[i-1]) {
                count = i;
            }
            hash[tmp[i]] = count;
        }
        for (int i = 0; i < nums.size(); i++) {
            res[i] = hash[nums[i]];
        }
        return res;
    }
};
```