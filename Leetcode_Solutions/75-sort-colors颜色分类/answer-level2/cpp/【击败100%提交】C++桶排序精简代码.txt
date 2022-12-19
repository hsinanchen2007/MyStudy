![image.png](https://pic.leetcode-cn.com/6a089e98f0a4c9df66e425ad3317ecc5c9281247b45823fa013ec0cd724b7c02-image.png)


```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int stat[3] = {0};
        for(auto &element : nums) {
            ++stat[element];
        }
        int idx = 0;
        for(int i=0; i<3; ++i) {
            while(stat[i]-- > 0) {
                nums[idx++] = i;
            }
        }
    }
};
```
