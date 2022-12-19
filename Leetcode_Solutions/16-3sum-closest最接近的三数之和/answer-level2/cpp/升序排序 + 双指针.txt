### 解题思路
1、对vector升序排序。

2、遍历排序后的nums：
nums[k]作为第一个数，
指针 i = k+1，用于找第二个数；
指针 j = len-1，用于找第三个数；
sum3 = nums[k] + num[i] + num[j]。

3、双指针的移动规则：
sum3 > target，需要减小sum3的值，j--选择较小的正数；
sum3 < target，需要增加sum3的值，i++选择较大的负数；
sum3 = 0，直接返回target。

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if( len < 3 ) return 0;

        sort(nums.begin(), nums.end());

        int k, i, j, xx = nums[0] + nums[1] + nums[2];
        for(k=0; k<len-2; k++)
        {
            i = k + 1, j = len - 1;
            while( i < j )
            {
                int sum3 = nums[k] + nums[i] + nums[j];
                if( fabs( sum3 - target ) < fabs( xx - target ) )
                    xx = sum3; 
                if( sum3 > target ) j--;
                else if( sum3 < target ) i++;
                else return target;
            }
        }
        return xx;
    }
};
```