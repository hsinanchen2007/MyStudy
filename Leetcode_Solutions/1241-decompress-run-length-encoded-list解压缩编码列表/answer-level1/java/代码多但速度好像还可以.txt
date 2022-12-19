### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {

    int count [] = new int [nums.length/2+nums.length%2];
	        int digital [] = new int [nums.length/2+nums.length%2];
	        
	        int total = 0;

	        for (int i = 0;i<count.length;i++){
	           count[i] = nums[i*2];
	        }

	        for (int i = 0;i<digital.length;i++){
	           digital[i] = nums[i*2+1];
	        }
	        
	        for(int i= 0 ;i<count.length;i++)
	        {
	        	total +=count[i];
	        }
	        
	        int result [] = new int [total];
	        
	        int cnt = 0;
            for(int k=0;k<nums.length/2;k++) {
             for(int i=0;i<count[k];i++) {
            	 result[cnt] = digital[k];
            	 cnt++;
             }
            }
	        
	        return result;
    }
}
```