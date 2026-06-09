### 执行用时：1ms，内存消耗：33.6MB
由于强整数为x^i + y^j的和，并且小于等于bound，因此x^i和y^j的大小都必须在闭区间[0,bound-1]内。通过循环求出在给定bound下i、j的最大值cnta和cntb，同时在求解的过程中，把x^i(i >= 0 && i <= cnta)的所有值记录在哈希表中，哈希表下标为i，值为x^i；对y也采取同样的操作，记录y^j(j >= 0 && j <= cntb)的所有值在另一个哈希表中。这样可以免去接下来的双重for循环中的重复计算。
然后是双重for循环，对于所有在区间[0,bound-1]内的x^i，遍历所有在区间[0,bound-1]内的y^j，只要两者的和sum小于等于bound且sum未在list中出现过则将其添加进list。cnta、cntb的作用就是将x^i和y^j的大小限制在[0,bound-1]内。

时间复杂度：O(n^2)。共循环cnta*cntb次，cnta=logx(bound)，cntb=logy(bound)。
空间复杂度：O(1)。哈希表大小为常数。

### 代码

```java
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        int a = 1, b = 1;
        int[] hasha = new int[32];
        int[] hashb = new int[32];
        int cnta = 0, cntb = 0;
        if(x == 1)  hasha[cnta++] = 1;
        else
            while(a < bound)
            {
                hasha[cnta++] = a;
                a *= x;
            }
        if(y == 1)  hashb[cntb++] = 1;
        else
            while(b < bound)
            {
                hashb[cntb++] = b;
                b *= y;
            }
        
        List<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < cnta; i++)
        {
            if(hasha[i] >= bound) break;
            for(int j = 0; j < cntb; j++)
            {
                int sum = hasha[i] + hashb[j];
                if(sum <= bound && !list.contains(sum))    
                    list.add(sum);
                else if(sum > bound)    break;
            }
        }
        return list;
    }
}
```