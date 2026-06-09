### 解题思路
1. 刚开始没有思路，沉下心来，仔细分析，发现二叉搜索树的特点是根节点的左侧都小于根节点，右侧相反。
2. 因此考虑使用递归的方法来做，分解成子问题。
3. 然后通过写了几个例子，发现对称性，如n=5时，以1,2,3,4,5为根节点的数量为numTrees(4), numTrees(3),numTrees(2)*numTrees(2), numTrees(3), numTrees(4)。可以发现规律，当根节点两边都大于1时，以当前节点为根节点的树数为两边点的乘积，否则，为较大一侧的numTrees。
4. 纯递归速度较慢，因为有重复计算，所以在基础上加map备忘录剪枝即可。

### 代码

```java
class Solution {
    Map<Integer, Integer> map = new HashMap<>();
    public int numTrees(int n) {
        if(n < 3) return n;
        if(map.containsKey(n)) return map.get(n);
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(2 * i > n + 1){
                if(n - i > 1) res += (numTrees(i-1) * numTrees(n-i));
                else res += numTrees(i-1);
            }
            else{
                if(i - 1 > 1) res += (numTrees(i-1) * numTrees(n-i));
                else res += numTrees(n-i);
            }
        }
        map.put(n, res);
        return res; 
    }
}
```