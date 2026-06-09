### 解题思路
一个总数，找到对应的n，等差数列求和；
需要特别注意的是，会有int溢出的情况，GetNum接口需要使用long

### 代码

```c
long GetNum(int n)
{
    long tmp = n;
    return tmp * (tmp + 1) / 2;
}

int Bsearch(int candies)
{
    int left, right, mid;

    left = 1;
    right = candies + 1;

    while (left < right) {
        mid = (left + right) / 2;
        if (GetNum(mid) > candies) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int* distributeCandies(int candies, int num_people, int* returnSize){
    int n = Bsearch(candies) - 1;
    int fullNum = GetNum(n);
    int lastNum = candies - fullNum;
    int *ans = (int *)calloc(1, sizeof(int) * num_people);
    int i, index;

    index = 1;
    while (index <= n) {
        for (i = 0; i < num_people; i++) {
            if (index > n) {
                break;
            }
            ans[i] += index++;
        }
    }

    if (i == num_people) {
        i = 0;
    }
    ans[i] += lastNum;

    *returnSize = num_people;
    return ans;
}
```