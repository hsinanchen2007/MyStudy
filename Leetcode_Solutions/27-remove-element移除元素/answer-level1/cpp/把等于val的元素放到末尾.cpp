### 解题思路
把等于val的元素放（交换）到末尾

### 代码

```cpp
class Solution {
public:
    void swap(int& i, int& j)
    {
        int tmp = i;
        i = j;
        j = tmp;
    }

    int removeElement(vector<int>& nums, int val){
        int newlen = 0;
        int oldlen = nums.size();
        int i = 0;
        int j = oldlen - 1;
        // 把所有val值元素放到末尾
        while(i <= j)
        {
            if(nums[i] == val && nums[j] != val)
            {
                swap(nums[i], nums[j]);
                i++;
                newlen++;
            }
            else if(nums[i] == val && nums[j] == val)
            {
                j--;
            }
            else if(nums[i] != val && nums[j] == val)
            {
                j--;
                i++;
                newlen++;
            }
            else if(nums[i] != val && nums[j] != val)
            {
                i++;
                newlen++;
            }
        }
        return newlen;
    }
};
```