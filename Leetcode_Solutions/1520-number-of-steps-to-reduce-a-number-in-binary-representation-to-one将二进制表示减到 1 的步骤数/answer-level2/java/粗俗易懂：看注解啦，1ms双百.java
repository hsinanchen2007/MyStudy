```
class Solution {
    public static int numSteps(String s) {
        // 思路：用一个数组存放整个字符串的位，数组从左到右存放字符串的右到左的字符
        // 我们知道二进制除二相当于将数的二进制右移一位，
        // 那我们现在用指针从数组下标0开始，除的话就将指针向右边移一位，相当于除以2,
        // 如果遇到当前指针对应的数组值为1，就进行进位，从指针开始一直向右边找到第一个数组值为0的并置为1，期间一路上碰到为1的都置为0
        // 具体看代码，很清楚
        int len = s.length();
        int[] record = new int[len + 1];// 最后一位预留位，防止需要进位的情况，预留一个位置
        for (int i = 0; i < len; i++){ // 存放到数组，注意是从字符串的最右边向左存放到数组
            record[i] = s.charAt(len - i - 1) - '0';
        }

        int count = 0; // 记录运算的次数
        int k = 0; // 当前指针
        while (k < len){
            if (record[k] == 0){ // 为零，则直接进位
                k++;
            }else{// 为1
                if (k == len - 1) break; // 最后一位为1的就证明已经到最后了，可以结束
                int i = k+1; // 从当前指针的下一位开始进位
                record[k] = 0; // 将当前指针对应的为置为0
                while (i < len){
                    if (record[i] == 0){ // 找到第一个数组值为0的并置为1
                        record[i] = 1;
                        break;
                    }else {
                        record[i++] = 0; // 期间一路上碰到为1的都置为0
                    }
                }
            }
            count++;
        }

        return count;
    }

    // 思路一：先把s变成数字，然后再进行扣减, 会超时
    public static int numSteps1(String s) {
        int num = 0;
        int len = s.length();
        for (int i = len - 1; i >= 0; i--){
            if (s.charAt(i) == '1'){
                num += Math.pow(2, len - 1 - i);
            }
        }

        int count = 0;
        while (num != 1){
            if (num % 2 != 0){
                num++;
            }else{
                num = num / 2;
            }
            count++;
        }

        return count;
    }
}
```
