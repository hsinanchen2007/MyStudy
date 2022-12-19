
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/17
 *
 * 解题思路: 排序 -> 从小到大(i++)对孩子的胃口进行满足，不满足则增加饼干的尺寸(j++) 直到饼干分完或者全部孩子满足
 */
```
public int findContentChildren(int[] g, int[] s) {
    Arrays.sort(g);
    Arrays.sort(s);

    int j = 0;
    int i = 0;
    for(;i < g.length && j < s.length;j++){
        if(g[i] <= s[j]){
            i++;
        }
    }
    return i;
}

```