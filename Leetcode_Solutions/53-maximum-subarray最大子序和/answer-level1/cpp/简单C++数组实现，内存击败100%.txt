### 解题思路
新建一个arr数组，用nums[0]进行初始化，然后从i=1开始遍历nums数组，将nums[i]与arr[i-1]比较，取大的。
如果nums[i]大，说明与前面的数相加会减小这个数组，所以之后的数组将以此数开始；
如果nums[i]+arr[i-1]大，这很好理解，就是加上去让子序列越来越大。
也就是：
![微信图片_20200324115736.jpg](https://pic.leetcode-cn.com/d89e7cf44cac247aab6e0025bab97de9c1c4246e2693b78b0eacbbf5c20fd67a-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200324115736.jpg)
这时候取数组arr的最大值就是最大连续子序列的值。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(!n)return {};
        if(n==1)
        {
            return nums[0];
        }

        vector<int> arr;
        arr.push_back(nums[0]);
        for (int i=1;i<n;++i)
        {
            int temp=max(nums[i]+arr[i-1],nums[i]);
            arr.push_back(temp);
        }
        vector<int>::iterator p=max_element(arr.begin(),arr.end());
        return *p;
        
        
    }
};
```