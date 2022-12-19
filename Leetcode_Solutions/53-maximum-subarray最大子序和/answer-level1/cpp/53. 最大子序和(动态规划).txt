### 解题思路
1.求最大子序列和MAX，初值为数组首元素，求和变量sum初值为数组首元素。
2.从数组第二个元素开始遍历。
3.将数组中当前元素与sum求和，所得结果与当前元素比较，将大一些的值赋值给sum。
 再将sum与MAX比较，将大一些的值赋值给MAX，一次循环结束。
4.重复上述操作，直到数组中元素全部遍历为止。
5.返回MAX。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = max(nums[i] + sum, nums[i]);
            MAX = max(MAX, sum);

        }
        return MAX;
    }
};
```