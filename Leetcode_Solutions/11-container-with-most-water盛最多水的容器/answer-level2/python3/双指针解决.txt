```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0;
        j = len(height) - 1
        area = (min(height[i], height[j])) * (j - i)
        while i < j:
            if height[i] < height[j]:
                i += 1
                area = max(area, (min(height[i], height[j])) * (j - i))
            else:
                j -= 1
                area = max(area, (min(height[i], height[j])) * (j - i))
        return area
```
java解决
```
class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int area = (Math.min(height[i], height[j])) * (j - i);
        while(i < j) {
            if(height[i] < height[j]) {
                i++;
                area = Math.max(area, (Math.min(height[i], height[j])) * (j - i));
            }
            else {
                j--;
                area = Math.max(area, (Math.min(height[i], height[j])) * (j - i));
            }
        }
        return area;
    }
}
```

