### 解题思路
    此题利用二分法查找较为简单。
    观察数组我们发现旋转之后的数组相当于是将数组循环左移若干位。将数组的中间元素与最后一个元素比较，若大于，例如4，5，6，7，1，2，3，显然最小元素在后半段，若小与，例如5，6，7，1，2，3，4，显然最小元素在前半段。此处注意，当中间元素大雨最后一个元素时，最小元素不可能是中间元素，但是当小于时，中间元素有可能是最小元素，因此分段时注意是否要将中间元素纳入。

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1,mid;
        while (low < high) {        //分段，直至low==high
            mid = (low + high)/2;
            if (nums[mid] > nums.back()) {
                low = mid+1;        //取后半段，不包括中间元素
            }
            else
                high = mid;     //取前半段，包括中间元素
        }
        return nums[low];
    }
};
```