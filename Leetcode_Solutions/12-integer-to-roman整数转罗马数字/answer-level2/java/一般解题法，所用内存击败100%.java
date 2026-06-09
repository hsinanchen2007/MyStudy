```
public String intToRoman(int num) {
	        int i=0,x;
	        StringBuffer str=new StringBuffer();    //最终要输出的字符串
	        StringBuffer s=new StringBuffer();     //暂存
	        char[] c= {'I','V','X','L','C','D','M'};
	        while(num!=0) {
	        	x=num%10;
	        	num=num/10;	    
	        	s=new StringBuffer("");   //清空暂存
	        	switch(x) {
	        	case 0:break;
	        	case 1:s.append(c[i]);break;
	        	case 2:s.append(c[i]).append(c[i]);break;
	        	case 3:s.append(c[i]).append(c[i]).append(c[i]);break;
	        	case 4:s.append(c[i]).append(c[i+1]);break;
	        	case 5:s.append(c[i+1]);break;
	        	case 6:s.append(c[i+1]).append(c[i]);break;
	        	case 7:s.append(c[i+1]).append(c[i]).append(c[i]);break;
	        	case 8:s.append(c[i+1]).append(c[i]).append(c[i]).append(c[i]);break;
	        	case 9:s.append(c[i]).append(c[i+2]);break;	        	
	        	}
	        	i=i+2;	       //进阶 	
	        	str=s.append(str);
	        }
	        return str.toString();
	        }
```
