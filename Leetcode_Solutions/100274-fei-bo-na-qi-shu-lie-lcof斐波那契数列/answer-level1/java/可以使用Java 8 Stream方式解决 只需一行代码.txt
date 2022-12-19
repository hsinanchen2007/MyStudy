```
class Solution {
    public int fib(int n) {
        return Stream.iterate(new int[] {0, 1}, i -> new int[] {i[1], ((i[0] + i[1]) % 1000000007)})
                .map(ints -> ints[0])
                .limit(n+1)
                .skip(n)
                .findFirst().get() ;
    }
}
```
