### 解题思路
由题意容易得出完整梯形硬币数与行数之间的关系，行数为偶时：CoinNum = (1+row)*row/2;行数为奇时：CoinNum = (2+row)*(row/2)+1;则使用二分查找存在两种情况，其一为目标硬币数刚好构成完整硬币梯形，即CoinNum与n相等；其二是目标硬币数构成完整硬币梯形后有余数，即n>CoinNum;第一种情况直接判断，第二种情况则使用两个临时变量存储行数，并判断它们是否相邻，至此问题解决。(此题中可以使用等差公式计算硬币数，即CoinNum=row+row*(row-1)/2,但是测试时发现运行时间需要4ms)

### 代码

```c
int arrangeCoins(int n){
    long left = 1, right = n, mid, CoinNum;
    int rowNum, Lflag = -1, Rflag = -1;
    while(left <= right)
    {
        mid = (left+right)/2;
        //判断行数奇偶性，计算硬币数
        if(mid%2 == 0)
            CoinNum = (1+mid)*mid/2;
        else
            CoinNum = (2+mid)*(mid/2)+1;
        //二分法查找，若硬币数与目标值相同循环退出，否则标记当前的行
        if(CoinNum < n)
        {
            Lflag = mid;
            left = mid +1;
        }
        else if(CoinNum > n)
        {
            Rflag = mid;
            right = mid -1;
        }
        else
        {
            rowNum = mid;
            break;
        }
        //比较行变量是否相邻，相邻则找到完整总行数，循环退出
        if((Lflag + 1) == Rflag)
        {
            rowNum = Lflag;
            break;
        }
    }
    return rowNum;
}
```