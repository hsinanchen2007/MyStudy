### 解题思路
此处撰写解题思路

### 代码

```java
/*解题思路：如何判断这个数字（X）是否是好数。
(1)如果这个数字中含有3，4，7，那么一定不是好数。
(2)如果这个数字符合(1)，但每一位都没有2，5，6，9中的任何一个，它也不是好数。
解决方法：法1：将数字转化成字符串，每一位进行判别；方法2：递归调用
*/
class Solution {
    public int rotatedDigits(int N) {
        int count=0;
        for(int i=1;i<=N;i++)
        {
            if(IsGoodNum(i,false))  //初始值flag设为false，直到遇到一位是好数时改为true，若遇到0,1,8不变，遇到2,3,7,立即退出
                count++;
        }
        return count;
    }

    public boolean IsGoodNum(int n,boolean flag)
    {
        if(n==0)              //递归结束条件，判断到最后一位（由于是从后向前取数字，实际是第一位）
            return flag;
        //每一次递归需要做什么
        int d=n%10;
        if(d==3||d==4||d==7)  //一定不符合好数
            return false;
        if(d==0||d==8||d==1)
            return IsGoodNum(n/10,flag);  //是不是好数不知道，以观后效
        return IsGoodNum(n/10,true);
    }
}
```