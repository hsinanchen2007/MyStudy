### 解题思路
因为所有的数字都在0到n-1的范围内，那么我们可以将这些数字看成是指向nums的索引，
遍历数组，访问到一个数字的时候，我们根据索引对其指向的位置做一个标记，那么下次
我们又访问到该标记时，就可以确定重复的数字了。

这里我们做的标记是，对其加n。


### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {

        //索引法
        int res;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int n = nums[i]%size;
            if(nums[n] >= size){
                res = n%size;
                break;
            }
            else nums[n] += size;
        }
        return res;
    }
};
```
