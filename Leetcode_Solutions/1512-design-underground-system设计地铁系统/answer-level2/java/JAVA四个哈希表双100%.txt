翻译题意就行 很简单
比赛的时候一直卡在最后一个测试点
一直以为是小数点的问题
后来在 return的时候 多乘上 0.1 就过了
现在想想可能之前是 return的是两个整数做除法
还是不够细
卡在51个测试点的朋友们 乘上0.1就可以过啦！```
代码块
class UndergroundSystem {
    public static Map<Integer, Integer> im;
	public static Map<Integer, Integer> om;
	public static Map<String, Integer> zm;
	public static Map<Integer, String> is;
	public static Map<String, Integer> cm;
    public UndergroundSystem() {
             im = new HashMap<>();
		 om = new HashMap<>();	
		 zm = new HashMap<>();
		 is = new HashMap<>();
		 cm = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
            im.put(id, t);
		is.put(id, stationName);
    }
    
    public void checkOut(int id, String stationName, int t) {
        om.put(id, t);
		//从im找
		int it = im.get(id);//拿到了进站时间
		int spend = t - it;//画的时间
		String ins = is.get(id);//进入的站名
		String d = ins + stationName;//组合后的站名
		//我要的是统计 组合站名一共有几次
		if(cm.containsKey(d)){
			cm.put(d, cm.get(d) + 1);//更新数量
		}else{
			cm.put(d, 1);
		}
		
		if(zm.containsKey(d)){
			zm.put(d, zm.get(d) + spend);
		}else{
			zm.put(d, spend);
		}
    }
    
    public double getAverageTime(String startStation, String endStation) {
        	String k = startStation + endStation;
		//double res = zm.get(k) / cm.get(k);
		//String s = String.format("%.1f", res);
		return 1.0 * zm.get(k) / cm.get(k);
    }
}
