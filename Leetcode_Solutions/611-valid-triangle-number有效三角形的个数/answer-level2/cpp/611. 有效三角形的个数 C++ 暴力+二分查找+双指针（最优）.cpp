### 解题思路
1.暴力法：先排序，三层遍历，最短的2条边之和要大于第三条边则计数+1；
2.二分查找：先排序，二层遍历，找第三条边时采用二分查找lower_bound
3.双指针：先排序：



1.暴力法：先排序，三层遍历，最短的2条边之和要大于第三条边则计数+1；(超时)

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < nums.size();i++){
            for (int j = i + 1; j < nums.size();j++){
                for (int k = j + 1; k < nums.size();k++){
                    if(nums[i]+nums[j]>nums[k]){
                        count++;
                    }else{
                        break;
                    }
                }
            }
        }

        return count;
    }
};
```
2.二分查找：先排序，二层遍历，找第三条边时采用二分查找lower_bound，找到大于等于nums[i]+nums[j]的索引index，index-1即使第三条边索引（必须满足大于第二条边索引j）
```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i <nums.size();i++){
            for (int j = i+1;j<nums.size();j++){
                int index = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                if(index>j+1){
                    count += (index - 1) - j;
                }


            }
        }

        return count;
    }
};
```


3.双指针：先排序：
1）从前向后或者从后向前遍历（其实都一样），i表示第三条边
2）left = 0，right = i-1
当nums[left]+nums[right]>nums[i]时，说明left最小值都已经满足了三角形条件，则left右侧的所有数值+right都满足，因此count += (right - left);right--
当nums[left]+nums[right]<=nums[i]时,说明right最大值都不能满足三角形条件，则当前left+right左侧的所有值都不满足，因此left++；

### 代码

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = nums.size()-1; i >=0;i--){
            int left = 0;
            int right = i - 1;
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    count += (right - left);
                    right--;
                }else{
                    left++;
                }
            }
        }

        return count;
    }
};
```