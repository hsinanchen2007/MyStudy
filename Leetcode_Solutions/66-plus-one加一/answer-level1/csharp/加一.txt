### 解题思路
执行用时 :268 ms, 在所有 C# 提交中击败了95.12% 的用户
内存消耗 :30.2 MB, 在所有 C# 提交中击败了5.88%的用户

### 代码

```csharp
public class Solution {
    public int[] PlusOne(int[] digits) {
            int i;
            for(i=digits.Length-1;i>=0;i--){
                if(digits[i]!=9){
                    digits[i]++;
                    return digits;
                }
                else {
                    digits[i]=0;
                }
            }
            int[] digits2 = new int[digits.Length+1];
            for( i=0;i<digits2.Length;i++){
                if(i==0){
                    digits2[i]=1;
                }else{
                    digits2[i]=0;
                }
            }
            return digits2;
    }
}
```