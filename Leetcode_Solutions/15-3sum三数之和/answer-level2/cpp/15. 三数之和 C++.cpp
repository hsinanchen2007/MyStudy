### 解题思路
1.使用三指针法。数组遍历指针i，左指针L,右指针R。
2.先将nums排序，再从数组头遍历数组，i为遍历数组指针，L = i + 1，R = 数组尾元素指针。
3.保证L < R的基础上先检查i所指的元素是否大于0，若大于0则直接跳出遍历数组(因为i指针一直指向的三个元素中较小的元素)，再计算i，L，R所指的元素之和是否等于0，若等于则将三个元素压入result。
4.若三个指针元素之和小于0，则向右移动L指针(去同值移动)，若三个指针元素之和大于0，则向左移动R指针(去同值移动)，并保持L < R。
5.遍历完所有的数组返回result。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        int len = nums.size();
        if(len < 3){
            return result;
        }
        
        sort(nums.begin(),nums.end());
        for(int i = 0;i < len;i++){
            if(nums[i] > 0){
                break;// 如果当前数字大于0，则三数之和一定大于0，所以结束循环
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;//去重
            }
            int L = i + 1;
            int R = len - 1;
            while(L < R){
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0){
                    result.push_back(vector<int> {nums[i],nums[L],nums[R]});
                    while(L < R && nums[L] == nums[L + 1]) L++;//去重
                    while(L < R && nums[R] == nums[R - 1]) R--;//去重
                    L++;
                    R--;
                }
                else if(sum < 0){
                    L++;
                }
                else if(sum > 0){
                    R--;
                }
            }
        }
        return result;
    }
};
```