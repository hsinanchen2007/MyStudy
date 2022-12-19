### 解题思路
### 代码

```java
class Solution {
    public int numTrees(int n) {
        //G(n)表示长度为n的序列种数
        // F(i,n)=G(i-1)*G(n-i)表示以i为根的长度为n的序列种数
        // G(n)=求和(F(i,n))
        int[] G=new int[n+1];
        G[0]=1;
        G[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                G[i]+=G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
}
```