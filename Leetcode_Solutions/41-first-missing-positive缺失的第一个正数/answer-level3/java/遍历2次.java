关键点：
数组长度为len，那么返回值肯定在 1 到 len+1 之间。

思路：
设置一个同样长度 len 的数组flags，用于保存 1 到 len+1 之间的数字 k 是否出现过。

第一次遍历数组nums：
 1 到 len+1 之间的数字 k 出现过，则把flags对应下标 k-1 的值设为true。

第二次遍历数组flags：
找到第一个值为false的下标 i ，那么 i+1 就是要找的数字。
如果全部都是true，那么 len+1 就是要找的数字。


```java []
public int firstMissingPositive(int[] nums) {
    int len = nums.length;
    boolean[] flags = new boolean[len];
    for (int num : nums) {
        if (num <= len && num>0) {
            flags[num-1] = true;
        }
    }

    for (int i = 0; i < len; i++) {
        if (!flags[i]) {
            return i+1;
        }
    }
    return len+1;
}
```




