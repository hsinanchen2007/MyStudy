```
class Solution {
    public int myAtoi(String str) {
        char[] arr = str.toCharArray();
        if (arr.length == 0) return 0;
        int start = 0;
        // 去除头部空格
        for (int i=0; i<arr.length; i++) {
            if (arr[i] != ' ') {
                start = i;
                break;
            } 
        }
        boolean flag = true;
        // 判断是否有符号，用flag表示符号，true表示正，false表示负;
        if (arr[start] == '+' || arr[start] == '-') {
             flag = (arr[start]=='-') ? false : true;
             start++;
        }
        long sum = 0;
        // 计算数字，都用正数计算，用long控制溢出;
        for (int i=start; i<arr.length; i++) {
            if (arr[i]-'0'<0 || arr[i]-'0'>9) {
                break;
            }
            int temp = arr[i]-'0';
            sum = (sum*10 + (long)temp);
            // 如果是负数，那么定义溢出上限
            if (flag == false && sum > (long)(Integer.MAX_VALUE)+1) {
                sum = (long)(Integer.MAX_VALUE)+1;
                break;
            }
            // 如果是正数，那么定义溢出上限
            if (flag == true && sum > (long)Integer.MAX_VALUE) {
                sum = (long)Integer.MAX_VALUE;
                break;
            }
        }
        // 给输出结果加符号
        if (flag) {
            return (int)sum;
        } else {
            return (int)(-sum);
        }
    }
}
```
