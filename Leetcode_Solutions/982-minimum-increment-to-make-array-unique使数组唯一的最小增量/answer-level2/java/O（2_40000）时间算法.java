### 解题思路
每次都只保留一个高度为i的元素，将剩余的重复元素均拔高至i+1高度。
用high[i]表示高度为i的元素个数。
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[]high=new int[80001];
        for(int i=0;i<A.length;i++)
        {
            high[A[i]]++;
        }
        int ans=0;
        for(int i=0;i<high.length;i++)
        {
            if(high[i]==0||high[i]==1)
            continue;
            else
            {
                ans+=high[i]-1;
                high[i+1]+=high[i]-1;
            }
        }
        return ans;
    }
}
```