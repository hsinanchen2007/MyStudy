### 解题思路
当题目给出的数组题目，且数组范围固定时，通常可以考虑如果利用数组下标解决问题。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {

        //0-1001每个元素的个数
        int[] counts = new int[1001];
        for(int i=0;i < arr1.length;i++) {
            counts[arr1[i]]++;
        }

        int idx = 0;
        int[] result = new int[arr1.length];
        //存在的都放result
        for(int i=0;i < arr2.length;i++) {
            while(counts[arr2[i]] > 0) {
                result[idx++] = arr2[i];
                counts[arr2[i]]--;
            }
        }
        //不存在的
        for(int i=0; i < counts.length; i++) {
            while(counts[i] > 0) {
                result[idx++] = i; 
                counts[i]--;
            }
        }
        return result;
    }

    //0-1000，每个元素的存储的位置
    //int[] sort = new int[1001];
    //for(int i=0;i<arr2.length;i++) {
    //    sort[arr2[i]] = i+1; //从1开始，0代表不存在
    //}
}
```