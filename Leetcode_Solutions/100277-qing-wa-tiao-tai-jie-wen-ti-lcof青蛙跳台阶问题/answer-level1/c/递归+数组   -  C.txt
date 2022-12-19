### 解题思路
1.n==0时，返回的步数时1？（因为题目就是这么规定的，如果要理解： 0 层台阶也有一种跳法（即不跳））
2.递归三步走：
  a.定义函数。
  b.找到出口，n==0时，返回的步数时1；n==1时，返回1；
  c.找到等价交换式。f(n)=f(n-1)+f(n-2);
3.使用递归函数，等台阶到43时，就会报出时间超时。
4.进行优化，因为递归时会存在重复计算的场景，申请一个固定长度的数组，用于保存过程数据。
5.执行结果：
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :5.1 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
#define MAX_VALUE 1010
int arr[1010]= {-1};
int func(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (arr[n] != -1) {
        return arr[n];
    }
    arr[n] = (func(n - 1) + func(n - 2)) % 1000000007;
    return arr[n];
}

int numWays(int n){
    int value;
    int i;

    for (i = 0; i < MAX_VALUE; i++) {
        arr[i] = -1;
    }
    value = func(n);
    return value;
}
```