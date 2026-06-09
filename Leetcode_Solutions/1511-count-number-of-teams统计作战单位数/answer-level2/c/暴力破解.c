![image.png](https://pic.leetcode-cn.com/12ed50f05e9bf7de26ef47cff397a33930bb1368ccff8af9be64b932f5baa88e-image.png)

### 解题思路
直接看代码，暴力破解

### 代码

```c
int numTeams(int *rating, int ratingSize)
{
    int count;

    count = 0;
    for (int index = 0; index < ratingSize - 2; index++) {
        for (int mid = index + 1; mid < ratingSize; mid++) {
            for (int end = mid + 1; end < ratingSize; end++) {
                if ((rating[index] < rating[mid]) && (rating[mid] < rating[end])) {
                    count++;
                } else if ((rating[index] > rating[mid]) && (rating[mid] > rating[end])) {
                    count++;
                }
            }
        }
    }
    return count;
}
```