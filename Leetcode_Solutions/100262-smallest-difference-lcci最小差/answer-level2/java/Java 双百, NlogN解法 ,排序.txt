### 解题思路
![image.png](https://pic.leetcode-cn.com/528fa27eabf5c5426a8996701b9edaeb56ce06f04f81d5081aeb47ffc647fefa-image.png)

排序处O(nlogn)
后面循环O(n)
双指针
左<右时 左++到大于
之后比较临界值大小

### 代码

```java
class Solution {
    public int smallestDifference(int[] a, int[] b) {
    	long min =  Integer.MAX_VALUE;
    	int aP = 0;
    	int bP = 0;
    	Arrays.parallelSort(a);
    	Arrays.parallelSort(b);
    	while(aP<a.length && bP<b.length) {
    		if(min == 0)return 0;
    		if(a[aP]<b[bP]) {
    			while(aP<a.length &&a[aP]<b[bP]) {
        			aP++;
        		}
    			if(aP<a.length) {
    				min = Math.min(min, Math.abs((long)a[aP]-b[bP]));
            		
    			}
                min = Math.min(min, Math.abs((long)a[aP-1]-b[bP]));
        		
    		}else if(a[aP]>=b[bP]) {
    			while(bP<b.length &&a[aP]>b[bP]) {
        			bP++;
        		}
    			if(bP<b.length) {
    				min = Math.min(min, Math.abs((long)a[aP]-b[bP]));
    				
    			}
                min = Math.min(min, Math.abs((long)a[aP]-b[bP-1]));
    		}
    		
    		
    	}
    	return (int)min;
    }
}
```