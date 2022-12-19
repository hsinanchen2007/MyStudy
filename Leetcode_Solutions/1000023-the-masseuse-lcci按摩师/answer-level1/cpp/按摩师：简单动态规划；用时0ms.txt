### 解题思路
定义数组value记录接受每位预约服务时总预约时间的最大值，状态转移方程为：value[i] = Math.max(value[i-2], value[i-3]) + nums[i];

### 代码
```java []
class Solution {
    public int massage(int[] nums) {
        int length = nums.length;
        int[] value = new int[length];
        int max = 0;
        for (int i = 0; i < length; i++) {
            if(i == 0 || i == 1) {
                value[i] = nums[i];
            } else if(i == 2){
                value[i] = nums[i] + nums[i-2];
            } else {
                value[i] = Math.max(value[i-2], value[i-3]) + nums[i];
            }
            max = value[i] > max ? value[i] : max;
        }
        return max;
    }
}
```
```python []
class Solution:
    def massage(self, nums: List[int]) -> int:
        value = []
        max = 0
        for i in range(len(nums)):
            if i == 0 or i == 1:
                value.append(nums[i])
            elif i == 2:
                value.append(nums[i-2] + nums[i])
            else:
                tmp = value[i-2] if value[i-2] > value[i-3] else value[i-3]
                value.append(tmp + nums[i])
            max = value[i] if value[i] > max else max 
        return max   
```
```c++ []
class Solution {
public:
    int massage(vector<int>& nums) {
        int length = nums.size();
        int max = 0;
        int* value = new int[length];
        for (int i = 0; i < length; ++i) {
            if(i == 0 || i == 1) {
                value[i] = nums[i];
            } else if(i == 2) {
                value[i] = nums[i] + nums[i-2];
            } else {
                value[i] = std::max(value[i-2], value[i-3]) + nums[i];
            }
            max = value[i] > max ? value[i] : max;
        }
        return max;
    }
};
```


