```
class Solution {
    public String addStrings(String num1, String num2) {
        // 用于拼接
        StringBuilder sb = new StringBuilder();
        // 进位处理
        int carry = 0;
        // 从低位往高位计算 最后反转
        for (int i = num1.length() - 1, j = num2.length() - 1;i >= 0 || j >= 0;i--,j--) {
            // 判断是否越界 越界就是0 不越界的话就取那个数
            int x = i >= 0 ? num1.charAt(i) - '0': 0;
            int y = j >= 0 ? num2.charAt(j) - '0': 0;
            // 求和
            int sum = x + y + carry;
            // 拼接
            sb.append(sum % 10);
            // 进位标志
            carry = sum / 10;

        }
        if (carry == 1) {
            sb.append("1");
        }
        // 反转
        return sb.reverse().toString();
    }
}
```
