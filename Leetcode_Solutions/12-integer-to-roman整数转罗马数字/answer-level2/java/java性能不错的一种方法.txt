我从高位开始往下通过判断拼接对应的字符，把每位分成几部分，
1-3和6-8用循环，其余直接拼接，之后减掉对应的int值。
代码较量大，由于最多到千位还是比较合适的，效率很高，占内存少。
不需要使用map，减少了查询时间。
代码如下：

	public String intToRoman(int num) {

           StringBuilder sb=new StringBuilder();
            //1000+
        	int i=num/1000;
        	for(int j=0;j<i;j++) {
        		sb.append("M");
        		
        	}
        	num-=i*1000;
            
            //100-999
            if(num>=900){
            	sb.append("CM");
            	num-=900;
            }else if(num>=500) {
            	sb.append("D");
            	num-=500;
            	i=num/100;
            	for(int j=0;j<i;j++) {
            		sb.append("C");
            	}
            	num-=i*100;
            }else if(num>=400) {
            	sb.append("CD");	
            	num-=400;
            }else {
            	i=num/100;
            	for(int j=0;j<i;j++) {
            		sb.append("C");
            	}
            	num-=i*100;
            }
            
            
            //10-99
            if(num>=90) {
            	sb.append("XC");
            	num-=90;
            }else if(num>=50) {
            	sb.append("L");
            	num-=50;
              	i=num/10;
            	for(int j=0;j<i;j++) {
            		sb.append("X");
            	}
            	num-=i*10;
            }else if(num>=40) {
            	sb.append("XL");
            	num-=40;
            }else {
              	i=num/10;
            	for(int j=0;j<i;j++) {
            		sb.append("X");
            	}
            	num-=i*10;
            }
            
            //1-9
            if(num>=9) {
            	num-=9;
            	sb.append("IX");
            }else if(num>=5) {
            	num-=5;
            	sb.append("V");
              	i=num/1;
               	for(int j=0;j<i;j++) {
            		sb.append("I");
            	}
            }else if(num>=4) {
            	num-=4;
            	sb.append("IV");
            }else {
            	i=num/1;
               	for(int j=0;j<i;j++) {
            		sb.append("I");
            	}
            }
            
        return sb.toString();
	}


