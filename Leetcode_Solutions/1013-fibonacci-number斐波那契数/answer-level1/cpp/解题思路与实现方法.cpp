### 解题思路
该题目主要分析思想
# 解题方法
1、递归
2、如上

# 我们思考下 f(0) = 0 ; f(1) =1  f(x) = f(n-1) + f(n - 2)
    1、看到前面0，1 都是原路返回，其实这种思想在递归中我们称为终止条件。 从第三个数开始我们发现都是前面两个数相加，这种思想
怎么实现了， 这时候就要引入中间变量，为了不污染前面两个数据。  
### 代码

```cpp
class Solution {
public:
  int fib(int N) {
    if (N <= 1) return N;
    int first = 0;
    int  sec = 1;
    int sum = 0;
    // 2
    for(int i = 0; i < N -1; i ++) {
      sum = first + sec;
      first = sec;
      sec = sum;
    }
    return sec;
  }
};
```


