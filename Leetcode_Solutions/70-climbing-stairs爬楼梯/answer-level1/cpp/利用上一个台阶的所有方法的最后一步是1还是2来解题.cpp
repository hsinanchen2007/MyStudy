![图片.png](https://pic.leetcode-cn.com/a3a0071947aed7f41618d96c9f1ad6d501db7703507d263969d2caeb7be8c144-%E5%9B%BE%E7%89%87.png)
如果待求台阶的上一个台阶的所有方法中，有x1种最后一步步数为1的方法，有y2种最后一步步数为2的方法，那么最后一步步数为1的方法接下来有两种可能到下个台阶，一种是将最后一步步数改为2，另一种是多走一步；最后一步步数为2的方法只有一种可能，那就是多走一步；这么分析下来，待求台阶一共有最后一步步数为1的方法数为x1+y1,最后一步步数为2的方法数为x1，那么总方法数为x1+y1+x1;
class Solution {
public:
    int climbStairs(int n) {
    int x1=1,y2=0;
    for(int i=1;i<n;i++)
    {
        int temp=x1;
        x1=x1+y2;
        y2=temp;
    }
    return x1+y2;
    }
};

