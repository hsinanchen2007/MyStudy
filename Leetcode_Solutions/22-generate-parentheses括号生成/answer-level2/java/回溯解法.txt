```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        // 字符数组存储可能的结果，长度已确定。
        char[] c = new char[n*2];
        generate(res,n,0,0,c);
        return res;
    }
    
    /*
    * @res 最后返回的结果
    * @n 总括号对数
    * @c1 左括号的个数
    * @c2 右括号的对数
    * @c 当前已存储的字符
    */
    public void generate(List<String> res,int n,int c1,int c2,char[] c){
        // 结束条件判断
        if(c1 > n || c2 > n || c2 > c1)
            return;
        // 添加进结果集条件判断
        if(c1 == n && c2 == n){
            res.add(String.valueOf(c));
            return;
        }

        if(c1 >= c2){
            // 添加左括号
            c[c1+c2]='(';
            generate(res,n,c1+1,c2,c);
            // 添加右括号
            c[c1+c2]=')';
            generate(res,n,c1,c2+1,c);
        }
    }
}
```
