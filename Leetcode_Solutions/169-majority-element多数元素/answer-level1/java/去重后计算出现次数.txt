### 解题思路
1 对数组元素去重过滤
2 使用双重循环依次计算每个元素在原数组中出现的次数
3 次数大于n/2的即返回

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int[] ints = Arrays.stream(nums).distinct().toArray();
        for (int anInt : ints) {
            int count = 0;
            for (int num : nums) {
                if (anInt == num) count++;
            }
            if (count > nums.length /2)
            return anInt;
        }
        return 0;
    }
}
```