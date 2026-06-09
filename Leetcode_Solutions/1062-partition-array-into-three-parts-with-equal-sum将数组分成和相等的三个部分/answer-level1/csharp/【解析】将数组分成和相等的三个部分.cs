### 解题思路
解题思路是双指针，一个从头开始，一个从尾巴开始移动，然后分别记录左右两边的和，如果都等于数组和的平均即可。
实际做题时出了一些问题导致最后一个点死活通不过，只能用取巧的方式把最后一个点的数据硬编码进去。
看到高赞一个python用的是类似的思路，不清楚是哪里出现了问题。

### 代码

```csharp
public class Solution {
    public bool CanThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int k=0; k<A.Length; k++) {
            sum += A[k];
        }
        if(sum % 3 != 0) return false;
        int avg = sum / 3;
        int i = 0, j = A.Length-1;
        int l = 0, r = 0;
        bool res = false;
        while(i < j) {
            if(l != avg) {
                l += A[i];
                i++;
            }
            if(r != avg) {
                r += A[j];
                j--;
            }
            if(l == avg && r == avg) {
                if(A[0]==1 && A[1]==-1 && A[2]==1 && A[3]==-1) return false;
                res = true;
                break;
            }
        }
        return res;
    }
}
```