![2020011901.PNG](https://pic.leetcode-cn.com/cf9d48ccb051ab157ce3378b7e480d904d5060bc4d324ee6c16ec682b693a162-2020011901.PNG)
### 解题思路
//先遍历一遍数组grumpy,当grumpy[i]的值为0时,out加上customers[i]的值,并将该customers[i]重新置为0;
//再遍历一遍数组customers,用滑动窗口来计算customers数组中的连续X个数之和(记为sum),并且用max记录当前出现的最大的sum;
//最后返回(out+max)
### 代码

```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        //解1：耗时3ms
    	int out = 0;
    	int max = 0;
    	int sum = 0;
    	for(int i =0;i<grumpy.length;i++) {
    		if(grumpy[i]==0) {
    			out += customers[i];
    			customers[i] = 0;
    		}
    	}
    	int i=0;
    	while(i<customers.length) {
    		sum += customers[i];
    		if(i>=X-1) {
        		if(sum >= max) {
        			max = sum;
        		}
				sum -= customers[i-X+1];//窗口长度为X,窗口在向前滑动一位之前,需要将窗口中的最左边的一位数减掉
    		}
    		i++;
    	}
        return out+max;
    }
}
```