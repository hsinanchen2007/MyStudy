思路：
    1. 记录数组array：1,4,9,16........lastValue ;其中lastValue < n;
    2. 倒着对数组进行深度遍历；找到累加和==n的层次数目；
    3. 增加过滤条件：如果当前层次已经大于“之前已知的有效层次数”，就return;
```
void Travers(int *flag, int id, int target, int sum, int level, int *ret)
{
    // 过滤条件：假设当前id满足条件，那么实际层次为level + 1。
    // 如果level + 1 > 之前的有效层次数目，就不需要再往下遍历了。
    if (level + 1 >= *ret) {
        return;
    }
    for (; id > 0; id--) {
        if (sum + flag[id] > target) {
            continue;
        } else if (sum + flag[id] == target) {  // 满足条件后更新ret
            if (level + 1 < *ret) {
                *ret = level + 1;
            }
            return;
        } else {
            Travers(flag, id, target, sum + flag[id], level + 1, ret);
        }
    }

    return;
}


int numSquares(int n){
     int flag[1000]  = {0};
     int i = 1;
     //初始化数组arry，记录n之前的幂次列表；
     for (i = 1; i <= n; i++) {
          int val = pow(i, 2);
          if (val < n) {
              flag[i] = val;
          } else if (val == n) {
              return 1;
          } else {
              break;
          }
     }
    int ret = INT_MAX;
    //进行深度遍历，找到最小层次数目。
    Travers(flag, i - 1, n, 0, 0, &ret);
    return ret;
}
```
