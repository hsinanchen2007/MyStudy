
本题可以使用容量为sum(arr)/2的0-1背包算法来求解.
题目可以简化为,把石头分为两堆, 用一堆之和减去另一堆之和的最优解.
由于这个问题的最优解是0, 且不会出现负数, 自然而然就想到求出权重之和最接近于sum(arr)/2的一堆石头, 设其值为w.
那么最终解就是sum(arr) - 2*w.


```c
// 可将这题转化为0-1背包问题
// 背包容量设置为storage = sum(stones)/2, 背包能装下石头权重之和最大值为full
// 那么最后所求值为sum(stones) - 2* full

int max(int a, int b){
    return a>b?a:b;
}

int lastStoneWeightII(int* stones, int stonesSize){
    // 求的背包的容量storage
    int sum_w = 0;
    for(int i=0; i<stonesSize; i++)
        sum_w += stones[i];
    int storage = sum_w / 2;

    // 记录背包容量在0,1,2...storage时分别能装下的石头权重最大和. 一开始初始化为0.
    int packages[storage+1]; 
    memset(packages, 0, sizeof(packages));

    // 求背包最多能装下多重的石头
    for(int i=0; i<stonesSize; i++){ //一共尝试装n次,一块一块的往背包里装石头
        for(int j=storage; j>-1;j--){
            if(j < stones[i])
                break;
            //求的当背包容量为j时, 装第i快石头装入背包或不装入背包的最大值
            packages[j] = max(packages[j], packages[j-stones[i]]+stones[i]);
        }
    }
    // 当i快石头都尝试完毕后,我们packages[storage]即为容量为storage的背包能装下的最重石头之和

    return sum_w - 2*packages[storage];


}
```
