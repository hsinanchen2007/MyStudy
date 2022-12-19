### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int NumberOfSteps (int num) {
        int step=0;
        while(num>0){
            if (num%2==0){
                num /= 2; 
            }
            else
            {   num = num - 1;              
            }
            step++;
        }
        return step;
    }
}
```