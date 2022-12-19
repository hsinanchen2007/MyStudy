### 解题思路
针对arr1中的每个元素，判断arr2中是否有与其距离小于等于d的元素，有的话次数-1。

### 代码

```java
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int count = arr1.length;
        for(int num1: arr1)
            for(int num2: arr2)
                if(Math.abs(num1-num2) <= d){
                    count --;
                    break;
                }
        return count;
    }
}
```