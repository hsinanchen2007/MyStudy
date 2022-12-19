### 解题思路
经典的丑数类问题，这里给出c语言的解法。

1.为每个素数建立一个id用于记录从结果数组中取数的游标。

2.结果数组初始化ret[0] = 1;

3.根据每个素数自己的游标，从结果数组中取数与自身相乘，得到新的临时结果，注意该结果必须比ret[i-1]要大（去重）

4.选出最小的新的临时结果作为该位置最终结果

5.重复3，直至结束。

关键注意3中的去重步骤。


![image.png](https://pic.leetcode-cn.com/6f7bd5d6cc9a29cd71fdf9e37156adb8d4c76169f5363459e35aea5df69658c3-image.png)

### 代码

```c

int nums[3] = {3, 5, 7};

//【算法思路】数学。丑数类问题。
//关键点1：使用已有结果数组，每个素数独立维护生成的结果
//关键点2：去重。新结果必须大于上一个已有结果。
int getKthMagicNumber(int k){
    if(k == 1) {
        return 1;
    }

    int id[3] = {0};

    int *ret = (int *)calloc(k, sizeof(int));

    ret[0] = 1;

    for(int i = 1; i < k; i++) {
        int min = INT_MAX;
        int mid;
        for(int j = 0; j < 3; j++) {
            int tmp = nums[j] * ret[id[j]];

            while(tmp <= ret[i - 1]) {
                id[j]++;
                tmp = nums[j] * ret[id[j]];
            }

            if(tmp < min) {
                min = tmp;
                mid = j;
            }
        }

        ret[i] = min;
        id[mid]++;
        //printf("ret[%d] = %d, id[%d] = %d\n", i, ret[i], mid, id[mid]);
    }

    return ret[k - 1];
}
```