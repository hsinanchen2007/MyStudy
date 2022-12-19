![Snipaste_2020-03-27_18-35-52.png](https://pic.leetcode-cn.com/468d646087ea507aee44db050540085dfafa6485e63c26d5094185da214e9f44-Snipaste_2020-03-27_18-35-52.png)
对于这样一个Z字型数列 他是有规律的
第1行的数是满足等差数列首项为0，公差d为(2*numRows-2)
第2到n-1行 是row-1， (k*d-row+1), (k*d+row-1)
第numRows行也是等差数列，首项为numRows-1，公差还是d

于是很容易就得到最主要的逻辑部分
```
    	int size=s.length();
    	char[] c=new char[size];
    	int index=0;
    	int cha=2*numRows-2;
    	int k=0;
    	//第一行的值
    	while(k*cha<size){
    		c[index++]=s.charAt(k*cha);
    		k++;
    	}
    	//第二到n-1行
    	int row=2;
    	while(row<numRows){
    		c[index++]=s.charAt(row-1);
    		k=1;
    		while(k*cha-row+1<size){
    			c[index++]=s.charAt(k*cha-row+1);
    			if(k*cha+row-1<size){
    				c[index++]=s.charAt(k*cha+row-1);
    			}
    			k++;
    		}
    		row++;
    	}
    	//第numRows行
    	k=0;
    	while(numRows-1+k*cha<size){
    		c[index++]=s.charAt(numRows-1+k*cha);
    		k++;
    	}
```
最后注意一下初始值的问题，就可以了
```
    	if(numRows==1||numRows>s.length()){
    		return s;
    	}
```

完整代码如下：
```
    public static String convert(String s, int numRows) {
    	
    	if(numRows==1||numRows>s.length()){
    		return s;
    	}
    	
    	int size=s.length();
    	char[] c=new char[size];
    	int index=0;
    	int cha=2*numRows-2;
    	int k=0;
    	//第一行的值
    	while(k*cha<size){
    		c[index++]=s.charAt(k*cha);
    		k++;
    	}
    	//第二到n-1行
    	int row=2;
    	while(row<numRows){
    		c[index++]=s.charAt(row-1);
    		k=1;
    		while(k*cha-row+1<size){
    			c[index++]=s.charAt(k*cha-row+1);
    			if(k*cha+row-1<size){
    				c[index++]=s.charAt(k*cha+row-1);
    			}
    			k++;
    		}
    		row++;
    	}
    	//第numRows行
    	k=0;
    	while(numRows-1+k*cha<size){
    		c[index++]=s.charAt(numRows-1+k*cha);
    		k++;
    	}
		return String.valueOf(c);
    }
```
