### 解题思路
写完后和大部分人的思路大同小异或者几乎一样，因为一个孩子只能吃一块，而且要满足，所以优先满足孩子的胃口再说。
先排序再分。

### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        //下将两个数组进行排序
        Arrays.sort(g);
        Arrays.sort(s);

        int count = 0;
        for (int i = 0;count<g.length && i<s.length;i++){
            if (s[i]>=g[count]){
                count++;
            }
        }
        return count;
    }
}
```