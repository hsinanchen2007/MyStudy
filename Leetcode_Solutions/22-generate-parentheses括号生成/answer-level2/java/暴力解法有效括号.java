### 解题思路
暴力解法，左右括号数肯定相等，直到等于N结束，每次加一个左括号，或者右括号，必须保证右括号<=左括号数（有效括号）。

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        if(n ==0){
           return new ArrayList<>(0);
        }
        List<String> list = new ArrayList<>();
        addStr(n,1,0,"(", list);
        return list;
    }
    public static void addStr(int n,int left, int right, String str, List<String> data){
        if((left + right) == 2 * n){
            data.add(str);
            return;
        }
        if(left < n){
            addStr(n,left + 1,right,str.concat("("),data);
        }
        if(right < n && right < left){
            addStr(n,left,right + 1,str.concat(")"),data);
        }
    }
}
```