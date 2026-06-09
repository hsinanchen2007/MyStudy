### 解题思路
1.与26题出去相同元素数组的思想基本相同，使用两个指针，i指针用于标定需要替换的元素，j指针用于寻找需要传递的数值。
2.i指针初始化为0，j指针也初始化为0并遍历整个数组。
3.发现j指向的元素与val值不相同，就将值传递给i指向的数值并后移i指针，若发现j指向的指针与val值相同则直接后移j指针。
4.直接返回i，因为i指针指向最后一个改变数值的元素的后一个元素，因此直接返回i值表示新数组的长度。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int i = 0;
        for(int j = 0;j < nums.size();j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
```