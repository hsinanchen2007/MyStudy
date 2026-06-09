### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        if(a.length == 0){
            return a;
        }
        int len = a.length;
        int [] b = new int[len];
        b[0] = 1;
        //这里算出了b[i]的前i-1个数的乘积
        for(int i = 1; i < len; i++){
            b[i] = b[i-1]*a[i-1];
        }
        int tmp = 1;
        //tmp是b[i]后面的len-i个数的乘积
        for(int i = len - 2; i >= 0; i--){
            tmp *= a[i+1];
            //合并得乘积数组
            b[i] *= tmp;
        }
        return b;
    }
}
```