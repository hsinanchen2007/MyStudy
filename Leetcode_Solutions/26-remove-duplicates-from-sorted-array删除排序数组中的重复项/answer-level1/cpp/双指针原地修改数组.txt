### 解题思路
1、指针i指向最后一个不重复的数字。
2、指针j指向下一个需要判断的数字。
3、如果j与i指向的数字不相同，将j指向的数字赋值给i + 1指向的位置，同时i,j右移一位；如果i与j指向的数字相同，j右移一位。
4、特殊处理只有一个数字的情况。

### 代码

```cpp
class Solution {
public:
int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2)
        return nums.size();
    int i = 0;
    int j = 1;
    while(j < nums.size()){
        if(nums[i] != nums[j]){
            nums[i + 1] = nums[j];
            i++;
        }
        j++;
    }
    
    return i + 1;
}
};
```