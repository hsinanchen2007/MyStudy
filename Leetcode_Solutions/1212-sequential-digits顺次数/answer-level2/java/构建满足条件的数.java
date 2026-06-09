### 解题思路
这题不要采用遍历区间所有数，而且要采用构建满足条件的数。
![图片.png](https://pic.leetcode-cn.com/5c1696efdc45ae9b329dcc37890b1751dddbf4b0e6b3db3c9ef0aaf0dbd04a1f-%E5%9B%BE%E7%89%87.png)


### 代码

```java
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        int t = low;
        int length = 1;
        while (length <= 9 && t > 9) {
            length ++;
            t /= 10;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = length; i <= 9; i++) {
            for (int j = 1; j <= 10 - i; j++) {
                int num = build(j, i);
                if (num > high) return result;
                if (num >= low) result.add(num);
            }
        }
        return result;
    }

    private int build(int from, int length) {
        int result = 0;
        for (int i = 0; i < length; i++) {
            result = result * 10 + (from + i);
        }
        return result;
    }
}
```