### 解题思路
![擷取.PNG](https://pic.leetcode-cn.com/26ccdf411ffdd45514af6840d6071643a73d4af298188ad315ac1d4b59966bd6-%E6%93%B7%E5%8F%96.PNG)


### 代码

```csharp
public class Solution {
    public bool CanThreePartsEqualSum(int[] A) {    
            int ACount = 0;
            for (int i = 0; i < A.Length; i++)
            {
                ACount += A[i];
            }

            int times = 0;
            int ASecount = 0;           
            for (int i = 0; i < A.Length && times < 3; i++)
            {
                ASecount += A[i];               

                if (ASecount == ACount / 3)
                {                  
                    ASecount = 0;                  
                    times++;
                }
            }

            if (times == 3)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}
```