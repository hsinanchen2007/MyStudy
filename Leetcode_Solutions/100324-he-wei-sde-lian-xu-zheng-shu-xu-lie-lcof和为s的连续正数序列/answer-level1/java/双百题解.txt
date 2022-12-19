
思路：获得数组左边界和长度，利用数学的求和公式就可以了

    1. 由于target = (start,...,target/n,...,start + n), 其中target/n 时要么在中间，要么是在中间偏左的那个数，如果在中间start = target/n - n/2，如果是中间偏左的那个数则start = target/n - n/2 + 1。
    2. 得到 start 和 n则利用求和公式:sum = n*start + n*(n-1)/2，如果sum与target相等则此区间成立
    3. 终止条件为：左边界start到达1或比1还小

```java []
public int[][] findContinuousSequence(int target) {
        List<int[]> result = new ArrayList<>();
        int num = 2;

        int start;  //左边界
        do {

            int tmp = target / num;
            start = (num & 1) == 0 ? tmp - (num / 2 - 1) : tmp - (num / 2); //除数为偶数是左边界向右一位，为奇数时不变

            int sum = num * start + (num * (num - 1)) / 2;  //求和的值

            if (sum == target) {
                int[] ints = new int[num];
                for (int i = 0; i < num; i++) {
                    ints[i] = start + i;
                }
                result.add(ints);
            }

            num++;
        } while (start > 1);    //左边界一旦小于等于1结束

        Collections.reverse(result);

        return result.toArray(new int[0][]);
    }
```
