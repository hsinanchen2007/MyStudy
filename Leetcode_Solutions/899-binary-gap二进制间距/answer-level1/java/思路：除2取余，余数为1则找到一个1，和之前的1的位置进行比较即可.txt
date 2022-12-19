![image.png](https://pic.leetcode-cn.com/5399c5387cd77e48cb67cd0dd865f89100de57f4cab00b5a66eee5a9451dee0b-image.png)
class Solution {
    public int binaryGap(int N) {
        int maxLen=0;//初始距离
        //把第一个1和第二个1的位置相同都置位0
        int start=0;
        int end=start;
        //先找到第一个1
        while (N/2!=0){
            if (N%2==1)
                break;
            N=N/2;
        }
        //得数小于等于0，
        while(N/2>0){
            N=N/2;
            end++;
            if(N%2==1){
                //有新的1出现,判断距离是否比原来的大，重置把新的1位置传给start
                if (end-start>maxLen)
                    maxLen=end-start;
                //重置start的位置
                start=end;
            }
        }
        return maxLen;
    }
}