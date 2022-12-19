### 解题思路
    左边的括号是始终必须多于右边的括号的，当左边的括号还没到n的时候，两种括号都可以添加，当左括号到n了，只添加右括号。

### 代码

```java
class Solution {
    List<String> res = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        generate(n,"",0,0,0);
        return res;
    }

    private void generate(int n, String str, int left, int right, int now) {
        if ((n * 2) == now) {
            res.add(str);
            return;
        }
        if (left >= right && left < n){
            generate(n,str + "(",left + 1, right, now + 1);
            generate(n,str + ")",left, right + 1, now + 1);
        }else if(left >= right && right < n){
            generate(n,str + ")",left, right + 1, now + 1);
        }
    }
}
```