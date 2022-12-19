### 解题思路
sizeOfInt函数判断整型位数用于迭代次数，每次取模更新6的位次，最后最大位次加上差值即最大数字

### 代码

```java
class Solution {
    final static int[] sizeTable = { 9,99,999,9999,99999,999999,9999999,
                        99999999,999999999,Integer.MAX_VALUE};    
    static int sizeOfInt(int x) {    
        for (int i = 0; ; i++){
            if (x <= sizeTable[i]){
                return i + 1;
            }
        }
    } 

    public int maximum69Number (int num) {
        int digits = sizeOfInt(num);
        int variate = num;
        // 记录6最高的位次
        int index = -1;
        for(int i=0; i<digits; i++) {
            int cow = variate % 10;
            variate /= 10;
            if(cow == 6) {
                index = i;
            }
        }
        if (index == -1) {
            return num;
        } else {
            return num + 3 * (int) Math.pow(10, index);
        }
    }
}
```