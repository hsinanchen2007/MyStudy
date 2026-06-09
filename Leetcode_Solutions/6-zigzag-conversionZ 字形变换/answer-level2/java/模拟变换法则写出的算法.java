我的方法是模拟变换法则，挨个转换的同时按行存储：
首先对原字符串顺序挨个遍历，按对应的行存入list中，
行的变化是从1到n,再从n到1，如此反复 比如n=4时是1 2 3 4  3 2  1 2 3 4
之后再从map中按行取出就OK了 性能上有很大优化空间，希望大家帮忙改进
代码如下：    

 	String convert(String s, int n) {
	 	//长度小于n，或者n=1时直接返回即可
        if(s.length()<=n||n==1){
            return s;
        }
        byte bytes[]=s.getBytes();

		//初始化map
	    Map<Integer,ArrayList<Integer>> map=new HashMap<>();
	    for(int i=0;i<n;i++) {
	    	map.put(i+1, new ArrayList<Integer>());
	    }

        boolean flag=true;
	    int i=0,j=0;
	    //遍历，行数到n就-,到1就+
	    while(i<s.length()) {
		if(j==n) {
			j=n-1;
			flag=!flag;
		}else if(j==1&&!flag) {
			j=2;
			flag=!flag;
		}else {
			if(flag) {
				j++;
			}else {
				j--;
			}
		}
        map.get(j).add((int)bytes[i++]);  		
	    }
		
		//按行取出
		StringBuilder sb=new StringBuilder();
		for(int m=0;m<n;m++) {
			for(int x:map.get(m+1)) {
				sb.append((char)x);
			}
		}
		
		return sb.toString();
    }


