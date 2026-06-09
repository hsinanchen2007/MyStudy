### 解题思路
1. 首先去除前导0，因为肯定不能接水
2. 然后计算雨水：
    即，使用max记录当前为止最高的高度，当存在比其小的高度时累加，表示可能能接到这么多雨水。
    最终的max记录了整个数组中最长高度
3. 最后计算去除不能接到的雨水
    由于可能后面的高度都比最高高度小，那么就存在前面多接了的情况
    此时，从后面遍历，删除不能接的雨水数量
下图为简略的概念图
 5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4  
|----|
|&nbsp;&nbsp;&nbsp;&nbsp;|——-|---|
|&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;|---|&nbsp;&nbsp;&nbsp;&nbsp;|
|&nbsp;&nbsp;&nbsp;&nbsp;|---|&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;|
|&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;|

经过第一步得到的结果为：result = 3 + 2 + 1；max = 5；
经过第二步从后往前遍历：result = result - 1 - 1 - 1；（即减去3次 5-4 的高度）。 

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int result = 0;
        int i = 0;
        int max = 0;
        //去除前导0
        while(i < height.length && height[i] == 0)i++;
        if(i == height.length) return 0;
        max = height[i];
        i++;
        //计算雨水
        while(i < height.length){
            if(height[i] < max){
                result += max - height[i];
            }else{
                max = height[i];
            }
            i++;
        }
        //减去不能接的雨水
        i = height.length - 1;
        while(i >= 0){
            if(height[i] == max) break;
            int curr_max = height[i];
            while(i >= 0 && curr_max >= height[i]){
                result -= max - curr_max;
                i--;
            }
        }
        return result;
    }
}
```