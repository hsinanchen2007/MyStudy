### 解题思路
遍历存下x的系数和常数的总和

### 代码

```java
class Solution {
    public String solveEquation(String equation) {
    	int positive , i=0;
    	int eSign = -1;
    	double x=0;
    	double constant=0;
    	
    	if(equation.charAt(0)=='-') {
    		positive = -1;
    		i++;
    	}else positive = 1;
    	
    	
        for(; i<equation.length() ; i++) {
        	int head = i;
        	while(i<equation.length() && equation.charAt(i)!='+' && equation.charAt(i)!='-' 
        			&&equation.charAt(i)!='=') i++;
        	
        	if(equation.charAt(i-1) == 'x') {
        		String s = equation.substring(head,i-1);
        		int num;
        		if(s.length() == 0 )num = 1;
        		else num  = Integer.valueOf(s);
        		
        		x+= -1*positive*eSign*num;
        	}else {
        		int num  = Integer.valueOf(equation.substring(head,i));
        		constant+= positive*eSign*num;
        	}
        	
        	if(i==equation.length())break;
        	
        	char c = equation.charAt(i);
        	if(c=='=') {
        		eSign =1;
        		if(equation.charAt(i+1)=='-') {
            		positive = -1;
            		i++;
            	}else {
            		positive = 1;
            	}
        	}else if(c=='+') positive =1;
        	else positive =-1;

        }
        if(x==0) {
        	if(constant!=0)return "No solution";
        	else return "Infinite solutions";
        }
        return "x="+(int)(constant/x);
    }
}
```