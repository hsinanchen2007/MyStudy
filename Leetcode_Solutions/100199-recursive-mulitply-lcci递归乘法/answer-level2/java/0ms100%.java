### 解题思路
用两个数中较大的数作为底数，迭代次数为较小的数

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        int max=Math.max(A,B);
        int min=Math.min(A,B);
        return helper(max,min);
    }
    private int helper(int num,int times){
        if (times==0)
            return 0;
        return num+helper(num,times-1);
    }
}
```