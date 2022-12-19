### 解题思路
参考
https://leetcode-cn.com/problems/valid-perfect-square/solution/c-li-yong-wan-quan-ping-fang-shu-de-xing-zhi-qiu-j/
### 代码

```c
bool isPerfectSquare(int num){
    if (num == 0 ) return false;
    for(int i=1;num>0;i+=2)
        num -= i;
    return num == 0;
}
```