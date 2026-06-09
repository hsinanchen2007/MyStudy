### 解题思路
递归解决，难点在于递归函数内部的设计：
1.参数内容：string str,left(左括号数量)，right(右括号数量)，n(括号的对数)
2.函数设计：先写出返回条件：左右括号数量==n
            如果left括号的数量<n,那么就可以加"("
            如果right括号的数量小于left括号的数量，就可以加")"

### 代码

```java
class Solution {
    public static List<String> alist;
    public List<String> generateParenthesis(int n) {
        // 使用递归遍历的方式遍历出所有字符组合
        alist = new ArrayList<>();
        trace("",0,0,n);
        return alist;
    }
    public static void trace(String str,int left,int right,int n){
        if(left==n&&right==n){
            alist.add(str);
            return;
        }
        if(left<n){
            trace(str+"(",left+1,right,n);
        }
        if(left>right){
            trace(str+")",left,right+1,n);
        }

    }
}
```