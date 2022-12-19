### 解题思路
不同长度的不重复全排列

### 代码

```java
class Solution {
    private int n = 0; // 字符串的长度
    private int m = 0; // 字符串中m个不同的字符
    private int count = 0; // 非空字母序列的数目
    private char[] res = new char[10]; // 记录每个位置填写的字符
    private int[] used = new int[10]; // 标记m个字符可以使用的次数
    private char[] nums = new char[10]; // 存放输入中互不相同的m的字符

    public void backtrace(int index) {
        if (index != 0) {
            ++count;
        }
        for (int i = 0; i < m; ++i) { // 枚举m个不同的字符
            if (used[i] > 0) { // 若nums[i]字符还没有被用完，则可使用次数减1
                --used[i];
                res[index] = nums[i]; // 在index位置上放上该字符
                backtrace(index + 1); // 填下一个位置
                ++used[i]; // 可使用次数恢复
            }
        }
    }

    public int numTilePossibilities(String line) {
        n = line.length();
        for (int i = 0, j; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (nums[j] == line.charAt(i)) {
                    used[j]++;
                    break;
                }
            }
            if (j == m) {
                nums[m] = line.charAt(i);
                used[m++] = 1;
            }
        }
        backtrace(0);
        return count;
    }
}
```