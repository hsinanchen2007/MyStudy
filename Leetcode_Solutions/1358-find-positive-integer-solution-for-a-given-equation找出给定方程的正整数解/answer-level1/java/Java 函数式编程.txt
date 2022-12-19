本来这道题的标签是使用二分查找，根据题目描述，发现传入的第一个参数是一个接口，准确的说，是一个匿名类。而匿名类，则是函数式编程的基础。因此，这道题可以使用函数式编程的思想来做。由于CustomFunction接口返回的是一个增函数，因此，当迭代计算出的值小于z的时候，继续迭代，若大于z，则跳出当前迭代，开始下一次迭代过程。暴力过程参见代码：
```
class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> lists = new LinkedList<>();
        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; j++) {
                int value = customfunction.f(i, j);
                if (value == z) {
                    List<Integer> list = new LinkedList<>();
                    list.add(i);
                    list.add(j);
                    lists.add(list);
                } else if (value < z) {
                    continue;
                } else {
                    break;
                }
            }
        }
        return lists;
    }
}
```