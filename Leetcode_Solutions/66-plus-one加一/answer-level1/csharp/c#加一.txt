### 解题思路
暴力求解

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