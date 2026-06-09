### 解题思路
签到打卡

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        //暴力破解 归并排序

        int[] tempArr = new int[m];

        for (int i = 0; i < m; i++) {
            tempArr[i] = A[i];
        } 

        //几率当前归并到的下标
        int index = 0;
        int r = 0;
        int l = 0;

        //归并排序到A上 因为这里是默认已经排序过的所以只需要排序一次即可
         while (r < m && l < n) {

                //左边小
                if (tempArr[r] <= B[l]) {
                    A[index++] = tempArr[r++];
                } else if (B[l] <= tempArr[r]) {
                    A[index++] = B[l++];
                }

         }

        //将某一个数组内剩余的添加到数组的最后

        while (r < m) A[index++] = tempArr[r++];

        while (l < n) A[index++] = B[l++];

    }

}
```