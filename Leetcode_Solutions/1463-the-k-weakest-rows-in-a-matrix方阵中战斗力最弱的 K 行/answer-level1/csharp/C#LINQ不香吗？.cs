```
   public int[] KWeakestRows(int[][] mat, int k)
    {
        var p = from arr in mat
                let index = Array.IndexOf(mat, arr)
                orderby arr.Count(item => item == 1), index
                select index
                ;

        return p.Take(k).ToArray();
    }
```
