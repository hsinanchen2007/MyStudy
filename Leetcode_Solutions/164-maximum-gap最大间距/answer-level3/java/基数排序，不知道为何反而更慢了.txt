执行结果：
通过
显示详情
执行用时 :
25 ms
, 在所有 Java 提交中击败了
8.86%
的用户
内存消耗 :
43.2 MB
, 在所有 Java 提交中击败了
5.26%
的用户
```
class Solution {
     public int maximumGap(int[] nums) {
	        int len = nums.length;
	        if(len<2)return 0;
	        
	        int x=10;
	        
	        int m=0;
	        for(int i=0;i<len; i++){
	            if(nums[i]>m){
	                m=nums[i];
	            }
	        }
	        List<Integer> nn = new ArrayList<>(len);
	        List<Integer>[] xs = new ArrayList[10];
	        List<Integer>[] xs2 = new ArrayList[10];
	        List<Integer>[] xs3 = new ArrayList[10];
	        for(int i=0;i<10;i++){
	            xs[i]=new ArrayList<Integer>();
	            xs2[i]=new ArrayList<Integer>();
	        }
	         for(int i=0;i<len; i++){
	            xs[nums[i]%10].add(nums[i]);
	        }
	        int index=0;
	        while(m>0){
	        	xs3 = new ArrayList[10];
	        	 for(int i=0;i<10;i++){
	 	            xs3[i]=new ArrayList<Integer>();
	 	        }
	            for(int i=0;i<10;i++){
	            	
	                Iterator<Integer> it = xs[i].iterator();
	                while(it.hasNext()){
	                    int ii = it.next();
	                    if(ii/x==0){
	                        xs2[ii/(x/10)%10].add(ii);
	                    }else {
	                    	xs3[ii/(x/10)%10].add(ii);
	                    	
	                    }
	                }
	            }
                for(int i=0;i<10;i++){
	                xs[i].clear();
	            }
	            xs=xs3;
	            for(int i=0;i<10;i++){
	                nn.addAll(xs2[i]);
	                xs2[i].clear();
	            }
	           x=x*10;
	           m = m/10;
	        }
	        int max=0;
	        for(int i=1;i<len; i++){
	            if(nn.get(i)-nn.get(i-1)>max){
	                max=nn.get(i)-nn.get(i-1);
	            }
	        }
	        return max;
	    }
}
```
