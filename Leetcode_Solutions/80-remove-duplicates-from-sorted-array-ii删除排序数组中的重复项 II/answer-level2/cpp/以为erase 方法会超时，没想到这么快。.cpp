### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/55f64738444bf9b7700658b2307212397a1cb4bc1dc40a61f0683188e385a33e-image.png)

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        uint8_t count{1};
        int tempN = nums[0];
        auto p = nums.begin()+1;
        while(p != nums.end()){
            if (*p == tempN) {
                tempN = *p;
                ++count;
                if (count > 2) {
                    nums.erase(p);
                }else{
                    p++;
                }
            } else {
                tempN = *p;
                count = 1;
                p++;
            }
        }
        return nums.size();
    }
};
```