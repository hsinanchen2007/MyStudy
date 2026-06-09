### 解题思路
判断奇偶数，步数+1，计算一次后如果还没归0则使用递归继续计算。

### 代码

```csharp
public class Solution {
    private int step_num = 0;
    public int NumberOfSteps (int num) {
        if(num%2==0)
            num = num/2;
        else
            num -=1;
        step_num++;
        if(num==0) return step_num;
        else {
            NumberOfSteps(num);
            return step_num;
        }
    }
}
```