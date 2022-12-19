思路来源于：遍历法
```
class Solution {
    public String removeOuterParentheses(String S) {
               int count=0,index=0;         //count左括号次数, index单独括号数
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<S.length();i++){
			if(S.charAt(i)=='('){
				count++;index++;
			}else{
				index--;
			}
			if(index>0&&count!=1){
				sb.append(S.charAt(i));
			}
			if(index==0)
				count=0;
		}
		return sb.toString(); 
    }
}
```