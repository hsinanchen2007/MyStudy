暴力如下：
初始想法：基本思想，先找出最低的柱子和最高的柱子，然后依次从最低柱子的值到最高柱子值遍历。将各个高度对应的矩形面积算出来，取其最大值。算各个高度的最大矩形面积时，需要找出不低于该高度的最大连续柱子个数作为矩形长度

后来想法：但考虑到，可能存在一枝独秀很高的柱子，这个最低柱子值到最高柱子值之间的遍历范围巨大。这里采用基数排序将各个柱子排好序后，依次从低到高以各个柱子的高度为最低高度（重复的跳过）算各个高度柱子的矩形面积
```
class Solution {
	private int[] heights;
	private int[] a;  //sorted array
    public int largestRectangleArea(int[] heights) {
    	if(heights.length == 0) return 0;
    	
    	this.heights = heights;
    	sort(heights);
    	int s = a[0]*heights.length;
    	for(int i = 1; i < a.length; i++) {
    		if(a[i] == a[i-1]) {
    			continue;
    		}
    		int maxContinuePiece = maxContinuous(a[i]);
    		if(s < maxContinuePiece*a[i]) {
    			s = maxContinuePiece*a[i];
    		}
    	}
    	return s;
    }
    //找出高度不低于minHeight的连续柱子最长个数
    private int maxContinuous(int minHeight) {
    	int begin = 0,end = 0,count = 1;
    	boolean beginFlag = false;
    	for(int i = 0; i < heights.length; i++) {
    		if(heights[i] >= minHeight) {
    			if(!beginFlag) {
    				begin = i;
    				beginFlag = true;
    			}
    			end = i;
    		} else {
    			if(count < end-begin+1) {
    				count = end-begin+1;
    			}
    			begin = i;
    			end = i;
    			beginFlag = false;
    		}
    		if(i == heights.length - 1) {
    			if(count < end-begin+1) {
    				count = end-begin+1;
    			}
    		}
    	}
    	return count;
    }
    private void sort(int[] arr) {
		a = new int[arr.length];
		
		int[] h = new int[arr.length];
		int[] barrel0 = new int[256],barrel1 = new int[256],barrel2 = new int[256],barrel3 = new int[256];
		for (int i = 0; i < arr.length; i++)
		{	
			a[i] = arr[i];
	    	++barrel0[a[i]&0b11111111];
	    	++barrel1[(a[i]>>8)&0b11111111];
	    	++barrel2[(a[i]>>16)&0b11111111];
	    	++barrel3[a[i]>>24];
		}
		for(int i = 1; i < 256; i++) {
			barrel0[i] += barrel0[i-1];
			barrel1[i] += barrel1[i-1];
			barrel2[i] += barrel2[i-1];
			barrel3[i] += barrel3[i-1];
		}
		for(int i = a.length-1; i >= 0; i--) {
			h[--barrel0[a[i]&0b11111111]] = a[i];
		}
		for(int i = a.length-1; i >= 0; i--) {
			a[--barrel1[(h[i]>>8)&0b11111111]] = h[i];
		}
		for(int i = a.length-1; i >= 0; i--) {
			h[--barrel2[(a[i]>>16)&0b11111111]] = a[i];
		}
		for(int i = a.length-1; i >= 0; i--) {
			a[--barrel3[h[i]>>24]] = h[i];
		}
	}
}
```
