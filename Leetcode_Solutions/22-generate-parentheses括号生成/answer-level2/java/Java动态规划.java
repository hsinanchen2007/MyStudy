### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<List<String>> dp = new ArrayList<>(n+1);
        dp.add(0, Arrays.asList(""));

        for (int i = 1; i <= n; i++) {
            List<String> tmp = new ArrayList<>();
            for (int p = 0; p < i; p++) {
                int q = i - 1 - p;
                if(p == 0){
                    for (String s : dp.get(q)) {
                        tmp.add("()" + s);
                    }
                }
                else if(p == i - 1){
                    for (String s : dp.get(p)) {
                        tmp.add("(" + s + ")");
                    }
                }
                else{
                    for (String s1 : dp.get(p)) {
                        for (String s2 : dp.get(q)) {
                            tmp.add("(" + s1 + ")" + s2);
                        }
                    }
                }
            }
            dp.add(i, tmp);
        }
        return dp.get(n);
    }
}
```