### 解题思路
在回溯中，若在某一条件下有多种可能，用for循环实现即可

### 代码

```java
class Solution {
    List<String> list = new ArrayList();
    
    public List<String> generateParenthesis(int n) {
        getParenthesis(0,0,new StringBuffer(),n);
        return list;

    }
    
    public void getParenthesis(int leftNum, int rightNum, StringBuffer sb, int n){
        if(leftNum == n && rightNum == n){
            list.add(new String(sb));
            return ;
        }
        
        if(leftNum > n || rightNum > n)
            return ;
        
        if(leftNum < rightNum){
            return ;
        }
        
        if(leftNum > rightNum){
            for(int i=0; i<2; i++){
                if(i==0){
                    sb.append('(');
                    getParenthesis(leftNum+1,rightNum,sb,n);
                    sb.deleteCharAt(sb.length()-1);
                }else{
                    sb.append(')');
                    getParenthesis(leftNum,rightNum+1,sb,n);
                    sb.deleteCharAt(sb.length()-1);
                }
            }
        }
        
        if(leftNum == rightNum){
            sb.append('(');
            getParenthesis(leftNum+1,rightNum,sb,n);
            sb.deleteCharAt(sb.length()-1);
        }
        
        
    }
}
```