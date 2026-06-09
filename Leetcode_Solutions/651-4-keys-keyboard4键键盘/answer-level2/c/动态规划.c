### 解题思路
输出的选择只有 A 或 Ctrl-V（前面要有Ctrl-A Ctrl-C）。
首先，定义状态 剩余的敲击次数n，数组a[n]为还剩n次敲击次数时输出A最多的次数；
其次，确定状态转移方程：
a[i] = a[i - 1] + 1 代表第i次选择敲击A
a[i] = a[j - 2] * (i - j + 1) 代表第j次选择Ctrl-V，其中j >= 2 && j < i;
最后，定义边界条件：
a[0] = 0;
### 代码

```c
int max(int a,int b){
    if(a > b)
        return a;
    else
        return b;
}
int maxA(int N){
    int a[N + 1];
    if(N < 1)
        return 0;
    if(N == 1)
        return 1;
    a[0] = 0;
    for(int i = 1;i < N + 1;++i){
        a[i] = a[i - 1] + 1;
        for(int j = 2;j < i;++j){
            a[i] = max(a[i],a[j - 2] * (i - j + 1));
        }
    }
    return a[N];
}
```