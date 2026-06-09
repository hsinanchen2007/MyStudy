### 解题思路
第一反应是用了键值对， 然后程序就写的很复杂

### 代码

```java

class Solution {
    public int romanToInt(String s) {
	 int num=0;
		 Map<String, Integer> map = new HashMap<>();
		 map.put("I", 1);
		 map.put("V", 5);
		 map.put("X", 10);
		 map.put("L", 50);
		 map.put("C", 100);
		 map.put("D", 500);
		 map.put("M", 1000);

		 //遍历map容器
		 Set<Map.Entry<String, Integer>>  ss = map.entrySet();

		 
		 //获得第一个键对应的值
		 char temp = s.charAt(0);
		 String c = String.valueOf(temp); 
		 int preNum = 0;
		 for (Iterator iterator = ss.iterator(); iterator.hasNext();) {
			    Map.Entry e = (Map.Entry) iterator.next(); 
			    if( e.getKey().equals(c)   ) {
			    	preNum =(int)e.getValue();    //第一个数 赋值给preNum

			    }
			    }

		
			    	
			    	
		 for (int i=1;i<s.length();i++)
		 {
			  temp = s.charAt(i);
			  c = String.valueOf(temp);   //把单个字符变成字符串进行比较
			  
		
			 for (Iterator iterator = ss.iterator(); iterator.hasNext();) {
				    Map.Entry e = (Map.Entry) iterator.next(); 

				    //把一个小值放在大值的左边，就是做减法，否则为加法。
				    if( e.getKey().equals(c)  && (preNum >=  (int)e.getValue()) )   //左边的值比现在的值大  ，那就加
				    {
		
				    	num = num +preNum;
				    	preNum = (int)e.getValue();
			//	    	System.out.println("prenum="+ preNum +"   num= "+num );
				    	
				   //  System.out.println("对应的值是"+num);
				    }
				    if( e.getKey().equals(c)  && (preNum <  (int)e.getValue()) ) {
				    	//num =(int)e.getValue() -preNum;
				    	num = num -preNum;
				    	preNum = (int)e.getValue();
				   // 	System.out.println("prenum="+ preNum  );
				    }
			 }
			
			  
			 
			 
		 }
		 num =num+preNum;
		 return num;
		 
		 
	    }
}
```