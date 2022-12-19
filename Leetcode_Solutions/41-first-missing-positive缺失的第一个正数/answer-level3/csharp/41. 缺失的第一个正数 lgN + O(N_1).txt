### 解题思路
首先负数与0不考虑
我们直接二分找到第一个大于0的数，lgN排除掉负数以及0
之后就简单了，如果剩下n个元素那么答案只可能是1~n中的数字
我们拿个变量从1开始一一比对就可以了。
如z=1;
如果z < nums return z;
如果并且与数组之前的值与这个值不同或者是第一个值并且与z相同 z++
如果在比对过程没有找出解，则剩下的数是从1开始连续的则返回z+1

### 代码

```csharp
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        Array.Sort(nums);
        int len = nums.Length;
        if(len == 0) return 1;
        int start = 0;
        if(nums[0] < 0) { // 有负数
            int l = 0;
            int r = len;
            while(l < r) { //找到第一个大于0的数
                int mid = (l + r) >> 1;
                if(nums[mid] >= 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            if(r == len )return 1;
            else{
                start = r;
            }
        } 
        int z = 1;
        for(int i = start; i < len ; i ++ ){
             if(nums[i]==0) continue;
             if(z < nums[i])return z;
             else if((z == nums[i] && i ==0) || (i > 0 && nums[i] != nums[i-1])) z++;
             }
         return nums[len-1]+1;
        
    }
}
```