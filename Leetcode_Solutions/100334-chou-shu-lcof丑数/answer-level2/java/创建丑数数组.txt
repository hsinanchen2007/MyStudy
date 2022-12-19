
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] uglyArr = new int[n];
        uglyArr[0] = 1;
        int multiply2 = 0,multiply3 = 0,multiply5 = 0;
        for(int i=1;i < uglyArr.length;i++){
            int min = Math.min(Math.min(uglyArr[multiply2]*2,
            uglyArr[multiply3]*3),uglyArr[multiply5]*5);
            uglyArr[i] = min;
            if(uglyArr[multiply2]*2 == min) multiply2++;
            if(uglyArr[multiply3]*3 == min) multiply3++;
            if(uglyArr[multiply5]*5 == min) multiply5++;
        }
        return uglyArr[n-1];
    }
}
```