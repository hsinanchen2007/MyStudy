### 解题思路
1. 遍历nums数据所有元素，判断每个元素的位数为偶数，总数count+1
2. 统计位数的方法是 /10 数字就+1，直到num < 10,循环结束
3. 判断统计值是否为偶数，count & 1 的结果 会让count 转化为2进制后，保留最后一位其他位置为 0，如果最后一个是 1 则是奇数，反之是偶数

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        if (nums == null || nums.length == 0) {//不加这个判断，多耗时1ms
            return 0;
        }
        int count = 0;
        for (int num : nums) {
            if (isEven(num)) {
                count++;
            }
        }
        return count;
    }

    private boolean isEven(int num) {
        int count = 1;
        while (num >= 10) {
            num /= 10;
            count++;
        }
        return (count & 1) == 0;
    }
}
```