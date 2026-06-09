### 解题思路
![微信截图_20200318113101.png](https://pic.leetcode-cn.com/767c6be404840f6f57b4ef1ccba62b6c33f4c72a65f8c8eb6fa74443d3e5168d-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200318113101.png)

### 代码

```csharp
public class Solution {
    public int SuperEggDrop(int K, int N){
        int num = 1;
        while (f(num++, K) < N) ;
        return num - 1;
    }

    private int f(int a, int b) => (a == 1 || b == 1) ? a : (f(a - 1, b - 1) + 1 + f(a - 1, b));   
}
```