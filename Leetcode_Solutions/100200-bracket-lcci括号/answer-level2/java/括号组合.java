### 解题思路
回溯，刚学会，很牛逼

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        backtrack(list, n, 0, "");
        return list;
    }
    
    public static void backtrack(List<String> list, int left, int right, String str){
        if(left==0 && right==0){
            list.add(str);
        }else{
            if(left>0){
                backtrack(list,left-1,right+1,str+"(");
            }
            if(right>0){
                backtrack(list,left,right-1,str+")");
            }
        }
    }
}
```