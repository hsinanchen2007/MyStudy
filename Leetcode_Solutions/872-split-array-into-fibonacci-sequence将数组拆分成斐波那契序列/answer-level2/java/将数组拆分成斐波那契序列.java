#### 方法 1：暴力

**想法**

数组的前两个元素唯一决定了后面的数组元素。

**算法**

对于每种可能的前两个元素，假设没有前导零，遍历剩余的字符串。对于每个情况，我们希望得到小于等于 `2^31 - 1` 的数，且是前两个数字之和。

```Java []
class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        int N = S.length();
        for (int i = 0; i < Math.min(10, N); ++i) {
            if (S.charAt(0) == '0' && i > 0) break;
            long a = Long.valueOf(S.substring(0, i+1));
            if (a >= Integer.MAX_VALUE) break;

            search: for (int j = i+1; j < Math.min(i+10, N); ++j) {
                if (S.charAt(i+1) == '0' && j > i+1) break;
                long b = Long.valueOf(S.substring(i+1, j+1));
                if (b >= Integer.MAX_VALUE) break;

                List<Integer> fib = new ArrayList();
                fib.add((int) a);
                fib.add((int) b);

                int k = j + 1;
                while (k < N) {
                    long nxt = fib.get(fib.size() - 2) + fib.get(fib.size() - 1);
                    String nxtS = String.valueOf(nxt);

                    if (nxt <= Integer.MAX_VALUE && S.substring(k).startsWith(nxtS)) {
                        k += nxtS.length();
                        fib.add((int) nxt);
                    }
                    else continue search;
                }
                if (fib.size() >= 3) return fib;
            }
        }

        return new ArrayList<Integer>();
    }
}
```

```Python []
class Solution(object):
    def splitIntoFibonacci(self, S):
        for i in xrange(min(10, len(S))):
            x = S[:i+1]
            if x != '0' and x.startswith('0'): break
            a = int(x)
            for j in xrange(i+1, min(i+10, len(S))):
                y = S[i+1: j+1]
                if y != '0' and y.startswith('0'): break
                b = int(y)
                fib = [a, b]
                k = j + 1
                while k < len(S):
                    nxt = fib[-1] + fib[-2]
                    nxtS = str(nxt)
                    if nxt <= 2**31 - 1 and S[k:].startswith(nxtS):
                        k += len(nxtS)
                        fib.append(nxt)
                    else:
                        break
                else:
                    if len(fib) >= 3:
                        return fib
        return []
```



**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `S` 的长度，按照要求结果的长度都是 $O(1)$ 的。
* 空间复杂度：$O(N)$。