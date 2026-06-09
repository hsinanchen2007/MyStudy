```
class Solution {
    public int[] closestDivisors(int num) {
        int sqrt = (int)Math.sqrt(num + 2);
        while(true){
            if((num + 1) % sqrt == 0){
                return new int[]{sqrt, (num + 1) / sqrt};
            } else if((num + 2) % sqrt == 0){
                return new int[]{sqrt, (num + 2) / sqrt};
            }
            sqrt--;
        }
    }
}
```