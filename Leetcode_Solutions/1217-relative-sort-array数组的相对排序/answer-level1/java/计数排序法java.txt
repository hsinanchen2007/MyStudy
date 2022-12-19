### 解题思路
1.用一个数组countArr存储arr1中的元素出现的频次，下标是arr1中的元素，这样其实已经进行了排序.
2.遍历arr2将其中的每个元素作为下标，在countArr找到arr1中与其相同的元素个数，并且都放入结果中。这样就是按照arry2的顺序输出。
3.剩下的元素就是arr2不在arr1中的元素了，直接遍历countArr数组放入即可，已经排好序了。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        // 存储arr1中的元素的出现频次，下标是arr1中的元素，值是出现的频次
        int[] countArr = new int[1001];
        // 答案，因为arr2的元素都在arr1中，所以长度为arr1的长度
        int[] ans = new int[arr1.length];
        // 计算频次
        for (int a1 : arr1) {
            countArr[a1]++;
        }
        int j = 0;
        for (int value : arr2) {
            while (countArr[value] > 0) {
                ans[j++] = value;
                // 不要忘记减1，
                countArr[value]--;
            }
        }
        // 剩下的已经排序了，直接放入就行
        for (int i = 0; i < countArr.length; i++) {
            // 此处要双循环，因为可以是多次
            while (countArr[i] > 0) {
                // 注意此处是下标i是答案
                ans[j++] = i;
                // 不要忘记减1
                countArr[i]--;
            }
        }
        return ans;
    }
}
```