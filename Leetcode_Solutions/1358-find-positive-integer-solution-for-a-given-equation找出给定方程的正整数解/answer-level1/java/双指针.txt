双指针
```
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
        List<List<Integer>> ret = new ArrayList();
        for(int first = 1, second = 1000; first <= 1000; ) {
            if(customfunction.f(first, second) == z) {
                List<Integer> temp = new ArrayList();
                temp.add(first);
                temp.add(second);
                ret.add(temp);
                first ++;
            } else {
                if(second == 1) {
                    first ++;
                    second = 1000;
                    
                } else {
                    second --;
                }
            }
        }
        return ret;
    }
}
```
