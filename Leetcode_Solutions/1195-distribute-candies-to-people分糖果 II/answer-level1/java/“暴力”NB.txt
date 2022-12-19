### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] num = new int[num_people];
    	int i = 0;
    	while(candies!=0) {
    		//每次分多少？Math.min(candies, i+1)
    		num[i%num_people] += Math.min(candies, i+1);
    		candies -= Math.min(candies, i+1);
    		i++;
    	}
    	
    	return num;
    }
}
```