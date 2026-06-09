### 解题思路
1.先排序
2.具体选哪三个数相乘，需要分情况数组中数的正负号：
a.全是正数
b.全是负数
c.有正有负，比如-2 -1,...10或者-2,1,...10
3.但结果其实主要是：nums[n-1]*nums[n-2]*nums[n-3] (代表情况a,b)和nums[0]*nums[1]*nums[n-1] (代表情况c)

### 代码

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        //第一种：给定的数全是负数，
        //第二种：负数和正数都有
        //第三种：全是正数
        //首先对数组排序，答案不外乎是后三个数相乘或者前两个数乘以最后一个数，两种
        int n = nums.size();
        int a = nums[n-1]*nums[n-2]*nums[n-3];
        int b = nums[0]*nums[1]*nums[n-1];

        if(a > b|| nums[n-1] < 0)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
};
```