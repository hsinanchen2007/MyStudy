### 解题思路
同26题，设置单指针

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //同26题，设置单指针
        if (nums.empty()) return 0;

        int k = 0;
        int count_1 = 1;//计数不等于val的元素
        int count_2 = 0;//记录第一个不等于val的元素位置

        for(int i = 0; i < nums.size(); i++){
            //找到第一个不等于val的值
            if (nums[i] != val){
                count_2 = i;
                break;
            }
           if(i == nums.size() - 1)
                //全部等于val时返回0
                return 0;
        }
        if(count_2 != 0)
            nums.erase(nums.begin(), nums.begin() + count_2);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != val){
                nums[++k] = nums[i];
                count_1++;
            }
        }
        
        nums.erase(nums.begin() + count_1, nums.end());

        return nums.size();
        
    }
};
```