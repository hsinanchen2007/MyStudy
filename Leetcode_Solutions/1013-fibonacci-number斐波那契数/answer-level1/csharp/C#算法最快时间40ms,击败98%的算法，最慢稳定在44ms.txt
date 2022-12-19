### 解题思路
此处撰写解题思路
创建一个三个元素的数组，并且想到N/3的余数变化和数组下标可以一一对应，于是利用循环结构滚动计算F(N)的值
### 代码

```csharp
public class Solution {
    public int Fib(int N) {

        int a = 0;
        int b = 1;
        int c = 0;
        int[] fib = new int[3] {a,b,c};
        for (int i = 0; i < N - 1; i ++) {
            fib[(i + 2) % 3] = fib[(i + 1) % 3] + fib[(i + 3) % 3];
        }
        return fib[N % 3];
    }
}
```