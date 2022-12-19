### 解题思路
**如果数列降序，则不存在更大的字典排列。这是特列。
1.考虑把一个数列分成无数个上述特列解决
2.从后往前遍历数组，找到第一个使得从它开始后面的数列不降序的元素位置notDes
3.下一个更大的字典排序，必为：notDes位置的元素与其后较大的最近的那个元素交换后，再将notDes后的元素升序排列的数组

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        int notDes;
        //从后往前找到第一个不降序的元素
        notDes = indexDes(nums);
        if(notDes==-1){
            sort(nums.begin(), nums.end());
            return;
        }
        //找到最近的较大的那个数字交换
        int maxDis = INT_MAX, index;
        for(int i=notDes+1;i<nums.size();i++){
            if(nums[i]>nums[notDes]){
                if(maxDis>nums[i]-nums[notDes]){
                    index = i;
                    maxDis = nums[i]-nums[notDes];
                }
            }
        }
        swap(nums[notDes], nums[index]);
        sort(nums.begin()+notDes+1, nums.end());
    }
    int indexDes(vector<int> nums){
        bool flag = true;
        int i;
        for(i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                flag = false;
                break;
            }
        }
        if(flag==true)return -1;
        return i-1;
    }
};
```