### 解题思路
此处撰写解题思路

### 代码

```c
int lastRemaining(int n, int m){
    int i = 0;
    int alive = 0;

    // 活着的数一直活着,但每次在圆圈里的index不一样,设为a
    // 倒数来看
    // 倒数第i次剔除r后剩余i个数, 状态如下
    // (r) xxx a xxx xx...xx     == > index(a, i) = x
    // 倒数第i次剔除前, 也就是倒数第i+1次删除后，状态如下
    //     xx...xx (r) xxx a xxx ==> index(a, i + 1) = (x + m) %  (i + 1)
    // 最后一次只留一个数, 即index(a, 1) = 0
    // 递推 index(a, 2) = (0 + m) % 1  
    //      index(a, 3) = (index(a, 2) + m) % 2 

    for (i = 2; i < n + 1; i++)
    {
        alive = (alive + m) % i;
    }
    return alive;
}
```