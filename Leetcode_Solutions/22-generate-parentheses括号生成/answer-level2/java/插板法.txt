### 解题思路
此处撰写解题思路
f(n) = g(f(n-1))
g() = 得到f(n-1)的结果.  在结果前放一个'(' f(n-1) 的结果中有 n个位置可插入')', 但是有重复. 去掉重复即可. 
f(1) = [()]
### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {

        List<String> list = new ArrayList<String>();
        if (n == 0) {
            return list;
        }
        //n==1时 返回[()]
        if (n == 1) {
            list.add("()");
            return list;
        }
        //得到n-1的结果.
        List<String> listN = generateParenthesis(n - 1);
        for (String s : listN) {
            char[] sd = s.toCharArray();
            for (int i = 1; i < sd.length + 2; i++) {
                char[] target = new char[sd.length + 2];
                //在结果前放一个'('
                target[0] = '(';
                //n-1 的结果中有 n个位置可插入')'
                System.arraycopy(sd, 0, target, 1, i - 1);
                target[i] = ')';
                System.arraycopy(sd, i - 1, target, i + 1, sd.length - i + 1);
                String addS = new String(target);
                //但是有重复. 去掉重复即可
                if (list.contains(addS)) {
                    continue;
                }
                list.add(addS);
            }
        }
        return list;
    }
}
```