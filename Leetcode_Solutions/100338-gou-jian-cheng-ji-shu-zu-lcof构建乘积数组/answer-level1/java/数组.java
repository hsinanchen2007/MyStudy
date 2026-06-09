### 解题思路
这个之前做过，就是记录a[i]左边乘积数组和右边乘积数组，然后做乘法就好了。

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        if(a.length == 0)
            return new int[0];
        
        int[] left = new int[a.length];
        int[] right = new int[a.length];
        int[] res = new int[a.length];
        left[0] = 1;right[a.length-1] = 1;

        for(int i = 1; i < a.length; i++){
            left[i] = left[i-1] * a[i-1];
        }
        for(int i = a.length - 2; i >= 0; i--){
            right[i] = right[i+1] * a[i+1];
        }

        for(int i = 0; i < res.length; i++){
            res[i] = left[i] * right[i];
        }

        return res;
    }
}
```