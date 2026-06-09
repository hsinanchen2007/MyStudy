### 解题思路
用replaceFirst把左边的 ")" 删掉,再把右边的 "(" 删掉...
因为没有replaceLast函数(可以试试写一个),把它翻转过来最后在翻转回去.......

### 代码

```java
class Solution {
    public String minRemoveToMakeValid(String s) {
        int n=0;
		char[] cs=s.toCharArray();
		for(int i=0;i<cs.length;i++){
			if(cs[i]=='(')
				n++;
			if(cs[i]==')'){
				n--;
				if(n<0){
					s=s.replaceFirst("\\)", "");
					n++;
				}
			}
		}
		s = new String( new StringBuffer(s).reverse() );
		n=0;
		cs=s.toCharArray();
		for(int i=0;i<cs.length;i++){
			if(cs[i]==')')
				n++;
			if(cs[i]=='('){
				n--;
				if(n<0){
					s=s.replaceFirst("\\(", "");
					n++;
				}
			}
		}	
		return new String( new StringBuffer(s).reverse() );
    }
}
```