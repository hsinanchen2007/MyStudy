class Solution {
    public int addDigits(int num) {
        // 如果下一个数只有一位，则返回
        if (nextNum(num) < 10) {
            return nextNum(num);
        }
        // 如果下一个数不止一位，递归调用
        return addDigits(nextNum(num));
    }

    /**
     * 计算下一个数是多少的方法
     * @param input 输入数字
     * @return 下一个数字
     */
    private int nextNum(int input) {
        int num = input;
        int nextNum = 0;
        while (num / 10 > 0) {
            nextNum += num % 10;
            num = num / 10;
        }
        nextNum += num;
        return nextNum;
    }
}