### 解题思路

从前往后修改的思路比较麻烦，但是从后往前来维护一个最大值变量max，就忽然变得很简单。

如果当前的数比max小，则把当前的数变成max；

如果比max大，则把max改成当前的数。

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {

        int max = -1;

        for(int i = arr.length - 1; i >= 0; i--){
            int temp = arr[i];
            arr[i] = max;
            max = temp > max ? temp : max;
        }
        return arr;
    }
}
```