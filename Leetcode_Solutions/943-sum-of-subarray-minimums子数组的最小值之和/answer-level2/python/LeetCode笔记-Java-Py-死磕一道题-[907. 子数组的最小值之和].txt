##### 方法1:单调栈
- 维护一个单调栈，思路如图，举例转的这个栈
- 维护一个`tmp`变量记录每一轮的`res`值，`res`的全局变量记录结果，每次弹出或是添加元素的时候，维护好`tmp`和`res`
![clipboard.png](https://pic.leetcode-cn.com/2f59d73899312f0c53eafdc5fc71daa31e221036b8eaca7e897a30c57b44b648-clipboard.png)


```java []
class Solution {
    int MOD = 1000000007;

    public int sumSubarrayMins(int[] A) {
        Stack<Pair> stack = new Stack<>();
        int res = 0, tmp = 0;
        for (int i = 0; i < A.length; i++) {
            int count = 1;
            while (!stack.empty() && stack.peek().val >= A[i]) {
                Pair pop = stack.pop();
                count += pop.count;
                tmp -= pop.val * pop.count;
            }
            stack.push(new Pair(A[i], count));
            tmp += A[i] * count;
            res += tmp;
            res %= MOD;
        }
        return res;
    }
}

class Pair {
    public int val;
    public int count;

    public Pair(int val, int count) {
        this.val = val;
        this.count = count;
    }
}

```
```python []
class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        MOD = 1000000007 # 维护一个单调递增栈
        stack = [(float('-inf'),float('-inf'))]
        res = tmp = 0
        for i in range(len(A)):
            count = 1
            while stack and A[i] <= stack[-1][0]:
                cur = stack.pop()
                count += cur[1]
                tmp -= cur[0] * cur[1]
            stack.append((A[i],count))
            tmp += A[i] * count
            res += tmp
            res %= MOD
        return res
```


