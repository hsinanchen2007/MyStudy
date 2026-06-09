### 解题思路
此处撰写解题思路
1. 思路是递归
2. 后面的数是前边的数的描述
3. 因此定义递归函数参数值是n-1
4. 描述一个数k的方法就是普通的遍历这个字符串，每个字符做一个统计
### 代码

```java
class Solution {
    // 思路是递归
    // 后面的数是前边的数的描述
    // 因此定义递归函数参数值是n-1
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return say(countAndSay(n - 1));
    }

    // 如何描述一个数k
    private String say(String s) {
        // 记录某个数值出现的次数
        int count = 1;
        // 当前的数值，从0开始
        // 第0个数必然有count = 1
        char num = s.charAt(0);
        StringBuilder sb = new StringBuilder();
        // 从1开始循环
        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            // 如果这个数和前边的数是同一个
            if (c == num) {
                count++;
            } else {
                // 如果不是同一个数
                // 则记录上一个数的个数
                sb.append(count);
                sb.append(num);
                // 重新初始化字符
                num = c;
                count = 1;
            }
        }
        // 将最后的结尾统计进去
        sb.append(count);
        sb.append(num);
        // 返回描述字符串
        return sb.toString();
    }
}
```