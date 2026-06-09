### 解题思路
好慢的说，硬解
### 代码
```java
class Solution {
    public int thirdMax(int[] nums) {
        List<Integer> sortsA= new ArrayList<>();
		int num=0;
		for(int i=0;i<nums.length;i++) {
			if(sortsA.indexOf(nums[i])==-1) 
			{	
				sortsA.add(nums[i]);
				num++;
			}
		}
		Integer[] Aa=sortsA.toArray(new Integer[sortsA.size()]);
		Arrays.sort(Aa);
        if (num<3){
	            return Aa[num-1];
	        }
			return Aa[num-3];
    }
}
```