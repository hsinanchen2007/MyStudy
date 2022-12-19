![image.png](https://pic.leetcode-cn.com/5e8d1750cd9a48f649d49587705ac0240a737884e85f866fc04b62fc6b13769d-image.png)
### 解题思路
1. gcd函数
2. 两个临界条件
3. z和Gcd(x,y)是否能够整除

### 代码

```c
 int Gcd(int M,int N)
{
    return N?Gcd(N,M%N):M;
}

bool canMeasureWater(int x, int y, int z){
    if(z==y || z==x || z==(x+y)) return true;//临界1：需要的z升水等于x或y或(x+y)，不用倒腾，直接ok
    if(z > x+y) return false;//临界2：需要的z升水大于(x+y)，两个加一起都装不下这么多水，false
    return z % Gcd(x,y) == 0;//最后看需要的z升水与x、y的最大公约数是不是成倍数(此时z<x+y)
}
```