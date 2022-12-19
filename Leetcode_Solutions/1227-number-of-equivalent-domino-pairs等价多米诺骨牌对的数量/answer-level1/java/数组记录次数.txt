### 解题思路
数组记录次数

### 代码

```java
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] counts = new int[100];
        int result = 0;
        for(int[] dom : dominoes){
            if(dom[0]<dom[1]){
                counts[dom[0]*10+dom[1]]++;
            }else{
                counts[dom[1]*10+dom[0]]++;
            }
        }
        for(int count : counts){
            if(count>1){
                result += (count * (count-1))/2;
            }
        }
        return result;
    }
}
```