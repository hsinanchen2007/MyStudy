### 解题思路
暴力破解 在 i的平方 一直小于num , 最后加一跨过临界值 如果刚好等于num ,num就是平方数
![image.png](https://pic.leetcode-cn.com/b9ab2e859baf3212ec95e7f0f4b2331d1fe979bb8c8870f341858865531d313d-image.png)

### 代码
```c
bool isPerfectSquare(unsigned int num)
{
    unsigned int i  ;
    for(i=0;i*i<num;i++);
    return i*i==num?1:0;
}
```