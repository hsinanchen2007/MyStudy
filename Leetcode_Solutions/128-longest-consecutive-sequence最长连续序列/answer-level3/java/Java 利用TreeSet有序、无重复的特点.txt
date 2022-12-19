### 解题思路
TreeSet底层是二叉树,可以对对象元素进行排序

### 代码

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length<2){
            return  nums.length;
        }
         Set<Integer> set =new TreeSet();
	        for(int i:nums)
	            set.add(i);
	       
	        int ret=1;
	        for(int i:set){
////剪枝
	        	if(set.contains(i-1)){
	        		continue;
	        }
                 int len=1;
	        	while(set.contains(i+1)){
	        		i++;
	        		len++;
	        	}
	            ret=Math.max(ret, len);
	        }
	        return ret;
    }
}
```