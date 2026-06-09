### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
        
        int[] ck = new int[2];
        ck[0] = area; ck[1] = 1;

        for(int width = 2; width <= (int)Math.sqrt(area); width++){
            if(area % width == 0){
                int height = area / width;
                if(height >= width && height - width < ck[0] - ck[1]){
                    ck[0] = height;
                    ck[1] = width;
                }
            }
        }
        return ck;
    }
}
```