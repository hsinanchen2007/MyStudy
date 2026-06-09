代码写的比较乱，因为尽可能减少直接拼接字符串浪费时间空间 可以算是又臭又长
```
class Solution {
  Map<Integer, String> map; Map<Integer, String> danwei;
	Solution(){
	map=new HashMap<Integer, String>();
		   map.put(100, "Hundred");map.put(90, "Ninety");map.put(80, "Eighty");map.put(70, "Seventy");
		   map.put(60, "Sixty");map.put(50, "Fifty");map.put(40, "Forty");map.put(30, "Thirty");
		   map.put(20, "Twenty");map.put(19, "Nineteen");map.put(18, "Eighteen");map.put(17, "Seventeen");
		   map.put(16, "Sixteen");map.put(15, "Fifteen");map.put(14, "Fourteen");map.put(13, "Thirteen");
		   map.put(12, "Twelve");map.put(11, "Eleven");map.put(10, "Ten");map.put(9, "Nine");
		   map.put(8, "Eight");map.put(7, "Seven");map.put(6, "Six");map.put(5, "Five");
		   map.put(4, "Four");map.put(3, "Three");map.put(2, "Two");map.put(1, "One");map.put(0, "Zero");
		 danwei=new HashMap<Integer, String>();
		   danwei.put(1000000000, "Billion");      danwei.put(1000000, "Million");    danwei.put(1000, "Thousand");
	}

	    public String numberToWords(int num) {
		   if(num==Integer.MIN_VALUE) {
			   return "Negative Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Eight";
		   }
  
   StringBuilder res=new StringBuilder();
   if(num<0) {num=-num;res.append("Negative ");}
   if(num<100) {
	   if(map.containsKey(num)) {return res+map.get(num);}
	   res.append(map.get(num/10*10));res.append(" ");res.append(map.get(num%10));
		   return res.toString();
   }
   if(num<1000) {
	   if(num%100==0) {
		    res.append(map.get(num/100));res.append(" ");res.append(map.get(100));
		   return res.toString();
		   }
	   res.append(map.get(num/100));res.append(" ");res.append(map.get(100));res.append(" ");res.append(numberToWords(num%100));
	   return res.toString();
   }
   if(num<1000000) {
	   if(num%1000==0) {
		   res.append(numberToWords(num/1000));res.append(" ");res.append(danwei.get(1000));
		   return res.toString();
	   }
	   res.append(numberToWords(num/1000));res.append(" ");res.append(danwei.get(1000));res.append(" ");res.append(numberToWords(num%1000));
	   return res.toString();
   }
   if(num<1000000000) {
	   if(num%1000000==0) {
		  res.append(numberToWords(num/1000000));res.append(" ");res.append(danwei.get(1000000));
		   return res.toString();
		   }
	   res.append(numberToWords(num/1000000));res.append(" ");res.append(danwei.get(1000000));res.append(" ");res.append(numberToWords(num%1000000));
	   return res.toString();
   }
   if(num%1000000000==0) {
	 res.append(numberToWords(num/1000000000));res.append(" ");res.append(danwei.get(1000000000));
	   return res.toString();
	   }
   res.append(numberToWords(num/1000000000));res.append(" ");res.append(danwei.get(1000000000));res.append(" ");res.append(numberToWords(num%1000000000));
   return res.toString();
	    }
}
```
测试用例居然没有MIN_VALUE真是出乎意料
