### 解题思路
![image.png](https://pic.leetcode-cn.com/b9ee805234d6832c0a4c3c76302a2f80e34f3ef0d76b60a44f4dd9124aa9a0e5-image.png)
例子：A = 18, B = 16 A x B = 18 x (16 + 2) = 18 x 2^4 + 18 x 2^1 = 18 << 4 + 18 << 1

### 代码

```c
int multiply(int A, int B){
    //例子：A = 18, B = 16 A x B = 18 x (16 + 2) = 18 x 2^4 + 18 x 2^1 = 18 << 4 + 18 << 1
    int i, 
    sum = 0,
    max = A > B ? A : B,
    min = A > B ? B : A;

    if(min == 0) return 0;

    for(i = 0; min != 0; i++){
        if(min & 1 == 1){
            sum += max << i;
        }
        min >>= 1;
    }
    return sum;
}
```