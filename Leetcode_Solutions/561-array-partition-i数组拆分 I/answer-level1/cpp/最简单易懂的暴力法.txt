### 解题思路
因为两两成对，并且是每对中的最小值求和要最大，那么只要先排序（保证分对后第一个元素都比第二个元素小），然后把下表为奇数的元素相加起来就可以了。

### 代码

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int len = nums.size();
        int result=0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<len;i=i+2){
            result+=nums[i];
        }
        return result;
    }
};
```