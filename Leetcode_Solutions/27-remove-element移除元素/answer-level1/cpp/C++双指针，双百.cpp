### 解题思路
就是数组去重换皮，只不过这题相同的元素只有一个，定义一个慢指针和快指针，快指针扫到等于value的就跳过，不同的就将慢指针下一位替换为快指针当前值，由于要考虑第0号元素所以慢指针初始化为-1

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int i = -1;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
```