![image.png](https://pic.leetcode-cn.com/b323c6a1c2d4be8dc6750d880df018412fe23f67f37efbb5c677524b729098d3-image.png)

```
int climbStairs(int n){
    int i;               //用于循环至第n级阶梯
    unsigned long mem[3];//假设当前阶梯为第k级阶梯 这个记忆数组是用于记录到达第k-1级阶梯的走法数n(k-1)以及
                         //到达k-2级阶梯的走法数n(k-2)
                         //k-2记录在mem[1]，k-1记录在mem[2],而mem[0]设置用来做交换
    if(n == 1) return 1;
    if(n == 2) return 2;
    mem[0]=0;mem[1]=1;mem[2]=2;//mem数组赋初值 到达第1级阶梯只有一种走法 到达第2级阶梯有2种走法
    for(i=3;i<=n;i++){   //循环从i=3开始，到达第3级阶梯的走法数等于n(1)+n(2),即mem[1]+mem[2];将这个结果存入mem[2]中
                         //并将mem[2]中原来的值存入mem[1]中，这样mem[1]和mem[2]中存储的便是n(2)和n(3)了
                         //上述过程类推可以得到n(4)、n(5)、n(6)……
        mem[0]=mem[2];
        mem[2] = mem[1] + mem[2];
        mem[1]=mem[0];
    }
    return mem[2];       //最终结果存在mem[2]中，返回mem[2]的值
}
```
