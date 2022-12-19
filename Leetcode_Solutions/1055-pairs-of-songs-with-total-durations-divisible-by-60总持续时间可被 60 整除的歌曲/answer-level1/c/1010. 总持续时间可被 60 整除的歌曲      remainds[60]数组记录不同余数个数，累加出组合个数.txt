### 解题思路
在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字  i < j 且有 (time[i] + time[j]) % 60 == 0。

 

示例 1：

输入：[30,20,150,100,40]
输出：3
解释：这三对的总持续时间可被 60 整数：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60



### 代码

```c
int numPairsDivisibleBy60(int* time, int timeSize){
    //60长度数组，记录不同种余数的个数。 从而算出组合个数
    int remainders[60] = {0}, i = 0, remain, sum = 0;

    for(i = 0; i < timeSize; i++) {
        remain = time[i]%60;
        //有多少个配对的余数， 就有多少种组合
        if(remain == 0){
            sum += remainders[0];
        }else
            sum += remainders[60-remain];
        
        remainders[remain]++;
    }

    return sum;
}
```