### 解题思路
对面积开方，从中间往前找，i为宽，area/i为长，找到一个就结束循环

### 代码

```java
class Solution {
    public int[] constructRectangle(int area) {
        int[] ans = new int[2];
        for(int i = (int)Math.sqrt(area);i > 0 ;i--){
            if(i * (area/i) == area){
                ans[0] = area/i;
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
}
```