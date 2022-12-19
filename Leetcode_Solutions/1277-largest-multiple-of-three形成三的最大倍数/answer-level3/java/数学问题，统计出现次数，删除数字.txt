能被3整除的数字，各个位上的数字之和也能被3整除。

计算digit数组之和sum。

将数字分为3i、3i+1、3i+2。

若sum % 3 == 1，删除一个3i+1即可，若没有这种数字，删除两个3i+2即可（可证此时3i+2至少存在两个）；若sum % 3 == 2同理。

观察数据规模只有0到9，可统计每个数字出现的次数。

代码：
```
class Solution {
    private int[] num;

    private boolean delete(int k) {
        for (int i = k; i < 10; i = i + 3) {
            if (num[i] > 0) {
                num[i]--;
                return true;
            }
        }
        return false;
    }
    private String makeString() {
        StringBuilder ans = new StringBuilder("");
        for (int i = 9; i >= 0; i--)
            while (num[i]-- > 0)
                ans.append((char)(i + '0'));
        int index = 0;
        while (index < ans.length() - 1) {
            if (ans.charAt(index) != '0') break;
            index++;
        }
        return ans.delete(0, index).toString();
    }
    public String largestMultipleOfThree(int[] digits) {
        num = new int[10];
        int sum = 0;
        for (int value : digits) {
            num[value]++;
            sum += value;
        }
        int k = sum % 3;
        if (k > 0) {
            if (!delete(k)) {
                delete(3 - k);
                delete(3 - k);
            }
        }
        return makeString();
    }
}
```
![3.png](https://pic.leetcode-cn.com/2e23007193b9c0b9e37c07d8a5920cfb8e60f676bb7695fd5d56cf11fafc6d27-3.png)
