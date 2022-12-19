### 解题思路

待补充

### 代码

```java
class Solution {

    public void duplicateZeros(int[] arr) {
        //计算可以补0数量
        int fillZeroCount = 0;
        int lastFillIdx = 0;
        for(int i=0;i + fillZeroCount < arr.length; i++) {
            if(arr[i] == 0) {
                if(i + fillZeroCount + 1 < arr.length) {
                    fillZeroCount++;
                    lastFillIdx = i;
                }
            }
        }
        if(fillZeroCount == 0) {
            return;
        }
        //后边位置值都被舍弃
        int startIdx = arr.length - 1 - fillZeroCount;//包含
        int setIdx = arr.length-1;
        for(int j=startIdx; j != setIdx &&  j>=0; j--) {
            arr[setIdx] = arr[j];
            setIdx--;
            if(j<= lastFillIdx && arr[j] == 0){
                arr[setIdx] = 0;
                setIdx--;
            }
        }
        return;
    }
}
```