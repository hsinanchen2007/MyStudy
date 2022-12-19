### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int num = 0;
        wc: for (int i = 0; i < arr1.length; i++) {
                for (int j = 0; j < arr2.length; j++) {
                    int temp = arr1[i] - arr2[j] > 0 ? arr1[i] - arr2[j] : arr2[j] - arr1[i];
                    if (temp<=d) {
                        continue wc;
                    }

                }
            num++;
            }
            return num;
    }
}
```