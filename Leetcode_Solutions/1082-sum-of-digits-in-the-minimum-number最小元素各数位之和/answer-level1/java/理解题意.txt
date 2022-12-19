### 解题思路


### 代码

```java
class Solution {
    public int sumOfDigits(int[] A) {
        Arrays.sort(A);
        int min = A[0];
        int sum = 0;
        while(min!=0){
            sum += min%10;
            min /= 10;
        }
        return sum%2==0?1:0;
    }
}
```