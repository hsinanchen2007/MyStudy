```
public class Solution {
    public IList<int> GetRow(int rowIndex) {
        int[] res = new int[++rowIndex]; 
        for (int i = 0; i < rowIndex; i++) {
            res[i] = 1;
            for (int j = i - 1; j > 0; j--)
                res[j] += res[j - 1];
        }
        return res.ToList();
    }
}
```
