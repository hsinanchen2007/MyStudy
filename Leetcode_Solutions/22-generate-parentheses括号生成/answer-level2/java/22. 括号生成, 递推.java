### 解题思路
#### 基本思路（18 ms）
```
f[i]: i 个括号组成的所有可能
f[i+1]= {
   （f[k]) + f[i-k-1], 
    f[k] + "()" + f[i-k-1], 
    f[k] + (f[i-k-1])
} (0 <=k <i) 
```

#### 优化（11 ms）
再看一下，会发现 `(f[k]) + f[i-k-1]`已经包含了后两种状态。
可以把递推公式写成
```
f[i]: i 个括号组成的所有可能
f[i+1]=（f[k]) + f[i-k-1] (0 <=k <i) 
```

拿 `f[4]` 举例看一下生成过程
```
leftSize=0:[]
rightSize=3:[()()(), ()(()), (()()), (())(), ((()))]
size=4:[()()()(), ()((())), ()(())(), ()()(()), ()(()())]
f[0] + "()" + f[3]： 在状态 (f[0]) + f[3] 里
f[0] + （f[3]）： 在状态 (f[3]) + f[0] 里 
---------------------
leftSize=1:[()]
rightSize=2:[()(), (())]
size=4:[()()()(), (())()(), (())(()), ()((())), ()(())(), ()()(()), ()(()())]
f[1] + "()" + f[2]: () + () + f[2] -> 在状态 (f[0]) + f[3] 里
f[1] + (f[2]): () + (f[2]) -> 在状态 (f[0]) + f[3] 里
---------------------
leftSize=2:[()(), (())]
rightSize=1:[()]
size=4:[()()()(), (())()(), (())(()), ()((())), ()(())(), (()())(), ()()(()), ()(()()), ((()))()]
f[2] + "()" + f[1]: 在状态 (f[0]) + f[3] 和 (f[1]) + f[2] 里
f[2] + (f[1]): 在状态 (f[0]) + f[3] 和 (f[1]) + f[2] 里
---------------------
leftSize=3:[()()(), ()(()), (()()), (())(), ((()))]
rightSize=0:[]
size=4:[()()()(), (()())(), (()(())), ()()(()), (())()(), (((()))), (())(()), ()((())), ()(())(), ()(()()), (()()()), ((()())), ((()))(), ((())())]
f[3] + "()" + f[0]: 在状态 (f[0]) + f[3] 和 (f[2]) + f[1] 里
f[3] + (f[0]): 在状态 (f[2]) + f[1] 里
```

### 代码
```java
class Solution {
    public List<String> generateParenthesis(int n) {
        ArrayList<String[]> allParenthesis = new ArrayList<>();
        Set<String> curParenthesis = new HashSet<>();
        ArrayList<String> res = new ArrayList<>();
        if (n == 0) return res;

        curParenthesis.add("");
        allParenthesis.add(curParenthesis.toArray(new String[curParenthesis.size()]));
        curParenthesis.clear();
        curParenthesis.add("()");
        allParenthesis.add(curParenthesis.toArray(new String[curParenthesis.size()]));
        for (int i = 2; i <= n; ++i) {
            curParenthesis.clear();
            // 前 k 个所有括号组合
            for (int k = 0; k < i; ++k) {
                String[] leftParenthesis = allParenthesis.get(k);
                String[] rightParenthesis = allParenthesis.get(i - k - 1);
                for (int l = 0; l < leftParenthesis.length; ++l) {
                    for (int r = 0; r < rightParenthesis.length; ++r) {
                         // 1 前
                        curParenthesis.add("(" + leftParenthesis[l] + ")" + rightParenthesis[r]);
                        // 2 后
                        // curParenthesis.add(leftParenthesis[l] + "(" + rightParenthesis[r] + ")");
                        // 3 中
                        // curParenthesis.add(leftParenthesis[l] + "()" + rightParenthesis[r]);
                    }
                }
            }
            allParenthesis.add(curParenthesis.toArray(new String[curParenthesis.size()]));
        }
        
        return Arrays.asList(allParenthesis.get(n));
    }
}
```