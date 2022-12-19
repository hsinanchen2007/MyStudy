**思路：**
1. 倒叙遍历两个字符串，直到两个字符串全部遍历完成。
1. 如果一方遍历完成则这个字符串此后的数值全部为0（也就是差位补0）
1. 再定义一个变量`count`用来记录是否有进位，判断两个字符串对应位置	的数与`count`三者的和，小于等于1，则把和追加；为2，则追加0；大	于2也就是三则追加一；同时修改对应的`count`
1. 最后判断到了最后一位是否需要进位。
 ```
    public static String addBinary(String a, String b) {
    	//记录是否有进位
    	int count = 0;
    	int aindex = a.length()-1;
    	int bindex = b.length()-1;
    	int acount,bcount;
    	StringBuilder s = new StringBuilder();
    	//倒叙遍历两个字符串，直到两个字符串全部遍历完成
    	while(aindex>=0||bindex>=0){
    		//获得对应位的数值，如果一方遍历完成则剩余位全部补0
    		if(aindex<0){
    			acount = 0;
    			//利用ASCII码值将字符转化为数值
    			bcount = b.charAt(bindex)-'0';
    		}else if(bindex<0){
    			bcount = 0;
    			acount = a.charAt(aindex)-'0';
    		}else{
    			acount = a.charAt(aindex)-'0';
    			bcount = b.charAt(bindex)-'0';
    		}
    		//判断对应为相加后的情况
    		if(acount+bcount+count<=1){
    			s.append(acount+bcount+count);
    			count = 0;
    		}else if(acount+bcount+count==2){
    			s.append(0);
    			count = 1;
    		}else{
    			s.append("1");
    			count = 1;
    		}
    		//下标减一
    		aindex--;
    		bindex--;
    		//最后判断最高位是否有进位
    		if(aindex<0&&bindex<0&&count==1){
    			s.append("1");
    			break;
    		}
    	}
    	//反转并转化成字符串
		return s.reverse().toString();
    }
```
