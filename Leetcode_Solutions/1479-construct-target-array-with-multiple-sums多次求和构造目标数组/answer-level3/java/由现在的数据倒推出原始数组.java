### 解题思路
执行用时 :24 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :47.6 MB, 在所有 Java 提交中击败了100.00%的用户
1. 对数组排序时间复杂度是o(nlog(n))，超时。
2. 数组中有重复数字的话，则不可能是由其他数相加的结果，返回false；
3. 当前数组的最大值，是由当前数组的其他值+该位原来的值得到的，即，当前数组为[3, 5, 9]，则9 = 3 + 5 + x，x = 1, 原来的数组为[3, 5, 1]，不断的选取数组的最大值，知道最大值为1，判断数组是否满足[1, 1, 1, 1,..., 1],如果满足，返回true，否则，返回false，这个解有个bug，如果数组中有重复的数字的话，则会陷入死循环，所以需要增加flag，判断是否有重复的数字。

### 代码

```java
class Solution {
    public boolean isPossible(int[] target) {
        int len = target.length, sum = 0, maxIndex = 0, maxValue = 0, k = 0, flag = -1;
        while(true){
            for(int i = 0; i < len; i++){
                sum += target[i];
                if(target[i] > maxValue){
                    maxValue = target[i];
                    maxIndex = i;
                }
            }
            if(maxValue == 1) break;
            if(flag == maxValue) return false;
            target[maxIndex] = maxValue - (sum - maxValue);
            flag = maxValue;
            maxValue = 0;
            sum = 0;
            k++;
        }
        for(int i = 0; i < len; i++){
           if(target[i] != 1) return false;
        }
        return true;
    }
}
```