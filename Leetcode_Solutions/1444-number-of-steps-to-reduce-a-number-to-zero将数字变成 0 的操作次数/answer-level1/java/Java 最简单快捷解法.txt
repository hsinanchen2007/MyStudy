class Solution {
    public int numberOfSteps (int num) {
        int step = 0;
        while(num >0){
        num = (num % 2 == 0) ? (num = num / 2) :  (num -= 1);
        step++;
        }
        return step;
    }
}![360截图20200213232204272.jpg](https://pic.leetcode-cn.com/52e36877c58281af07219ab3f5ca2efe4a61356249dba03dd30ec9d306a9776b-360%E6%88%AA%E5%9B%BE20200213232204272.jpg)
