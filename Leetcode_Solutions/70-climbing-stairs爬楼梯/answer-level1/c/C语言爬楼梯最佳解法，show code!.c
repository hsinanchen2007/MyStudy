### 解题思路
使用尾递归

### 代码

```c
int climb(int n, int first,int second) {
    if (n == 1) {
        return first;
    }

    if (n == 2) {
        return second;
    }

    return climb(n-1,second,first+second);
}

int climbStairs(int n){
    return climb(n, 1, 2);
}

```