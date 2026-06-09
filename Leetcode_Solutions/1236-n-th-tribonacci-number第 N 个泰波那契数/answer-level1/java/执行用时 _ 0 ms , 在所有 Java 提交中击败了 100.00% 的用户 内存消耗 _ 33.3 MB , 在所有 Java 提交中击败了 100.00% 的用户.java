```
public class Solution {
    public int tribonacci(int n) {
        int prev = 0;
        int curr = 1;
        int next = 1;
        while(n-- > 0){
            next = next + curr + prev;
            curr = next - curr - prev;
            prev = next -prev - curr;
        }
        return prev;
    }
}
```
