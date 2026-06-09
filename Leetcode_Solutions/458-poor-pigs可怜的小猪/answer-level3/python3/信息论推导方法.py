首先，对数的底数取多少不影响信息量的计算。
一共有n个桶，要知道哪个桶有有毒药，至少需要math.log2(n)的信息量
每一只猪可以测试的次数是t=math.floor(minutesToTest/minutesToDie)。每只猪有t+1种状态，在第i次死亡（i:[1,2,...，t],或者存活，带信息量math.log2(t+1)
假设需要num只猪，则有num*math.log2(t+1)>=math.log2(n)
所以答案就是math.ceil[math.log2(n)/math.log2(t+1)]