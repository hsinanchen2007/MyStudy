### 解题思路
每一列从上到下遍历，遇0就就加入set，满k个就结束，当然最后一列肯定存在相同的情况，看看哪些还没加进去，从小到大再补进去就可以了

### 代码

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) 
    {
        Set<Integer>set = new LinkedHashSet<>();
        int [] res = new int[k];
        for(int j=0;j<mat[0].length;j++)
        {
            for(int i=0;i<mat.length;i++)
            {
                if(mat[i][j]==0)
                    set.add(i);
            }
            if(set.size()>=k)
                break;
        }
        for(int i=0;i<mat.length;i++)
        {
            if(!set.contains(i))
             set.add(i);
        }
        int num= 0;
        for(int i:set)
        {
            res[num]=i;
            num++;
            if(num==k)
                break;
        }
        return res;
    }
}
```