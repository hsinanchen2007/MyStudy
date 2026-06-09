### 解题思路
此处撰写解题思路
从前先后遍历,每个元素（最后一个元素除外），向后找第一个大于它的数，记录下表，并输出
### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        //从前先后遍历,每个元素（最后一个元素除外），向后找第一个大于它的数，记录下表，并输出
        int length = T.length;
        int [] res = new int[length];
        for(int i=0;i<length;i++) {
            for(int j=i+1;j<length;j++) {
                if(T[j]>T[i]) {
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
}
```