### 解题思路
第一次和 确定 缺失的两个数的和
第二次 确定 缺失的第一个数

### 代码

```csharp
class MisNum{
    public int[] MissingTwo(int[] nums) {
        var maxN = nums.Length + 2;
        var maxSum = (1 + maxN) * maxN / 2;
        var sumV = 0;
        foreach(var n in nums){
            sumV += n;
        }
        var delta = maxSum - sumV;
        //delta = A+B
        //1~half half+1 ~ maxN
        var halfMin = delta / 2;
        var sumHalf = 0;
        var maxHalfV = (1 + halfMin) * halfMin / 2;
        foreach(var n in nums){
            if(n <= halfMin) sumHalf += n;
        }
        var v1 = maxHalfV - sumHalf;
        var v2 = delta - v1;
        return new int[] { v1, v2 };
    }
}

public class Solution {
    public int[] MissingTwo(int[] nums) {
        var mn = new MisNum();
        return mn.MissingTwo(nums);
    }
}
```