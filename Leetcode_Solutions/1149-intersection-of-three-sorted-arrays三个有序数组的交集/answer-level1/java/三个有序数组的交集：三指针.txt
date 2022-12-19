### 解题思路
因为三个数组均为排序好的数组，所以可以考虑使用类似于**合并两个有序数组的思路**
1. 定义三个指针
    a. 三个指针指向的值相等，那么三个指针同时后移
    b. 如果他们不相等，那么找出最小的数，相应的指针后移，注意：这个地方可能有两个值同时为最小值

### 代码

```java
class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> res = new ArrayList<>();
        int arr1Index = 0, arr2Index = 0, arr3Index = 0;
        int arr1Len = arr1.length, arr2Len = arr2.length, arr3Len = arr3.length;
        while (arr1Index < arr1Len && arr2Index < arr1Len && arr3Index < arr3Len) {
            int arr1Val = arr1[arr1Index], arr2Val = arr2[arr2Index], arr3Val = arr3[arr3Index];
            if (arr1Val == arr2Val && arr2Val== arr3Val) {
                res.add(arr1Val);
                arr1Index++; arr2Index++; arr3Index++;
                continue;
            }
            /// 最小值往后移动
            int minVal = Math.min(Math.min(arr1Val, arr2Val), arr3Val);
            if (arr1Val == minVal) {
                arr1Index++;
            }
            if (arr2Val == minVal) {
                arr2Index++;
            }
            if (arr3Val == minVal) {
                arr3Index++;
            }
        }
        return res;
    }
}
```