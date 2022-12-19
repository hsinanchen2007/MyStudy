### 解题思路
此处撰写解题思路
这题主要的思想是，遍历这个数组，如果到下标i为止的数组里最大值等于下标加1，则表示左边的灯都全亮了，不相等说明目前的这个最大值在当前目标值的右侧还需要继续遍历
### 代码

```java
class Solution {
    public int numTimesAllBlue(int[] light) {
        int m = 1, count = 0;
        for(int i = 0; i < light.length; i++){
            m = Math.max(light[i],m);
            if(m == i+1)
                count++;
        }
        return count;
    }
}
```