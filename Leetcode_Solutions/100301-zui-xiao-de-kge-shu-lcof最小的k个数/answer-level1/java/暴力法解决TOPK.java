### 解题思路
给原始数组排序，然后返回数组的前k个元素（新手上路，有不足还请大佬们指正；）
### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //给数组排序；
        Arrays.sort(arr);
        //创建新的数组长度为k；
        int[] answer = new int[k];
        //将arr中的前k个元素添加到answer数组中；
        for(int i = 0; i < k; i++) {
            answer[i] = arr[i];
        }
        return answer;
    }
}
```