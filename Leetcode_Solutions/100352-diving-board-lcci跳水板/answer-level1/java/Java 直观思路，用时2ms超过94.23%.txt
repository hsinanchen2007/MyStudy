### 解题思路
若k==0，则不能组成任何长度，返回空数组；
若两类板长度相同，k块板只能组成一个固定长度k * len；
当两类板长度不同时，短板数越多则总长就最短，依次排列即可。

### 代码

```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        if(k == 0) return new int[0];
        if(shorter == longer) 
            return new int[]{k * shorter};
        
        int[] res = new int[k+1];
        for(int i = 0; i < k + 1; i ++)
            res[i] = (k - i) * shorter + i * longer;
        return res;
    }
}
```