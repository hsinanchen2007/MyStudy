### 解题思路
可以先排序，排序完成了之后，来进行这个数数，然后查看什么时候最大，得到索引，然后就返回得到索引最大的值。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        // Arrays.sort(nums);写代码就需要手写代码
        int indexI,indexJ,valueK;
        for(indexI=1;indexI<nums.length;indexI++){
            valueK = nums[indexI];
            for(indexJ = indexI-1;indexJ>=0&&nums[indexJ]>valueK;indexJ--){
                nums[indexJ+1]=nums[indexJ];
            }
            if(indexI!=indexJ+1){
                nums[indexJ+1] = valueK;
            }
            
        }
        
        
    	int temp[]=new int[nums.length];
    	int a = nums[0];
    	temp[0]=1;
    	for (int i = 1; i < temp.length; i++) {
    		if(a == nums[i]) {
    			temp[i]=temp[i-1]+1;
    		}else {
    			a=nums[i];
    			temp[i]=1;
    		}
		}
    	int maxIndex  = Integer.MIN_VALUE;
    	
    	for (int i = 0; i < temp.length; i++) {
			if(maxIndex<temp[i]) {
				maxIndex = i;
			}
		}
    	return nums[maxIndex];
    	

    }
}
```