### 解题思路
由于该数组是升序排列的，自然可以想到用二分查找，设置两个指针分别指向数组两头
然后进行二分查找，当我们找到的中值nums[mid]==target时，就可以利用left和right指针进行缩小范围了
当nums[left]<target时，左指针右移；当nums[right]>target时，右指针左移。
直到当nums[mid]==target，且nums[right]==target&&nums[left]==target时，left和right指针分别指向target的头尾，此时搜索完毕，返回left和right即可。
如果最终都没有搜索到则返回[-1,-1]

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>target){
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]==target){
                if(nums[right]>target)
                    right--;
                else if(nums[left]<target)
                    left++;
                if(nums[right]==target&&nums[left]==target)
                    return vector<int>({left,right});
            }
        }
        return vector<int>({-1,-1});
    }
};
```![image.png](https://pic.leetcode-cn.com/fedb9883d4b8e48b88c5f6e01026b9363196b238b6db2589300eb675b8681b24-image.png)

