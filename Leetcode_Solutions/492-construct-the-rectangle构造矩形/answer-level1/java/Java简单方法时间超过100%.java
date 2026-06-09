本题中是针对一个固定的数字，利用贪心的思想，如果要把数字转变成两个相差最小的，必然先想到要使用sqrt方法去开方，例如sqrt(4)是2*2，sqrt(9)是3*3.这里如果数字不难直接开出整数的平方，我们可以把它化为最近的整数并依次进行尝试，第一个尝试出的数字便是两个数差值的最小。
例如： area=10；
sqrt（10）=3.几
所有我们取3，并把10对3取余如果能整除代表一组数字中的是需要3的，如果不是，则3自减。
显然需要自减，所以变成了2，因为10对2刚好能取余，所以答案就是2和5.
```
class Solution {
    public int[] constructRectangle(int area) {
        int sqrt=(int)Math.sqrt(area);//开根号
        while(area%sqrt!=0){//找到小于sqrt最大的一个整数
            --sqrt;
        }
        return new int[]{area/sqrt,sqrt};
    }
}
```
