### 解题思路
此处撰写解题思路

### 代码

```java

class Solution {
   public static int maxProfit(int[] prices) {
	        List<Integer> temp = new ArrayList<Integer>();

	        for(int i=0;i<prices.length;i++){
	            for(int j=i+1;j<prices.length;j++){
	                int a=(prices[i]-prices[j]);
	                if(a<0){
	                    temp.add(Math.abs(a));
	                }
	            }
	        }

	        if(temp.size()>0){
	            return Collections.max(temp);
	        }
	        
	        return 0;
	    }
}
```