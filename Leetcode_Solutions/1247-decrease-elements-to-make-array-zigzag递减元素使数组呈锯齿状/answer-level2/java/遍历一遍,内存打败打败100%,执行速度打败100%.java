

class Solution {
    public int movesToMakeZigzag(int[] nums) {
            
      	int start = 0; //凸
    	int end = 0; //凹
    	
    	for(int i =1 ; i< nums.length; i=i+2) {
    		 int rigth = Integer.MAX_VALUE;
       		 int left = Integer.MAX_VALUE;
       	//凹
       
       		 
       		
       		 
       		 
    		//凸右边
    		if ((i+1) < nums.length) {
    			 //凸:右边大则需要调整
    			if( nums[i+1] - nums[i] >=0) {
    				start = start +nums[i+1] - nums[i]+1;
    			}
    	         
    			rigth = nums[i+1];
               
    		
    		
    		}
    		
    		//左边第1
    		if (i==1) {
    			//凸:左边大则需要调整
                if( nums[i-1] - nums[i] >=0) {
    				
    				start = start +nums[i-1] - nums[i]+1;
    			}
 
    			
    			
    		}
    		//左邊
    		if (i>1) {
    			
    			
    			//凸:当前大于前两位,肯定不用调整
               if( nums[i] - nums[i-2] <=0) {
            	 //nums[i]>nums[i-1]]不用调整
   				 if(nums[i]<=nums[i-1] ) {
   				    if(nums[i-2]>nums[i-1]) { //沒有調整
   				    	start = start + nums[i-1]- nums[i] +1; 
   				    }else {
   				    	start = start + nums[i-2]- nums[i]; 	
   				    }
   					 
   			
   				  }
               }
    			
    		}
    		// 凹
    		left= nums[i-1];
            if(nums[i]>=Math.min(rigth, left)) {
            	end = end +   nums[i] -  Math.min(rigth, left)  +1;
            }
          
    		
    		
    	
    	
    	
    	}
    	
    	
    	
    	return Math.min(start, end);
    }
}