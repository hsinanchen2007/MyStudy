# 分糖果
今天打卡的时候，看到这个题目，第一个思路就是暴力求解。想了半天也没想出来更好的方法。看了一眼官方题解，瞄到了用数学公式求解的方法，然后我就在风中凌乱了...
所以，我毅然决然的还是用暴力求解（捂脸）。
我的代码写的不是很简洁，但是很好理解,而且运行时间是1~2ms，比官方题解的暴力求解运行时间要短，这里给像我一样的小菜鸟们提供一点思路叭。
```
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res=new int[num_people];
        for(int i=0;;i++)
        {
            //糖果分完了，跳出循环
            if(candies<=0)
            break;
            if(candies>=i+1)
            {
                //循环加
                res[i%num_people]+=i+1;
                candies-=(i+1);
            }
            //剩下的糖果不够满足要求的，也要全都分给他
            else
            {
                res[i%num_people]+=candies;
                candies=0;
            }
        }
        return res;
    }
}
```
