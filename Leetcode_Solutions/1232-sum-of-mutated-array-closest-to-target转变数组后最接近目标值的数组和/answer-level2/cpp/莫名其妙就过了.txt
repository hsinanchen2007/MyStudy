### 解题思路
首先观察数据发现二分的起点应该是0，因为可以取到比所有数组元素小的数字，如果求和发现比target小，说明应该往右边找，这样才能想办法更接近，最后因为left要+1，所以最后的left代表right，left-1代表left，最终结果无非有这么几种：
1.取left的结果在target左边，取right的结果在target右边，那么通过判断left-1和left哪个差值小，那个就是答案
2.取left的结果在target左边，取right的结果等于target，那么left的差值必然小于left-1
3.取left和right的结果都在target左边，那么left-1的差值必然大于left
4.取left和right的结果都在target右边，那么left的差值必然大于left-1
所以通过最后比较left和left-1哪个差值小取哪个就可以得到答案。
而我想题目中方案相同时取左边这个可以解释为当left-1差值和left差值相同，也即left和target的差值与right和target的差值相同时取左边，这个也可以通过最后的if判断就可以实现。
### 代码

```cpp
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.back();
        int mid = -1;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            int sum = 0;
            for(int i = 0 ; i < arr.size() ; ++i)
            {
                if(arr[i] < mid)
                    sum += arr[i];
                else
                    sum += mid;
            }
            if(sum < target)
                left = mid + 1;
            else
                right = mid;
        }
        int sum1 = 0, sum2 = 0;
        for(int i = 0 ; i < arr.size() ; ++i)
        {
            if(arr[i] < left)
                sum1 += arr[i];
            else
                sum1 += left;

            if(arr[i] < left - 1)
                sum2 += arr[i];
            else
                sum2 += left - 1;
        }
        if(abs(sum2 - target) <= abs(sum1 - target))
            return left - 1;
        else
            return left;
    }
};
```