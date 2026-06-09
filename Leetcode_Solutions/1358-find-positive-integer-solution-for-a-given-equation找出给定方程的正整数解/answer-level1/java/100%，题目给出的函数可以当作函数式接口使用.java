### 解题思路
双指针，思路清晰
本地测试可以使用 BiFunction<Integer, Integer, Integer> function = (x, y) -> x + y; 
模拟 + ， * 类似。 当然BinaryOperator extends BiFunction 同样可以
附上本地测试代码
` BiFunction<Integer, Integer, Integer> function = (x, y) -> x + y;`
` System.out.println(findSolution(function, 5));`
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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        
		int x = 1, y = z;
		while (x <= z && y > 0) {
			int m, n;
			int trs = customfunction.f((m = x), (n = y));
			if (trs == z) {
                // 恰好相等则添加到结果集
				res.add(new ArrayList<Integer>() {{add(m); add(n);}});
				++ x;
				-- y;
			} else if (trs > z)
				-- y;
			else ++ x;
		}
		return res;
    }
}
```