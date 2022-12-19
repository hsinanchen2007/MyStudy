### 解题思路
1. 关键是要根据题目分析题意，挖掘规律。
2. 对于高个子的人来说，矮个子的人怎么排列都无所谓。所以应该先安排高个子的人按照k值大小入位。并且最高的人的k值是0,1,2,3,4...
3. 然后递归选后面次高的人，同样地方式插入。
4. 还有一个难点在于重写Arrays.sort方法中的Comparator<int[]>()方法。其中o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]表示，如果传入的h值相等，就按照k值升序排序。如果不相等，则按照h值逆序排序。

### 代码

```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                // if the heights are equal, compare k-values
                return o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0];
            }
        });

        List<int[]> res = new ArrayList<>();
        for(int[] p : people)
            res.add(p[1], p);
        
        return res.toArray(new int[people.length][2]);
    }
}
```