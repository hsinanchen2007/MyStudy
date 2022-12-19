### 解题思路
1.按照字符串思路计算出各个数字出现的次数；
2.然后取出最值。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //1.计算数字出现的次数，并排序
        int[] newArr = new int[10000];

        for (int i = 0; i < arr.length; i++) {
            newArr[9999 - arr[i]]++;
        }

        //返回的新数组
        int[] rtnArr = new int[k];
        int len = 0;
        for (int i = 10000 - 1; i >= 0 ; i--) {
            if (len == k) {
                break;
            }

            int size = newArr[i];
            while (len < k && size > 0) {
                rtnArr[len] = 9999 - i;
                len++;
                size --;
            }
        }

        return rtnArr;
    }
}
```