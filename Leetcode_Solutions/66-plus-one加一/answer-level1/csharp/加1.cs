### 解题思路
执行用时 :264 ms, 在所有 C# 提交中击败了98.37% 的用户
内存消耗 :29.9 MB, 在所有 C# 提交中击败了5.88%的用户

### 代码

```csharp
public class Solution {
    public int[] PlusOne(int[] digits) {
        int n=digits.Length;
            for(int i=n-1;i>=0;i--){
                if(digits[i]!=9){
                    digits[i]++;
                    return digits;
                }
                else 
                {
                    digits[i]=0;
                }
            }
            digits = new int[n+1];
            digits[0]=1;
            return digits;
    }
}
```