### 解题思路
不明白这题考察的是什么

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        //数组分为三部分
        //bad-case
        if (A.length < 3) {
            return false;
        }

        //遍历一遍 求和
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
        }

        //不能均分
        if (sum%3 != 0) {
            return false;
        }

        //分组的值
        int itemSum = 0;

        //分组的次数
        int index = 0;

        //再次遍历数组
        for (int i = 0; i < A.length; i++) {
            itemSum += A[i];
            if (itemSum == sum/3) {
                index++;
                itemSum = 0;
            }
        }

        
        if (index >= 3) {
            return true;
        }

        return false;
    }
}
```