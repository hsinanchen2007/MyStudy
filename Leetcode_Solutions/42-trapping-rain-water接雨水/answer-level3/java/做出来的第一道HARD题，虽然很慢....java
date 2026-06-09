### 解题思路
做出来的第一道HARD题，虽然很慢...

### 代码

```java
class Solution {
    public int trap(int[] height) {
    	int ans = 0;
    	for (int i = 1; i < height.length-1; i++) {   //两端的不考虑，不会积水
			
    		int leftMax=height[0];               //分别找左右两边的最大值
    		for (int j = 1; j < i; j++) {
				leftMax=height[j]>leftMax?height[j]:leftMax;    //注意动态比较
			}
    		//System.out.println("leftMax:"+leftMax);
    		
    		int rightMax=height[height.length-1];
    		for (int j = height.length-2; j >i; j--) {
				rightMax=height[j]>rightMax?height[j]:rightMax;
				//System.out.println("j:"+j);
	    		//System.out.println("rightMax:"+rightMax);
			}
    		//System.out.println("rightMax:"+rightMax);
    		
    		if (Math.min(rightMax, leftMax)>height[i]) {    //只有当两个最大值中的最小值大于本体时才会积水
				ans+=Math.min(rightMax, leftMax)-height[i];  
			}
    		//System.out.println("ans:"+ans);
    		
		}
		return ans;
    }
}
```