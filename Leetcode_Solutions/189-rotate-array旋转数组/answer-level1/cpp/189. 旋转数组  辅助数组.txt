### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k){
        //采用双数组（这样不满足O（1））
        int* a=new int [size(nums)];
        for(int i=0;i<size(nums);i++){
            a[(i+k)%size(nums)]=nums[i];        
        }
        for(int i=0;i<size(nums);i++){
            nums[i]=a[i];
        }
    }
};
```