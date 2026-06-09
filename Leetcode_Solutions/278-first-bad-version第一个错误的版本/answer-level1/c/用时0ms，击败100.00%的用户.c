### 解题思路
由题意可以看出本题与普通的有序二分查值不同的是需要找的是前后值不同的位置，因此在二分查找的基础上，只需添加两个临时变量存储，比较临时变量是否相邻可得出结果。需要注意的是，提交测试时左右值之和有超出int范围的情况存在，因此需要使用范围更大的类型定义。

### 代码

```c
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 1)
        return 1;
    long left = 1, right = n, mid, Lflag = -1, Rflag = -1;
    int answer;
    while(left < right)
    {
        //二分查找，正确版本与错误版本用临时变量存储
        mid = (left+right)/2;
        if(!isBadVersion(mid))
        {
            Lflag = mid;
            left = mid+1;
        }
        else
        {
            Rflag = mid;
            right = mid-1;
        }
        //比较错误版本与正确版本是否相邻，是则找到第一个错误版本，返回版本值，退出循环
        if(Lflag == (Rflag-1))
        {
            answer = Rflag;
            break;
        }
    }
    return answer;
}
```