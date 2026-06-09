### 解题思路
从题目中可知```1 <= x, y <= 1000```，所以我们可以使用一个嵌套循环，对x,y从1开始尝试求解，当某个x，y经过```customfunction.f(x,y)```函数计算的结果等于z时，这个x，y就是我们要的其中一个解。
复杂度分析：
- 时间复杂度：O(XY)
- 空间复杂度：O(N), N为解的个数

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
        for (int x = 1; x <= 1000; x++) {
            for (int y = 1; y <= 1000; y++) {
                int r = customfunction.f(x,y);
                if (r == z) {
                    List<Integer> subSolution = new LinkedList<Integer>();
                    subSolution.add(x);
                    subSolution.add(y);
                    solution.add(subSolution);
                }
            }
        }
        return solution;
    }
}
```