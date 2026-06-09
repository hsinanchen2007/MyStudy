public int calculate(String s) {
		char sign=' ';
		int res=0;
		int last=0;
		int i=0;
		while(s.charAt(i)==' ') {    //去掉开始的空格
			i++;
		}
		while(i<s.length()&&s.charAt(i)-'0'>=0&&s.charAt(i)-'0'<=9) {     //将第一个数赋给res；
			res=res*10+s.charAt(i)-'0';
			i++;
		}
        for(;i<s.length();i++) {
        	char c=s.charAt(i);
        	if(c=='+'||c=='-') {
        		if(sign=='+') {
        			res=res+last;
        		}else if(sign=='-') {
        			res-=last;
        		}
        		sign=c;        //存储当前的运算符('+'/'-')
        	}else if(c=='*'||c=='/') {
        		while(s.charAt(i+1)==' ') {
        			i++;
        		}
        		int b=0;
        		while(i+1<s.length()&&s.charAt(i+1)-'0'>=0&&s.charAt(i+1)-'0'<=9) {
        			b=b*10+s.charAt(i+1)-'0';
        			i++;
        		}
        		if(sign!=' ') {
        			if(c=='*') {
        				last=last*b;
        			}else {
        				last=last/b;
        			}
        		}else {
        			if(c=='*') {
        				res=res*b;
        			}else {
        				res=res/b;
        			}
        		}
        	}
        	else if(c==' ') {
        		continue;
        	}else {
        		int b=0;
        		while(i<s.length()&&s.charAt(i)-'0'>=0&&s.charAt(i)-'0'<=9) {
        			b=b*10+s.charAt(i)-'0';
        			i++;
        		}
        		last=b;
        		i--;
        	}
        }
        return sign=='+'?res+last:res-last;
    }