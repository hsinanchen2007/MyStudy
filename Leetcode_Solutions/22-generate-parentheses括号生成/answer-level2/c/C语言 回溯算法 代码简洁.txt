画了个递归树帮助理解，虽然不美观，但能看

![generate.png](https://pic.leetcode-cn.com/49ab243c22f69648ee79b83aaf82ea05fdf34447021a16410c856d955139d1db-generate.png)



> 红色画叉（灰色）就算 减枝 的过程

```c
//递归回溯求解，注意减枝
#define MAX_SIZE 1430
void generate(int left, int right, int n, char *str, int index, char **result, int *returnSize) {
  if (left == n && right == n) {  //左右括号都用完
    result[(*returnSize)] =  (char*)calloc((2 * n + 1), sizeof(char));
    strcpy(result[(*returnSize)++], str);
    return;
  }

  if (left < n) {  //当左括号没用完时
    str[index] = '(';
    generate(left + 1, right, n, str, index + 1, result, returnSize);
  }
  if (left > right && right < n) {  //右括号数量必须小于左括号，否则一定不合法，且右括号没有用完
    str[index] = ')';
    generate(left, right + 1, n, str, index + 1, result, returnSize);
  }
}

char **generateParenthesis(int n, int *returnSize) {
  char *str = (char*)calloc((2 * n + 1), sizeof(char));
  char **result = (char **)malloc(sizeof(char *) * MAX_SIZE);
  *returnSize = 0;
  generate(0, 0, n, str, 0, result, returnSize);
  return result;
}
```

> MAX_SIZE 应是一个卡特兰数，官方测试用例中 n 最多为 8，所以 MAX_SIZE = 1430 即可；
```c
<!-- 卡特兰数的一个递推函数（我也是百度来的） -->
int catalan(n) {
  int i, j, h[n + 1];
  h[0] = h[1] = 1;
  for (i = 2; i <= n; i++) {
    h[i] = 0;
    for (j = 0; j < i; j++)
      h[i] = h[i] + h[j] * h[i - j - 1];
  }
  return h[n];
}
``` 