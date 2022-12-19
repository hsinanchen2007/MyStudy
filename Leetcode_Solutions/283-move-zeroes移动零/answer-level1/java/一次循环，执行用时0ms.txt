### 解题思路
设置变量存放非零数字的下一个存放地址下标，每次循环只要当前数值不为零都自增1
如果当前数值为零跳过本次循环
如果数值非零且当前下标不等于下一个存放地址下标则将存放地址下标值设置为当前值，且将当前下标值设置为0


### 代码

```java
class Solution {
    public void moveZeroes(int[] data) {
        int l = 0;
        for (int i = 0; i < data.length; i++) {
            if (data[i] == 0) {
                continue;
            }
            if (l != i) {
                data[l] = data[i];
                data[i] = 0;
            }

            l++;
        }
    }
}
```