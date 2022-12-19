### 解题思路
先判断传入的数组长度，如果是0直接返回0。由于本题是非降序数组传入，如果数组元素相等则位置必定相邻。用pos表示相邻元素不同时，后一个元素（即相对于前半部分不同的元素）应放入的位置。此时还有最后一种情况，数组元素都相同，那此时pos=1与有两个相异元素混淆，所以加入count计算相异元素的个数。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length=nums.size();
        if(length==0){return 0;}
        int pos=1;
        int count=0;
        for(int i=0;i<length-1;++i)
        {
            
            if(nums[i]!=nums[i+1])
            {
                nums[pos]=nums[i+1];
                pos++;
                count++;
            }
        }
        if(count==0){return 1;}
        else{
            return pos;
        }
    }
};
```