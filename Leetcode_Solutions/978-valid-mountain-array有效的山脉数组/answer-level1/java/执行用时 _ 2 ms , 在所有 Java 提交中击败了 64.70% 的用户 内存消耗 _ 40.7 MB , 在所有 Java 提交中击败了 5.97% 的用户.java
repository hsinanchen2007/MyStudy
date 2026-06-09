### 解题思路
本题思路并不复杂，关键在于下标位置的取舍，这是一个大的问题，一定要理解清楚i的位置在什么位置判断什么情况

### 代码

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        if(A.length<3) return false;
        int i = 0;
        for(;i<A.length-1;i++) {
            if(A[i]>=A[i+1]) {
                break;
            }
        }
        if(i==A.length-1 || i==0) {
            return false;
        }
        for(;i<A.length-1;i++) {
            if(A[i]<=A[i+1]) {
                return false;
            }
        }
        return true;

        
    }
}
```