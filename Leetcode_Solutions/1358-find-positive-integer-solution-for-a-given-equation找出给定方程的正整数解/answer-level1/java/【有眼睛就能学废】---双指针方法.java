### 解题思路
使用前后两个指针
- 如果```customfunction.f(x, y) < z```的时候，移动数字小的指针；
- 如果```customfunction.f(x, y) > z```的时候，移动数字大的指针；
- 如果```customfunction.f(x, y) == z```的时候，记录结果。

### 代码

```java
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */
class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> solution = new LinkedList<List<Integer>>();
        int start = 1;
        int end = 1000;
        while(start <= 1000 && end >= 1) {
            int r = customfunction.f(start, end);
            if(r == z) {
                List<Integer> sub = new LinkedList<Integer>();
                sub.add(start);
                sub.add(end);
                solution.add(sub);
                start++;
                end--;
            } else if(r < z) {
                start++;
            } else {
                // r > z
                end--;
            }
        }
        return solution;
    }
}
```