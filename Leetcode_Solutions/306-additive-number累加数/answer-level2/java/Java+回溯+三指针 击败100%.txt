![企业微信20200324093819.png](https://pic.leetcode-cn.com/543781bba27ddbf874267c15e9e122c588ccd74a1dcb4ead9771e227f3d4a986-%E4%BC%81%E4%B8%9A%E5%BE%AE%E4%BF%A120200324093819.png)

```
class Solution {
    public boolean isAdditiveNumber(String num) {
        if (num.length() < 3)
            return false;
        char[] array = num.toCharArray();
        // i作为第二数的起始索引，j作为第三个数的起始索引。（第一个数的位数不应超过整个字符串的一半，否则计算和必定不满足）
        for (int i=1; i<=array.length/2; i++) {
            for (int j=i+1; j<=array.length-1; j++) {
                if (add(array, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    /**
     * @param array 原始数组
     * @param i 第一个数的起始索引
     * @param j 第二个数的起始索引
     * @param k 第三个数的起始索引
     * @return true表示成功遍历到尾部，外层调用方也可直接返回true；false表示查找失败
     */
    public boolean add(char[] array, int i, int j, int k) {
        long sum = 0;
        long ten = 1;
        // c用于记录和的位数
        int c = 0;
        int n1 = j-1;
        int n2 = k-1;

        // 排除非0的，但以0开头的数
        if ((array[i]=='0' && j-i>1) || (array[j]=='0' && k-j>1))
            return false;

        // 从个位开始计算两个数的和
        while (n1>=i && n2>=j) {
            sum += ((array[n1--]-'0') + (array[n2--]-'0')) * ten;
            ten *= 10;
            c++;
        }
        // 计算剩余高位的和
        while (n1>=i) {
            sum += (array[n1--]-'0') * ten;
            ten *= 10;
            c++;
        }
        // 计算剩余高位的和 
        while (n2>=j) {
            sum += (array[n2--]-'0') * ten;
            ten *= 10;
            c++;
        }

        // 和的位数
        int size = k+c;
        // 和的位数超出数组大小，则返回失败
        if (array.length < size)
            return false;

        if (ten > sum) {
            // ten大于和的情况，例如sum=19=9+10，ten=100
            // ten除以10，用于后续比较第三个数
            ten /= 10;
        } else {
            // ten小等于和的情况，例如sum=10=9+1，ten=10
            // 有进位，和的位数需要补充加一
            size++;
        }

        // 和与数组中接下来的字符比较
        for (int l=k; l<size; l++) {
            int n = (int) (sum / ten);
            // 有一个字符不相等，即返回失败
            if (array[l]-'0' != n) return false;
            sum %= ten;
            ten /= 10;
        }
        // 执行到这里说明第三个数匹配成功

        // 第三个数刚好抵达数组尾部，则返回true，否则继续回溯递归
        return array.length == size || add(array, j, k, size);
    }
}
```
