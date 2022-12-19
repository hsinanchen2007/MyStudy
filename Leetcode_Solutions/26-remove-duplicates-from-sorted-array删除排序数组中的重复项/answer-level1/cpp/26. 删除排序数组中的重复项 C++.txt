### 解题思路
1.使用双指针，i指针用于定位需要替换的下标，j指针用于寻转不同数值。
2.j指针遍历数组从第1位开始，发现与i指针指向的数值不同则先后移i指针，再将j指向的数值赋值给i指向的数值。
3.不断循环直至j循环至数组最后一个元素。
4.返回i + 1，i指向数组中的最后一个不同元素，加一即表示整个不同数值数组的长度。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int i = 0;
        for(int j = 1;j < nums.size();j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
```