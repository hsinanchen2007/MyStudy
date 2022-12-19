### 解题思路
使用数组做去重，另外抓住题目的两个条件，一是数的范围是-1000到1000，这样需要一个长度为2001的数组；
二是数组的长度是[1, 1000]，这样还需要另一个数组用作去重，去重数组的长度怎么计算呢？由条件二我们可以先得知原数组最大的情况是1000个数，那么去重数据在最坏的情况下应该是1,2,3,4……n，这是一个等差数列，这个数列需要满足Sn = (1+n)*n/2 >= 1000,可以计算到n的最小值是45，为了计算方便我们定义去重数据的长度为46，是的个数的和去重数据的下标一一对应。
当然了，如果希望使用更少的空间，两个数组可以定义为short类型。

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] array = new int[2001];
        int[] counts = new int[46];

        for (int a : arr) {
            array[a + 1000]++;
        }

        for (int a : array) {
            if (a == 0) {
                continue;
            }
            if (counts[a] == 1) {
                return false;
            }
            counts[a] = 1;
        }
        return true;
    }
}
```