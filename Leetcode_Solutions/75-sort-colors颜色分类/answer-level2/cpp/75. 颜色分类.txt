### 解题思路
看官方样例就知道思路了。
难点是边界条件，即初始值和停止条件。

想一下，必须要处理过所有元素后才能停止（意思是必须对每个数都判断一下它是几），那么i必须要从0开始处理；left和right表明left左边（不含left）全为0与right右边（不含right）全为2，而right那个位置一定是没有被处理过的，但right右边的元素全都被处理过了，故i在等于right时仍要计算。

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0, left = 0, right = nums.size()-1;i<=right;i++){//i和right取等时才停止
            if(nums[i]==0) swap(nums[left++],nums[i]);//这里在交换过i和left后，i的位置不可能是2，所以i可以更新。
            if(nums[i]==2) swap(nums[right--],nums[i--]);//这里在交换过i和right后，由于不知道原来right是多少（有可能是0），所以不更新i。
        }
    }
};
```