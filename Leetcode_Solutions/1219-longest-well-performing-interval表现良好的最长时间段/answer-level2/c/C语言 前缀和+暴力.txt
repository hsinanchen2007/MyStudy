先计算前缀和，然后暴力计算每个i为结尾的最长天数。
有个剪枝注意一下，固定i之后，j从0到i - 1遍历,找到符合条件的要结束本次循环。
不做这个剪枝和纯暴力就一样了，可能会超时。

```
int longestWPI(int* hours, int hoursSize){
    int max = 0;
    hours[0] = hours[0] > 8 ? 1 : -1;
    for (int i = 1; i < hoursSize; i++) {
        hours[i] = hours[i - 1] + (hours[i] > 8 ? 1 : -1);
    }
    for (int i = 0; i < hoursSize; i++) {
        if (hours[i] > 0) 
        {
            max = fmax(max, i + 1);
            continue;
        }
        for (int j = 0; j < i; j++) {
            if (hours[i] > hours[j]) {
                max = fmax(max, i - j);
                continue;  
            }
        }
    }
    return max;
}
```
