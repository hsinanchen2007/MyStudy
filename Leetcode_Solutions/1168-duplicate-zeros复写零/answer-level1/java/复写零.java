思路：1.判断一共有需要多少个空位可以为0提供复写空间，
     2.记录刨除复写空间后有多少个零需要复写
     3.然后从后往前遍历，如果需要复写的0大于复写空间，则靠后的0不进行复写
```
class Solution {
    public void duplicateZeros(int[] arr) {
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0 && i != len - 1) len --;
        }
        int nonPos = arr.length - len;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) count ++;
        }
        for (int i = len - 1; i >= 0 ; i--) {
            if(arr[i] == 0) {
                if(nonPos < count) {
                    arr[i + nonPos] = arr[i];
                    count --;
                } else {
                    arr[i + nonPos] = 0;
                    arr[i + nonPos - 1] = 0;
                    nonPos --;
                    count --;
                }
            } else {
                arr[i + nonPos] = arr[i];
            }
        }
    }
}
```
        