### 解题思路
1.降序的序列无法找到下一个排列。
2.如果一个数左边的有比它小的数，我们交换它就能得到一个更大的排列，但不是最小的更大排列。

由此，我们先从右往左寻找不可生成下一个排列的子序列，也就是递减的序列。
分情况
1.若整个序列都递减，那么直接反转序列；
2.若找到一个位置pos，nums[pos] > nums[pos-1],ok那么我们找到了这个递减子序列的开始位置pos，pos-1是一个小于它的位置，pos~len-1这个子序列是无法生成下一个序列了，由思路2，我们找到子序列中比nums[pos-1]大的最小的数，我们交换它，这样就生成了一个更大的排列，但是不是最小的最大，我们只需要再做一步，注意，我们交换过后pos~len-1还是递减的，我们只要反转它，那么他就变成递减的。这样就生成了最小的下一个更大的序列。

### 代码

```csharp
public class Solution {
    public void NextPermutation(int[] nums) {
        if(nums.Length <= 1) return ;
        int len = nums.Length;
        int pos = len -1;
        while(pos > 0 && nums[pos] <= nums[pos-1]) pos--;
        Array.Reverse(nums,pos,len-pos);
        if(pos == 0) return ;
        int t = pos - 1;
        for(;pos < len; pos ++) {
            if(nums[pos] > nums[t]) {
                var temp = nums[pos];
                nums[pos] = nums[t];
                nums[t] = temp;
                break;
            }
        }
    }
}
```