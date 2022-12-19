### 解题思路
边界问题，这里转换成long了

### 代码

```java
class Solution {
    public String fractionToDecimal(int numerator1, int denominator1) {
		StringBuilder sb = new StringBuilder();
		long numerator = numerator1;
		long denominator = denominator1;
		if(numerator*denominator<0){
			sb.append("-");
			
		}
		numerator=Math.abs(numerator);
		denominator=Math.abs(denominator);
		sb.append(numerator/denominator);
		
		long yu = numerator%denominator;
		
		if(yu>0){
			sb.append(".");
			Map<Long, Integer> id_map = new HashMap<Long, Integer>();
			id_map.put(yu, sb.length());

			while(true){
				
				yu *=10;
				
				
				
				long append = yu/denominator;
				sb.append(append);
				
				yu = yu%denominator;
				if(yu ==0){
					break;
				}
				if(id_map.containsKey(yu)){
					//循环
					sb = new StringBuilder(sb.subSequence(0,id_map.get(yu))+"("+sb.substring(id_map.get(yu))+")");
					break;
				}else{
					
					id_map.put(yu, sb.length());
					//continue;
				}
			}
		}
		
		return sb.toString();
	}
}
```