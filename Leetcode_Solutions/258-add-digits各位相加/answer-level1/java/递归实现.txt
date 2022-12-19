执行用时 : 3 ms , 在所有 Java 提交中击败了 90.12% 的用户 内存消耗 : 34.8 MB , 在所有 Java 提交中击败了 11.84% 的用户 
递归方法，题意挺明显的，下一轮的入参由上一轮结果输入
```
    public int addDigits(int num) {
        int temp = 0;
        while (num > 0) {
            temp += num % 10;
            num /= 10;
        }
        if (temp >= 10) {
            temp = addDigits(temp);
        }
        return temp;
    }
```
