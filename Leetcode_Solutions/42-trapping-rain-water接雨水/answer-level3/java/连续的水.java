### 解题思路

找出能形成的连续的“水槽”的两根柱子，先选取第一根柱子，第二根柱子就是那个比他高或是和他一样高的那根。这样的两根柱子之间的雨水就很好计算了，就是水的高度（两根柱子中短的那根的高度）减去其之间每根柱子的高度的和。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int rainCount = 0;
        for (int i=0;i<height.length;) {
            int waterHeight = height[i];
            if (waterHeight == 0) {
            	i++;
                continue;
            }
            boolean hasHigher = false;
            while (!hasHigher) {
            	for (int j = i+1; j<height.length; j++) {
            		if (height[j] >= waterHeight) {
            			for (int k=i + 1;k<j;k++) {
                            rainCount += waterHeight - height[k];
                        }
            			
            			i = j;
            			hasHigher = true;
            			break;
            		}
            	}
            	if (!hasHigher) {
            		waterHeight = waterHeight - 1;
            		if (waterHeight == 0) {
            			i = height.length;
						break;
					}
            	}
			}
        }
        return rainCount;
    }
}
```