### 解题思路
主要是理解题意，找出所有满足条件的整数对(x,y)，使得f(x,y)==z。由于函数f(x,y)是单调递增的，故可以使用双指针来找所有满足条件的整数对。函数递增，相当于序列有序。**双指针可以很好地利用有序性这一条件。**
定义双指针i、j，i从1开始扫描到1000，j从1000开始扫描到1(因为题目提到i、j范围都是1至1000)。若整数对大了，j--；小了则i++；等于z则表示双指针i、j指向的两个整数即满足条件的整数对。
时间复杂度：O(n)。n为x、y的定义域的区间长度。
空间复杂度：O(1)。

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
        List<List<Integer>> output=new LinkedList<List<Integer>>();
        int i=1,j=1000;
        while(i<=1000 && j>=1)
        {
            int cmp=customfunction.f(i,j)-z;
            if(cmp>0)       j--;
            else if(cmp<0)  i++;
            else
            {
                LinkedList<Integer> l=new LinkedList<Integer>();
                l.add(i);
                l.add(j);
                output.add(l);
                i++;
                j--;
            }
        }
        return output;
    }
}
```