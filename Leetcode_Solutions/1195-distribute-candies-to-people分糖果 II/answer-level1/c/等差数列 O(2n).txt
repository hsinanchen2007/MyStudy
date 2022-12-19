### 解题思路
思路1：
1.只要還有candies，就循环，维护一个第几轮的计数。
2.内层循环按人数循环，减去每个人这一轮分配的candies。

思路2：
1. 假设有r轮分完糖果，则(1+r*n)*(r*n)/2=candies，可以得到r=(sqrt(8*candies+1)-1)/2*n
2. 则每个人的糖果数是1,n+1,2n+1，这样的r个等差数列元素，和为(i+1+i+1+(r-1)*n)*r/2;
3. 计算不够分的糖果，多循环一次分完
4. 8*candies这里会溢出，使用long long

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ret = (int*)malloc(sizeof(int) * num_people);
    (void)memset(ret, 0, sizeof(int) * num_people);
    *returnSize = num_people;

    int round = (int)(sqrt(8*(long long)candies+1)-1)/(2*num_people);

    int i;
    for (i=0; i<num_people; i++) {
        ret[i] = (i+1+i+1+(round-1)*num_people)*round/2;
    }

    int remain = candies - round*num_people*(round*num_people+1)/2;
    if (!remain) return ret;

    for (i=0; i<num_people; i++) {
        if (remain > round*num_people+i+1) {
            ret[i] += (round*num_people+i+1);
            remain -= (round*num_people+i+1);
        } else {
            ret[i] += remain;
            break;
        }
    }
    return ret;
}
```