其实就是个约瑟夫问题
```java
class Solution {

    /**
    * 圆圈中剩下的最后一个数字，这是个约瑟夫环问题
    * 列举一种常规解法、一种数学解法
    **/
    public int lastRemaining(int n, int m) {
        /**
        * 1 常规解法====================================
        **/
        // 1 校验
        if (n == 0 || m == 0) {
            return -1;
        }
        // 2 把数据全部放到集合中
        List<Integer> list = new ArrayList<>(10);
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        // 3 第一次移动的时候肯定n还是完整的，直接求余(可能m > n，所以用求余)
        int c = (m - 1) % n;
        while (list.size() != 1) {
            list.remove(c);
            c = (c + m - 1) % list.size();
        }
        return list.get(0);
    }
        /**
        * 2 数学方法：(flag + m) % i
        **/
        /**
        int flag = 0;
        int flag = 0;
        for (int i = 2; i <= n; i++) {
            flag = (flag + m) % i;
            //动态规划的思想，将f(n,m)替换成flag存储
        }
        return flag;
        **/

}
```