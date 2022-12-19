### 解题思路
对每一位上的数字依次递归，首先得出本位数字对应的字母，然后位数+1进行递归，再判断本位数字与下一位数字能否结合成一位字母，若可以，则+2继续递归。当当前位与size相等，则停止。

### 代码

```java
class Solution {
    int count = 0, size;
    char[] n;
    public int translateNum(int num) {
        String numStr = String.valueOf(num);
        n = numStr.toCharArray();
        size = n.length;
        getCount(0);
        return count;
    }

    public void getCount(int k) {
        if (k == size) {
            count ++;
            return;
        }
        getCount(k + 1);
        if (doubleDigits(k))
            getCount(k + 2);
    }

    public boolean doubleDigits(int k) {
        if (k < size - 1 && (n[k] == '1' || (n[k] == '2' && n[k + 1] >= '0' && n[k + 1] <= '5'))) {
            return true;
        }
        return false;
    }
}
```