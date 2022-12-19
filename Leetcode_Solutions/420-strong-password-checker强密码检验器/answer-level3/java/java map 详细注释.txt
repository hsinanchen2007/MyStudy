### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int strongPasswordChecker(String s) {
        int upper = 1;
        int lower = 1;
        int digit = 1;
        int n = s.length();
        Map<Integer, Integer> m = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; ) {
            // 统计缺少的大小写或者数字的数量
            if (Character.isLowerCase(s.charAt(i))) lower = 0;
            if (Character.isUpperCase(s.charAt(i))) upper = 0;
            if (Character.isDigit(s.charAt(i))) digit = 0;
            int j = i;
            // 记录在该位置上存在多少个一样的字符
            while (i < n && s.charAt(j) == s.charAt(i)) i ++;
            int length = i - j;
            if (length >= 3) m.put(j, i - j);
        }
        // 缺少的大小写或者数字的数量
        int miss = lower + upper + digit;
        int res = 0;
        if (n < 6) {
            int diff = 6 - n;
            // 当n < 6 返回和6之间的差值以及缺少的数量当中最大的值
            res = Math.max(diff, miss);
        } else {
            // over 是超出20部分的数量
            int over = Math.max(n - 20, 0);
            res += over;
            // 以下这个for循环的目的是让所有超过3的连续数字的大小是3 的倍数 + 2
            for (int k = 1; k < 3; k ++) {
                for (int p : m.keySet()) {
                    if (m.get(p) >= 3 && m.get(p) % 3 == k - 1 && over > 0) {
                        m.put(p, m.get(p) - Math.min(k, over));
                        over -= k;
                    }
                }
            }
            // 如果此时over还是大于0， 大于3的连续数列减到2为止
            for (int p : m.keySet()) {
                if (m.get(p) >= 3 && over > 0) {
                    int need = m.get(p) - 2;
                    m.put(p, m.get(p) - over);
                    over -= need;
                }
            }
            int left = 0;
            // 连续数列的长度 / 3 就是需要替换操作的步数
            for (int p : m.keySet()) {
                if (m.get(p) >= 3) {
                    left += m.get(p) / 3;
                }
            }
            res += Math.max(left, miss);
        }
        return res;
    }
}
```