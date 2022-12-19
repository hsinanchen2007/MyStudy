![image.png](https://pic.leetcode-cn.com/8f8cea6e4ef6da0847921ddfa64f039419f95581924f3e5102e73ef60bd9c710-image.png)
解题思路：按二进制位计算，异或交换，结果不变，数组中所有元素异或后得出的就是独一无二的数。
```
    int singleNumber(vector<int>& nums) {
        int res=0;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            res=nums[i]^res;
        }
        return res;
    }
```
