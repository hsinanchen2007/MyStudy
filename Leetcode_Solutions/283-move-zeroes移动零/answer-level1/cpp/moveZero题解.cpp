### 解题思路
此处撰写解题思路

时间复杂度O(n)
空间复杂度O(1)
### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(); //获取当前数组大小
        int zeroCount = 0;//数组zero计数器
        for(int i =0 ; i< size; i++){
            
            if (nums[i] == 0) { //当前位置是0 ,计数
                zeroCount ++ ;
            }
            
            if(nums[i] != 0){ //当前位置不是0 将值往前移动
                nums[i-zeroCount] = nums[i];
            }
        }
        
        //将后面设置为0
        for(int i = 0 ; i< zeroCount ; i++){
            nums[size-zeroCount+i] = 0;
        }
    }
};
```