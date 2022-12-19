```java
class Solution {
    // 记录满足条件的结果
    private ArrayList<Integer> list;
    // 保存N和K两个变量
    private int N;
    private int K;
    public int[] numsSameConsecDiff(int N, int K) {
        // 由于不能有前导0，所以对于N等于1的情况，直接返回
        if (N == 1)
            return new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        list = new ArrayList<>();
        this.N = N;
        this.K = K;
        // 从1到9，逐个尝试
        for (int i = 1; i <= 9; i++)
            helper(i, i, 1);
        // 将结果转为int[]，当然这里也可以采用Java 8 流的方式：
        int[] result = new int[list.size()];
        int index = 0;
        for (Integer num : list)
            result[index++] = num;
        return result;
        // 上述转换可以替换为Java 8流处理：
        // return list.stream().mapToInt(Integer::valueOf).toArray();
    }
    /**
    * 辅助函数，cur：当前值；units：当前值的个位值，count：当前位数
    * 比如对于181，cur=181，units=1（个位），count=3（3位数）
    */
    private void helper(int cur, int units, int count) {
        // 如果达到题目要求的位数，则加入结果集，返回
        if (count == N) {
            list.add(cur);
            return;
        }
        // 分别计算当前个位加/减K的结果
        int temp1 = units + K;
        int temp2 = units - K;
        // 如果该值满足条件，则当前值往左累加，并将该值放在个位，同时位数count加1。
        // 递归该函数
        if (temp1 >= 0 && temp1 <= 9) {
            helper(cur * 10 + temp1, temp1, count + 1);
        }
        // 同上，只不过这里针对K=0的情况多一个判断，temp1要和temp2不等，不然就会有相同的值保存两次
        // 当然这里也可以判断K不为0
        if (temp2 != temp1 && temp2 >= 0 && temp2 <= 9) {
            helper(cur * 10 + temp2, temp2, count + 1);
        }
    }
}
```
