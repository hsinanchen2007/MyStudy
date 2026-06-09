### 解题思路
先求和，和不能被3整除直接返回false
将和除以3，得到每部分的和
用一个数组存储前两段的和，先遍历并累加第一段的和直到其等于计算得出的和。再遍历累加第二段，以此类推。如果提前遍历至终点或者累加得出的和与计算出的不等，返回false，否则返回true。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i : A) sum += i;
        if(sum % 3 != 0) return false;
        int part = sum / 3;
        int[] sums =  new int[2];
        int index = 0;
        for(int i = 0; i < 2; ++i){
            while(index < A.length - 1){
                sums[i] += A[index];
                ++index;
                if(sums[i] == part) break;
            }
            if(index == A.length - 1 && (i != 1 || sums[i] != part)) return false;
        }
        return true;
    }
}
```