![1580553942(1).jpg](https://pic.leetcode-cn.com/4493003464e99c3b066074f513cb1e2786223a3c2d5b751c635c4362d3dc776e-1580553942\(1\).jpg)
# 思路
思路其实大家基本都差不多，只不过很多人都选择了用栈。
我的方法就很朴素，没使用到栈。

逆序对：(A, B)且A > B，如：(5, 4)

**循环：**
从左到右找到第1对逆序对(A, B)：若找到，删除逆序对的A；若找不到，说明整体已经是升序排序的，直接从尾部截掉即可。
每次循环找逆序对的**起点**，会依赖于上次循环的**终点**。

# 代码(未优化版)
```java
//每次都从最左边开始找逆序对
class Solution {
    public String removeKdigits(String num, int k) {
        int ori_len = num.length();
        if (ori_len == k) return "0";
        StringBuilder sb = new StringBuilder(num);
        delete:
        while (k > 0) {
            int idx = 1;    //未优化部分
            boolean found = false;
            for (; idx < ori_len; ++idx) {
                if (sb.charAt(idx - 1) > sb.charAt(idx)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                sb.delete(ori_len - k, ori_len);
                break delete;
            }
            sb.deleteCharAt(idx - 1);
            --ori_len;
            --k;
        }
        while (--ori_len > -1 && sb.charAt(0) == '0')
            sb.deleteCharAt(0);
        return ori_len < 0 ? "0" : sb.toString();
    }
}
```

# 代码(优化版)
```java
//利用上次循环的终点作为下次循环的起点
class Solution {
    public String removeKdigits(String num, int k) {
        int ori_len = num.length();
        if (ori_len == k) return "0";
        StringBuilder sb = new StringBuilder(num);
        int idx = 1;    //优化部分
        delete:
        while (k > 0) {
            idx = Math.max(1, idx - 2); //优化部分
            boolean found = false;
            for (; idx < ori_len; ++idx) {
                if (sb.charAt(idx - 1) > sb.charAt(idx)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                sb.delete(ori_len - k, ori_len);
                break delete;
            }
            sb.deleteCharAt(idx - 1);
            --ori_len;
            --k;
        }
        while (--ori_len > -1 && sb.charAt(0) == '0')
            sb.deleteCharAt(0);
        return ori_len < 0 ? "0" : sb.toString();
    }
}
```
