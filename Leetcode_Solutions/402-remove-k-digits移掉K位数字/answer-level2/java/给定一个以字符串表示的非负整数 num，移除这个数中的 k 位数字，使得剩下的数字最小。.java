### 解题思路
    父问题可以分解为K个子问题，每个子问题题为：移除数字num中的一位使得到的数字最小。

    迭代的解K个上述子问题即为该问题的解。

    下面关注点就到了如何解子问题，我们发现可以转换为从左到右找第一个逆序对，将逆序对的第一位删除。

    另外需要注意去除左侧无意义零。

### 代码

```java
class Solution {
    public String removeKdigits(String num, int k) {
        for (int i = 0; i < k; i++) {
            num = getNext(num);
        }
        return num;
    }

    private String getNext(String num) {
        int i = 0;
        for (; i < num.length() - 1; i++) {
            if (num.charAt(i) > num.charAt(i + 1))
                break;
        }
        return formatResult(num.substring(0, i) + num.substring(i + 1));
    }

    private String formatResult(String num) {
        int i = 0;
        for (; i < num.length(); i++) {
            if (num.charAt(i) != '0') {
                break;
            }
        }
        return i == num.length() ? "0" : num.substring(i);
    }
}
```