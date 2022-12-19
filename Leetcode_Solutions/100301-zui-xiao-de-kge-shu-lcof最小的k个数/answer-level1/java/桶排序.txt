### 解题思路
![75ab005cf1881116b8c0975125843b5.png](https://pic.leetcode-cn.com/991923c36d591cce67e02bf5485dfbb88fd590fdc3eb31a1f11333a622e1713f-75ab005cf1881116b8c0975125843b5.png)
桶排序，O(n)的时间复杂度

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] temp = new int[10000];
        for (int i=0; i<arr.length; i++) {
            temp[arr[i]]++;
        }
        int[] re = new int[k];
        int count=0, index=0;
        while (count < k) {
            while (temp[index] == 0) {
                index++;
            }
            re[count++] = index;
            temp[index]--;
        }
        return re;
    }
}
```