// ### 解题思路
// 数学的方法咋不懂，就直接暴力分🍬

// **初始化**
// xpy是小盆友，一共num_people个小盆友
// c是准备发的🍬，从1开始
// i是准备拿🍬的小朋友的编号，从0开始

// **循环发🍬，直到发完**
// 这里有2个小技巧：
// 1. 用i % num_people让编号不越界
// 2. 每轮都比较剩余🍬和准备拿的🍬，如果剩余的不够准备拿的，则把糖全部分给当前小盆友，分🍬结束

// **返回xpy**

// ### 代码

// ```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] xpy = new int[num_people];
        int c = 1;
        int i = 0;
        while(candies > 0) {
            xpy[i % num_people] += candies > c ? c : candies;
            candies -= c;
            c += 1;
            i += 1;
        }
        return xpy;
    }
}
// ```