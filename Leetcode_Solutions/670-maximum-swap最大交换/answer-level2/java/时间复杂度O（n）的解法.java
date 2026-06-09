这题我们的想法肯定是，尽量交换前面的大数位，并且和它交换的数还得是在它后面大于它的最大数
1. 倒序使用数组存储下来每个位置，在它及它以后的最大数的索引
2. 然后再正序从一个数开始遍历，如果它及它以后的最大数不是它本身，那么这个数就是我们需要交换的。
```
class Solution {
    public int maximumSwap(int num) {
        char[] c = String.valueOf(num).toCharArray();
        int max = Integer.MIN_VALUE;
        int max_index = 0;
        int [] arr = new int[c.length];
        arr[c.length - 1] = c.length - 1;
        
        for (int i = c.length - 1; i >= 0; i --) {
            if (c[i] - '0' > max) {
                max = c[i] - '0';
                max_index = i;
            }
            arr[i] = max_index;
        }
        for (int i = 0; i < c.length; i ++) {
            if (arr[i] != i && c[arr[i]] != c[i]) {
                char tmp = c[i];
                c[i] = c[arr[i]];
                c[arr[i]] = tmp;
                break;
            }
        }
        return Integer.parseInt(new String(c));
        
    }
}
```
时间复杂度：O(n)
空间复杂度：O(n)