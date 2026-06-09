### 解题思路
@Marzii~ 感谢大神，这个题跟语言无关。
每一个数等于他的序号，最后一个数等于之前所有数和的负数就好了
例如 n=5，res = [0,1,2,3,-6]
### 代码

```csharp
public class Solution {
    public int[] SumZero(int n) {
        int[] res=new int[n];
        for(int i=0;i<n-1;i++){
            res[i]=i;
            res[n-1]-=i;
        }
        return res;
    }
}
```