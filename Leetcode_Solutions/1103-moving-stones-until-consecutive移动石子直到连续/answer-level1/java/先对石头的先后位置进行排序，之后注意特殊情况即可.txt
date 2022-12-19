首先，将石头的位置存入数组num[3]中。想要获得最大的移动次数，每个后面的石子向前每次移动一步即可。
从而：   max = (num[1]-num[0]-1) + (num[2]-num[1]-1) 
==> max = num[2] - num[0] - 2;

接下来考虑最小移动步数中的特殊情况：
1. 当三个石子一开始就是挨着的时候，次数为0；
2. 当仅有两个石子挨着的时候，次数为1；
3. 当仅有两个石子的间距为1的时候，次数为1；
4. 其余情况次数为2。

代码如下：
```
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] num = new int[] {a,b,c};
        Arrays.sort(num);
        int[] res = new int[2];
        res[1] = num[2] - num[0] - 2;
        if(num[1] - num[0] == 1 && num[2] - num[1] == 1)
            res[0] = 0;
        else if((num[1] - num[0] == 2) || (num[1] - num[0] == 1 && num[2] - num[1] > 1) || (num[2] - num[1] == 2) || (num[1] - num[0] != 1 && num[2] - num[1] == 1))
            res[0] = 1;
        else res[0] = 2;
        return res;
    }
}
```
