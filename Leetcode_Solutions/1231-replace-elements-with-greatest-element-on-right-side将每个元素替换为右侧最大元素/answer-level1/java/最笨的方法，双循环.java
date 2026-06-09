### 解题思路
先把需要需要覆盖的元素置为0，判断特殊情况i为末尾赋值为-1，然后从i+1开始遍历交换。

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        for(int i = 0;i<arr.length;i++){
            arr[i] = 0;
            if(i == arr.length -1){
                arr[i] = -1;
                break;
            }
            for(int j = i+1;j<arr.length;j++){
                if(arr[j] > arr[i]){
                    arr[i] = arr[j];
                }
            }
        }
        return arr;
    }
}
```