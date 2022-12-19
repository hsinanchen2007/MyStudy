### 解题思路
    典型的双指针思路，问题的关键点在于怎样移动才能不至于在移动的过程中错过正确答案，方法是移动过的时候，移动较短的边，因为这样最有可能增加容器的容量。
### 代码

```java
class Solution {
    public int maxArea(int[] height) {
           int max_vol=0;
	  int c1=0;
	  int c2=height.length-1;
	  int h=height[c1]<=height[c2]? height[c1]:height[c2];
	  max_vol=(c2-c1)*h;
	  int vol;
	  while(c1<c2)
	  {
		  if(height[c2]>=height[c1]) c1++;
		  else c2--;
		  h=height[c1]<=height[c2]? height[c1]:height[c2];
		  vol=h*(c2-c1);
		  if(vol>max_vol) max_vol=vol;
	  }
	  return max_vol;
    }
}
```