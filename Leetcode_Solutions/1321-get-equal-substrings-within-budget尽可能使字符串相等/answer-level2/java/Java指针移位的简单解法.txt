
思路：
    1.题目可以转化为最长连续子数组且该子数组之和小于等于maxcost
    2.由于该数组都是正数，在每次找到最长子数组之后，指针相应的移动一位，比较出最大的长度即可
    3.注意长度和连续数组之和的计算即可
    4.在本次周赛的实际过程中，思路没有现在回顾写题解清晰，当时还是有点混乱，在计算长度和最大值的时候考虑不全面，当时最长连续子数组之和一度以为是dp，到最后时刻才完成这第二题
    这几周周赛发现写代码最重要的是思路一定要清晰，而且能够用代码写出自己思路很重要，这方面还需要提高，以此共勉。
```java
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int sum=0,len=0,max=0;
        int pointer=0;
        for (int i=0;i<s.length();i++) {
            int val = Math.abs(s.charAt(i)-t.charAt(i));
            sum+=val;
            len++;
            if (sum<=maxCost) {
                continue;
            }
            len--;
            max=Math.max(max,len);
            //计算新的连续数组之和
            sum=sum-Math.abs(s.charAt(pointer)-t.charAt(pointer));
            //指针移位
            pointer++;
        }

        return Math.max(max,len);
    }
}