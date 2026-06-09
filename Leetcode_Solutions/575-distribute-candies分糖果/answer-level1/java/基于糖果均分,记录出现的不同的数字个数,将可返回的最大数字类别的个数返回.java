![2019122601.PNG](https://pic.leetcode-cn.com/42c9e5158fd5f915ca73ab3a30b8847eaa9524437b88b0413b73f3ee9bc2de4d-2019122601.PNG)
### 解题思路
因为糖果是平均分配的,
若果糖果的种类数(count记录不同的数组个数)大于总糖果数的一半,则返回总糖果数的一半
如果count小于糖果数的一半,则返回count
### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        Map<Integer,Integer> myHash = new HashMap<>();
    	int count = 0;
    	for(int i =0;i<candies.length;i++) {
    		if(!myHash.containsKey(candies[i])) {
    			myHash.put(candies[i], 0);
    			count ++;
                if(count>(candies.length>>1)) {
    		        return candies.length>>1;
    	        }
    		}
    	}
        return count;
    }
}
```