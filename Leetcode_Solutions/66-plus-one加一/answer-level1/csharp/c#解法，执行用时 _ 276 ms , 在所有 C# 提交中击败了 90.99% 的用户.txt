### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] PlusOne(int[] digits) {
        int arrayLength = digits.Length;
        int[] tempArray;
        int cpFlag = 0;
        if(digits[arrayLength-1] !=9)
        {
            digits[arrayLength-1] = digits[arrayLength-1]+1;
        }
        else
        {
            if(digits[0]==9)
            {
                tempArray = digits;
                digits = new int[tempArray.Length+1];
                // 从第二个位置拷贝数组
                for(int i=1;i<digits.Length;i++)
                {
                    digits[i] = tempArray[i-1];
                }
            }
            cpFlag = 1;
            for(int i=digits.Length-1;cpFlag!=0;i--)
            {
                digits[i] = digits[i] + cpFlag;
                if(digits[i]==10)
                {
                    digits[i] = 0;
                    cpFlag = 1;
                }
                else cpFlag = 0;
            }
        }
        return digits;
    }
}
```