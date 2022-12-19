### 解题思路
此处撰写解题思路
就是快排的修改吧，JAVA自带的sort本身就是优化的快排 所以我感觉我没必要去写（因为前面刷题 快排 冒泡也修改了多次了 这次就偷个懒~~）
### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Arrays.sort(arr);
        int arrs[] = Arrays.copyOfRange(arr,0,k);
        return arrs;
    }
}
```