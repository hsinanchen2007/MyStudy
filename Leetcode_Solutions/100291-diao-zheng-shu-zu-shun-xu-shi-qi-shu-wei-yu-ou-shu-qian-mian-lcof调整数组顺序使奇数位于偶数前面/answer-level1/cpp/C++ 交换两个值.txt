### 解题思路
遍历容器，将容器中为奇数的数放到数组前面去
自己设置一个指针用来表示交换的位置
### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int index=0;
        int temp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] % 2 != 0 &&index != i)
            {
                temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
                index++;
            }
            else if(nums[i] % 2 != 0 &&index == i)
            {
                index++;
            }
        }
        return nums;
    }
};
```