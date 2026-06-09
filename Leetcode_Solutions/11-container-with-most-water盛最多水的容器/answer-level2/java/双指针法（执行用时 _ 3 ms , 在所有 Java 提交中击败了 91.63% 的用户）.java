### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int maxArea(int[] height) {
        if(height==null||height.length==1){
            return 0;
        }

        int head = 0;
        int rear = height.length-1;
        int max = 0;
        while(head<rear){
            int area = Math.min(height[head], height[rear]) * (rear - head);
            if(area>max){
                max = area;
            }
            if(height[head]<height[rear]){
                head++;
            }else{
                rear--;
            }
        }
        return max;
    }
}
```