```
public class Solution {
    public int SumNums(int n) {
        return (int)Math.Floor(Math.Pow(10, Math.Log10(n) + Math.Log10(n + 1)) + 0.00001) >> 1;
    }
}
```
