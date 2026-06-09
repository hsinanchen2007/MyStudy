- 利用等差数列前n项和公式计算出n+1项的和
- 遍历一遍arr数组，用和减去每一项的结果即为所求

```
class Solution {
    public int missingNumber(int[] nums) {
        int sum = nums.length * (nums.length+1) / 2;//注意： 这里的项数是len+1
        for(int n : nums){
            sum -= n;
        }
        return sum;
    }
}
```
