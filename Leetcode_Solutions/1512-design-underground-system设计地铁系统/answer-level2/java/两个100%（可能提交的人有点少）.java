![1.png](https://pic.leetcode-cn.com/e902f3b11630189375cf004dd85c9514cf1585da9fa4c92fd0ab6cf2da1acaf6-1.png)

用两个map
一个记录 乘客上车  Map<id,(string)(stationName+" "+t)>
一个用来记录 起点终点  总时间总次数  Map<startStation+endStation,(string) 总时间+" "+总次数>
checkIn
直接put(id, stationName+" "+t)就可以了
checkOut 
用id找到乘客上车的位置 当时时间
如果起始位置和终点位置以前有人，就把总时间加上现在时间减当时时间，总次数加1
如果以前没有人，现在是第一个，那么，总时间就是现在时间减当时时间 ，总次数为1 
getAverageTime
就是总时间除以总次数
代码如下
```
class UndergroundSystem {
    Map<Integer, String> midMap ;
    Map<String, String> timeMap;
    public UndergroundSystem() {
    	midMap=new HashMap<>();
    	timeMap=new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
    	midMap.put(id, stationName+" "+t);
    }
    
    public void checkOut(int id, String stationName, int t) {
    	String [] str =midMap.get(id).split(" ");
    	if (timeMap.containsKey(str[0]+stationName))
		{
    		String [] strings = timeMap.get(str[0]+stationName).split(" ");
    		String string;
    		string=
    				String.valueOf(Integer.parseInt(strings[0])+t-Integer.parseInt(str[1]))//总时间
    				+" "
    				+String.valueOf(Integer.parseInt(strings[1])+1);//总次数
    		timeMap.put(str[0]+stationName, string);}
    	else {
    		timeMap.put(str[0]+stationName, t-Integer.parseInt(str[1])+" 1");
		}
    }
    
    public double getAverageTime(String startStation, String endStation) {
    	String [] strings = timeMap.get(startStation+endStation).split(" ");
    	return  Integer.parseInt(strings[0])*1.0/Integer.parseInt(strings[1]);
    }
}
```
用三个map
一个乘客map<id,string(stationName+" "+t)>
一个记录总时间map<startStation+endStation,总时间>
一个记录总次数map<startStation+endStation,总次数>，这样时间会少一点点，内存会多一点点.如图
![2.png](https://pic.leetcode-cn.com/b99b1e4ae3cad037c3d05f47f641a7c8a8a191bab928eb2eee2c39700cf0d1a0-2.png)
下面是代码
```
class UndergroundSystem {
    Map<Integer, String> midMap ;
    Map<String, Integer> timeMap;
    Map<String, Integer> numMap;
    public UndergroundSystem() {
    	midMap=new HashMap<>();
    	timeMap=new HashMap<>();
    	numMap=new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
    	midMap.put(id, stationName+" "+t);
    }
    
    public void checkOut(int id, String stationName, int t) {
    	String [] str =midMap.get(id).split(" ");
    	if (timeMap.containsKey(str[0]+stationName))
		{
    		timeMap.put(str[0]+stationName, timeMap.get(str[0]+stationName)+t-Integer.parseInt(str[1]));}
    	else {
    		timeMap.put(str[0]+stationName, t-Integer.parseInt(str[1]));
		}
    	if (numMap.containsKey(str[0]+stationName))
		{
    		numMap.put(str[0]+stationName, numMap.get(str[0]+stationName)+1);
		}else {
			numMap.put(str[0]+stationName, 1);
		}
    }
    
    public double getAverageTime(String startStation, String endStation) {
    	return  timeMap.get(startStation+endStation)*1.0/numMap.get(startStation+endStation);
    }
}
```



感谢MasssAA同学的思路
