### 解题思路
此处撰写解题思路
回溯的方法，关键代码就是倒数三行
递归每次n+1表示每次找后一个数字所对应的字符串的字符，一个for循环可以遍历所有的字符，每一次加上当前字符就可以了。自己慢慢想吧。
其实看代码比较容易懂，自己写就有点脑子短路了。。。
### 代码

```java
class Solution {
    private String[]zd={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};        private List<String>ret=new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        
        if(digits==null||digits.length()==0) return ret;
        solve(digits,0,"");
        return ret;
    }
    private void solve(String s,int n,String r){
        if(n==s.length()){
            ret.add(r);
            return;
        }
        String l=zd[s.charAt(n)-'0'];
        for(char c:l.toCharArray()){
            solve(s,n+1,r+c);
        }
    }
}
```