## 思路:

根据[维基百科](https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81#%E7%9B%B4%E6%8E%A5%E6%8E%92%E5%88%97)性质,有三种方法

思路一:二进制数转格雷码

即: $G(n) = B(n+1)$ XOR $B(n)$

思路二:镜射排列


![镜面.png](https://pic.leetcode-cn.com/7a14e1e43158a6ba9435988faafa59464608636b6f9e8ee07ee74b46f75a5995-%E9%95%9C%E9%9D%A2.png)


思路三:直接排列

以二进制为0值的格雷码为第零项，第一项改变最右边的位元，第二项改变右起第一个为1的位元的左边位元，第三、四项方法同第一、二项，如此反复，即可排列出n个位元的格雷码.



## 代码:

思路一:

```python [1]
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = []
        for i in range(2 ** n):
            res.append((i >> 1) ^ i)
        return res
```



```java [1]
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < Math.pow(2, n); i++) {
            res.add((i >> 1) ^ i);
        }
        return res; 
    }
}
```

思路二:

```python [2]
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = [0]
        for i in range(n):
            for j in range(len(res) - 1, -1, -1):
                res.append(res[j] ^ (1 << i))
        return res
```



```java [2]
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(0);
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.add(res.get(j) ^ (1 << i));
            }
        }
        return res;
    }
}
```

思路三:

```python [3]
class Solution:
    def grayCode(self, n: int) -> List[int]:
        num = "0" * n
        res = [0]
        c = 2 ** n
        while len(res) < c:
            if num[-1] == "0":
                num = num[:-1] + "1"
                res.append(int(num, 2))
            else:
                num = num[:-1] + "0"
                res.append(int(num, 2))
            # print(num)

            if len(res) == c:
                break
            idx = num.rfind("1")
            if num[idx - 1] == "0":
                num = num[:idx - 1] + "1" + num[idx:]
            else:
                num = num[:idx - 1] + "0" + num[idx:]
            # print(num)
            res.append(int(num, 2))

        return res
```

```java [3]
class Solution {
    public List<Integer> grayCode(int n) {
        StringBuilder num = new StringBuilder();
        List<Integer> res = new ArrayList<>();
        res.add(0);
        double c = Math.pow(2, n);
        for (int i = 0; i < n; i++) num.append('0');
        while (res.size() < c) {
            if (num.charAt(num.length() - 1) == '0') {
                num.setCharAt(num.length() - 1, '1');
                res.add(Integer.parseInt(num.toString(), 2));
            } else {
                num.setCharAt(num.length() - 1, '0');
                res.add(Integer.parseInt(num.toString(), 2));
            }
            if (res.size() == c) break;
            int idx = num.lastIndexOf("1");
            if (num.charAt(idx - 1) == '0') {
                num.setCharAt(idx - 1, '1');
            } else {
                num.setCharAt(idx - 1, '0');
            }
            res.add(Integer.parseInt(num.toString(), 2));
        }
        return res;     
    }
}
```

