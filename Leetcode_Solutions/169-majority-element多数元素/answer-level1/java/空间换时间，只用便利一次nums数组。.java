### 解题思路
思路是创建一个表，记录遍历出来数字，各出现了几次，最后选最多次数输出，空间换时间，只用便利一次nums数组。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
         int value[] = new int[nums.length/2+1];
	        int value2[] = new int[nums.length/2+1];
	        int len = 0;
	        for(int i=0;i<nums.length;i++){
	            boolean chongfu = false;
	            for(int i1=0;i1<len;i1++){
	            if(nums[i]==value[i1]){
	            chongfu=true;
	            value2[i1]++;
	            }
	                }
	                if(!chongfu){
	                    len++;
	                    value[len-1]=nums[i];
	                    value2[len-1]=1;
	                }
	         }
	       int max=-1;
	        int valuemax=0;
	        for(int i=0;i<value.length;i++){

	            if(value2[i]>max){
	             max=value2[i];
	                valuemax=value[i];
	            }

	        }
	        return valuemax;
    }
}
```