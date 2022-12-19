### 解题思路
一开始使用暴力法，找到第一次下降的序号，效率略低
参考官方题解了解到了二分法
### 代码

```csharp
public class Solution {
    public int PeakIndexInMountainArray(int[] A) {
        int left=0,right=A.Length-1,m=0;
        while(left<right){
            m = (left+right)/2;
            if(A[m]<A[m+1]){
                left=m+1;
            }else{
                right=m;
            }
        }
        return left;
    }
}
```