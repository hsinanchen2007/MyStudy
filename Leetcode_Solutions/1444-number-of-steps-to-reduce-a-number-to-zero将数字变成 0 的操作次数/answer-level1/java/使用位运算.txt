利用位运算，如果 num是奇数的话，低位肯定是 1，否则是 0
判断是不是奇数可以用与 1做 &操作是否为 0来判断
除 2的操作可以用右移一位代替
减 1的操作可以用与 0xfffffffe做 &操作得到（在这个题目里面减一就相当于把低位的 1变成 0）

class Solution {
    public int numberOfSteps (int num) {
        int count = 0;
        while (num != 0){
            num = ((num & 1) == 0)?(num >> 1):(num & 0xfffffffe);
            count++;
        }
        return count;
    }
}