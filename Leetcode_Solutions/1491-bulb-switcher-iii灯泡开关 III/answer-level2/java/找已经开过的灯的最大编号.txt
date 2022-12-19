### 解题思路
直接看注释吧，看题看了我好久

### 代码

```java
class Solution {
    public int numTimesAllBlue(int[] light) {
        int result = 0;
        int lastLight = 1;//开的最靠后的一盏灯的编号，就是开灯的下标的最大值，这里初始化为1保证第一次开灯是第一盏灯也变蓝
        for(int i=0;i<light.length;i++){
            lastLight = Math.max(light[i],lastLight);
            if(lastLight == i+1){//最开的最靠后的一盏灯的编号比index大1，那么就保证了lastLight和它之前的灯都被打开了，所以这些灯都变蓝了
                result++;
            }
        }
        return result;
    }
}
```