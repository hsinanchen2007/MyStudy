### 解题思路
数字都在0~n-1的范围，并且题目是只要找出任意重复的即可。
所以我们可以记录下每个数组出现的次数，如果该数字之前出现过，则直接返回即可。
记录数字出现的方式可以通过未操作来实现，即设置一个n长度的数组bits，bits[n]用来记录数字n出现的次数

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int size = nums.length;
        int[] bits = new int[size];
        int num = 0;
        for(int i = 0; i < size; i++) {
             num = nums[i];
             bits[num]++;
            if(bits[num] > 1){
                break;
            }
        }
        return num;
    }
}
```