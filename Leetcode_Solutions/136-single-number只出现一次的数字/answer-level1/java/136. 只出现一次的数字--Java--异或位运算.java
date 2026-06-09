[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_136_singleNumber.java)

```java
    /**
     * 思考：
     * 线性的时间复杂度就是O(n)，不适用额外空间也就是最好常量级空间也不要有
     * O(n)的复杂度只允许遍历数组一次，一次遍历如何标识数字出现的次数？不能用额外空间就只能用数组本身进行存储
     * 是不是可以建立数字在数组中位置的映射关系？
     *
     * 解题思路：
     * 映射关系最常见的就是哈希表，比如数字对数组长度取模，但是可能会发生冲突（两个数组取模结果一致），需解决，处理复杂==>放弃
     * 看了提示说位运算，思考了下的确可以，判断只出现一次，其他都出现两次，正好可以使用异或运算，两次结果复原，出现一次的数据停留在bit上
     * 1.取bit=0
     * 2.循环遍历数组，与bit做异或操作
     * 3.将最终的bit返回
     *
     *
     * @param nums
     * @return
     */
    public int singleNumber(int[] nums) {
        int bit = 0;
        for (int i = 0; i < nums.length; i++) {
            bit = bit ^ nums[i];
        }
        return bit;
    }
```