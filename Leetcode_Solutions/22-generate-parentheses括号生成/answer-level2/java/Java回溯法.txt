### 解题思路
  在解答此题时，首先应该想到通过递归来返回所有结果。最开始我思考着能不能使用栈来辅助操作，但是发现比较不好处理，因为判断出栈插入的条件比较复杂，你需要清楚是直接向字符串中插入"()"，还是先在首部插入'('再在尾部插入')'。于是采用回溯法，直接使用StringBuilder来复杂存储当前的字符串，但是在使用的StringBuilder的时候千万记住要回溯，不然结果就会出错。
  以上是个人的愚见，望大神指点。

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
      List<String> list = new ArrayList<>();
      StringBuilder sb = new StringBuilder();
      getAll(n,n,list,sb);
      return list; 
    }
    
    /*
    *getAll函数用于获取所有的结果存入list中
    *@right:右括号数
    *@left:左括号数
    *@sb:记录当前组合的字符串。
    *   使用StringBuilder是对String的优化，但是导致在使用的过程中需要回溯sb，否则会影响结果
    */
    private void getAll(int right,int left,List<String> list,StringBuilder sb){
      //左右括号数都添加到sb中即可输出
      if(left==0&&right==0){
        list.add(sb.toString());
        return;
      }
      //左括号有优先权，不需要管右括号数，直接添加到sb
      if(left>0){
        sb.append('(');
        int l1 = sb.length();
        getAll(right,left-1,list,sb);
        sb.deleteCharAt(l1-1);//回溯:保证sb不被影响
      }
      //右括号必须看左括号的脸色行事,即right>left
      if(right>0&&right>left){
        sb.append(')');
        int l2 =sb.length();
        getAll(right-1,left,list,sb);
        sb.deleteCharAt(l2-1);//回溯：保证sb不被影响
      }
    }
}
```