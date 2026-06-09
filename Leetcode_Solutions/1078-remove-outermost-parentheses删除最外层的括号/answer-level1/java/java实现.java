```
 public String removeOuterParentheses(String S) {
        String res = "";
		int start = 0;
		int end = 0;
		int n = 0;
		for(int i=0;i<S.length();i++){
			
			char s = S.charAt(i);
			
			if('(' == s){
				if(0 == n){
					start = i;
				}
				n++;
			}
			if(')' == s){
				end = i;
				n--;
			}
			if(0 == n){
				res = res + S.substring(start+1,end);
			}
		}
        return res;
    }
```
