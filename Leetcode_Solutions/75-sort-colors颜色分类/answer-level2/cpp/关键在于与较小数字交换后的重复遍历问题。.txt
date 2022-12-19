### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/76fa6a5aa719e7e4be568f0f7e626bfbae4b40fcc2cd2cdd64dbd45a2fa176ef-image.png)

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //boudary pointer and currennt pointer
        if (nums.empty()){
            return;
        }
        int p0 = 0;
        int p = 0;
        int p2 = nums.size() - 1;
        while(p <= p2) {
            if (nums[p] == 0) {
//大家都很纠结这里，为什么p这里交换完后要右移？
//原因是为了避免：数值较小的左边界超过当前数字。
//举例[0,1,2],p0 = 0, p = 0, p2 =2;
//交换后 [1,0,2], p0 = 0, p = 1(不右移), p2 =2;
//下一步[1，0，2], p0 = 0, p = 0, p2 =2;
//下一步[1,0,2], **p0 = 2,** p = 0, p2 = 2; 
//1, 2, 0, 
//1, 0, 2, 
//1, 0, 2, 
//1, 1397644077, 2, 
                swap(nums[p++],nums[p0++]);
            }else if (nums[p] == 2) {
                swap(nums[p],nums[p2--]);
            }else{
                p++;
            }
        }
    }
};
```