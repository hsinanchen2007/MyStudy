### 解题思路

思路：
将所有不等于val的元素放在数组前面，val放在数组后面。
遍历整个数组，如果该元素不等于val，那么就和k指向的元素交换。最后k的值就是不等于val的元素个数。
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //[0,k)表示所有与val不等的元素
        int k=0;//指向的是不等于val的值应该去交换的元素的位置
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=val)//只要不等于val那么就与k指向的元素交换，并维护k
                swap(nums[k++],nums[i]);
        }

        return k;
    }
};
```

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=val)
            {
                //针对可能全部元素都不等于val的情况
                if(k!=i)
                    swap(nums[k++],nums[i]);
                else 
                    k++;
            }
        }

        return k;
    }
};
```
因为不关心新数组范围外的其他元素，故直接赋值即可。
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]!=val)
                nums[k++]=nums[i];
        return k;
    }
};
```

