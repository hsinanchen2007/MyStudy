### 解题思路
本题是前缀和的变形，无需对所有位置进行累加，只需要在最大值的位置进行累加即可，这里给出C语言的代码。

1.遍历数组，获得当前位置

2.如果当前位置是最大位置，则更新最大位置，其值为之前最大位置+1

3.如果不是最大位置，则对最大位置的值进行+1更新

4.判断最大值位置的值是否和其id相等。

注意，代码空间可以进一步优化，降低到1，这里保留数组形式，便于阐明思路。

![image.png](https://pic.leetcode-cn.com/18df14ceee4397faa147b8face811125a64fd38478bc0d8734d01c4576af9f4b-image.png)


### 代码

```c
//【算法思路】积分。
int numTimesAllBlue(int* light, int lightSize){
    int *prefix = (int *)calloc(lightSize + 1, sizeof(int));
    int max_id = 0;

    int ret = 0;
    for(int i = 0; i < lightSize; i++) {
        int nid = light[i];
        if(nid > max_id) {
            //更新顶部
            prefix[nid] = prefix[max_id] + 1;
            max_id = nid;
        } else {
            prefix[max_id]++;
        }

        if(prefix[max_id] == max_id) {
            ret++;
        }
/*
        for(int j = 0; j <= max_id; j++) {
            printf("%d   ", prefix[j]);
        }
        printf("\n");
*/
    }

    return ret;
}
```