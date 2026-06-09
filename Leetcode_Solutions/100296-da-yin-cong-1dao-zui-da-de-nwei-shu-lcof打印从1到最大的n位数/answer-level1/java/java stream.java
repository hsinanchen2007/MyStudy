
java stream
```
class Solution {
    public int[] printNumbers(int n) {
        if(n<1) return new int[1];
        return IntStream.rangeClosed(1,(int)Math.pow(10,n)-1).toArray();
    }
}
```
