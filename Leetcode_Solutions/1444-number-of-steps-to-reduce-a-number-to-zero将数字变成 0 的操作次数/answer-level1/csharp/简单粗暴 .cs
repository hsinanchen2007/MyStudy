### 解题思路
简单解法，按照题目描述进行循环遍历，记录次数，简单粗暴

### 代码

```csharp
public class Solution {
    public int NumberOfSteps (int num) {
        int count=0;
        while(num>0){
            count++;
            if(num%2==0)
            {
                num=num/2;
            }
            else
            {
                num=num-1;
            }
        }
        return count;
    }
}
```