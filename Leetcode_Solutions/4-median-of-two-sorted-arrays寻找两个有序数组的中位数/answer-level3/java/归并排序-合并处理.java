### 解题思路
代码思路:将两个数组合并到all数组中,参加合并的两个数组是有序的,所以在合并数组时用到归并排序的后半部分“治(conquer)”算法。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] oneArray, int[] twoArray) {
        int i=0, j=0, count = 0;
        int[] all = new int[oneArray.length + twoArray.length];
        while (i < oneArray.length || j < twoArray.length){
            //oneArray超出
            if(i == oneArray.length){
                all[count++] = twoArray[j];
                j++;
                continue;
            }
            //twoArray超出
            if(j == twoArray.length){
                all[count++] = oneArray[i];
                i++;
                continue;
            }
            if(oneArray[i] < twoArray[j]){
                all[count++] = oneArray[i];
                i++;
            }else {
                all[count++] = twoArray[j];
                j++;
            }
        }
        int model = all.length % 2;
        int middle = all.length / 2;
        return model == 0 ? ((double)all[middle-1] + (double)all[middle])/2 : (double)all[middle];
    }
}
```