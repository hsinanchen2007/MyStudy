#### 自定义排序：

**想法**

为了构建最大数字，我们希望越高位的数字越大越好。

**算法**

首先，我们将每个整数变成字符串。然后进行排序。

如果仅按降序排序，有相同的开头数字的时候会出现问题。比方说，样例 2 按降序排序得到的数字是 $95343303$ ，然而交换 $3$ 和 $30$ 的位置可以得到正确答案 $9534330$ 。因此，每一对数在排序的比较过程中，我们比较两种连接顺序哪一种更好。我们可以证明这样的做法是正确的：

假设（不是一般性），某一对整数 $a$ 和 $b$ ，我们的比较结果是 $a$ 应该在 $b$ 前面，这意味着 $a\frown b > b\frown a$ ，其中 $\frown$ 表示连接。如果排序结果是错的，说明存在一个 $c$ ， $b$ 在 $c$ 前面且 $c$ 在 $a$ 的前面。这产生了矛盾，因为 $a\frown b > b\frown a$ 和 $b\frown c > c\frown b$ 意味着 $a\frown c > c\frown a$ 。换言之，我们的自定义比较方法保证了传递性，所以这样子排序是对的。

一旦数组排好了序，最“重要”的数字会在最前面。有一个需要注意的情况是如果数组只包含 0 ，我们直接返回结果 $0$ 即可。否则，我们用排好序的数组形成一个字符串并返回。

```Java []
class Solution {
    private class LargerNumberComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            String order1 = a + b;
            String order2 = b + a;
           return order2.compareTo(order1);
        }
    }

    public String largestNumber(int[] nums) {
        // Get input integers as strings.
        String[] asStrs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            asStrs[i] = String.valueOf(nums[i]);
        }

        // Sort strings according to custom comparator.
        Arrays.sort(asStrs, new LargerNumberComparator());

        // If, after being sorted, the largest number is `0`, the entire number
        // is zero.
        if (asStrs[0].equals("0")) {
            return "0";
        }

        // Build largest number from sorted array.
        String largestNumberStr = new String();
        for (String numAsStr : asStrs) {
            largestNumberStr += numAsStr;
        }

        return largestNumberStr;
    }
}
```

```Python []
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
        
class Solution:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num
```

**复杂度分析**

* 时间复杂度：$O(nlgn)$

    尽管我们在比较函数中做了一些额外的工作，但是这只是一个常数因子。所以总的时间复杂度是由排序决定的，在 Python 和 Java 中都是 $O(nlgn)$ 。

* 空间复杂度：$O(n)$

    这里，我们使用了 $O(n)$ 的额外空间去保存 `nums` 的副本。尽管我们就地进行了一些额外的工作，但最后返回的数组需要 $O(n)$ 的空间。因此，需要的额外空间与 `nums` 大小成线性关系。
