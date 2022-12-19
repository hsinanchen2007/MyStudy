### 解题思路
思路：维护3个变量，imax用来存当前连续子序列的最大值，imin用来存当前连续子序列的最小值，
mymax用来不断迭代，找出最终连续子序列最大值，然后返回，需要注意，当当前的值是一个负数的时，
imax需要和imin进行交换。这样imax始终存的是当前连续子序列的最大值

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mymax = -65535;
        int imax = 1;
        int imin = 1;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] < 0)
            {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            mymax = max(mymax, imax);
        }
        return mymax;
    }
};
```