### 解题思路
使用循环将字符串s中的每个字符逐一赋给字符串temp,进行递归，当都赋给temp后，将temp加入res列表。
每次退出函数前将进入函数后添加到temp的字符移除。

### 代码

```java
class Solution {
    List<String> res=new LinkedList<>();  //保存结果
    String temp="";      //记录当前字符串
    public String[] permutation(String S) {
        function(S);
        return res.toArray(new String[res.size()]);
    }
    /**
    *使用循环将字符串s中的每个字符逐一赋给字符串temp,把s除赋给temp的字符外其他字符串作为参数进行递归，当都赋给temp后，将temp加入res列表。
    *每次退出函数前将进入函数后添加到temp的字符移除。
    */
    void function(String s){
        if(s.length()==1){
            temp+=s;
            res.add(temp);
            temp=temp.substring(0,temp.length()-1);  //移除加入的字符
            return ;
        }
        for(int i=0;i<s.length();i++){
            temp+=s.charAt(i);
            function(s.substring(0,i)+s.substring(i+1,s.length()));  
            temp=temp.substring(0,temp.length()-1);  //移除加入的字符
        }
    }
}
```