暴力破解，思路简单，分别统计小时位数字和分钟位数字中1出现的次数，如果满足条件，则添加到列表中。
欢迎关注微信公众号:程序员之道，程序员员们一起讨论学习，架构师之路不再孤单！
```
public class Solution401 {
    /**
     * i代表小时位的数字，j代表分钟位的数字
     * @param num
     * @return
     */
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (countOf1(i) + countOf1(j) == num) {
                    result.add(String.format("%d:%02d", i, j));
                }
            }
        }
        return result;
    }

    /**
     * 统计数字n中1的个数
     * @param n
     * @return
     */
    private int countOf1(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n-1);
        }
        return count;
    }

    public static void main(String[] args) {
        int n = 1;
        System.out.println(new Solution401().readBinaryWatch(n));
    }
}
```
