### 解题思路
令count = arr1.length，循环，只要有一个元素不符合条件，count--，最后返回count

### 代码

```java
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int count = arr1.length;
        for(int i = 0;i<arr1.length;i++){
            for(int j = 0;j<arr2.length;j++){
                if(Math.abs(arr1[i] - arr2[j]) <= d){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
}
```