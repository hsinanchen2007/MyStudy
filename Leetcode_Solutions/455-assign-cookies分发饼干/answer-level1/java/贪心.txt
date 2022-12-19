### 解题思路
此处撰写解题思路
先将两个数组排序，从头到尾，从小到大依次比较，胃口较小的孩子吃的饼干最好是饼干中能够满足他的最小的饼干，这样依次向后查找，找到的饼干一定在后面没有出现过的位置。

### 代码

```java

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int i=0,j=0;
        while(i<g.length&&j<s.length){
            if(g[i]<=s[j]) i++;
            j++;
        }
        return i;
           
    }
}
```