### 解题思路
这是啥题...

### 代码

```java
class Solution {
    public int search(int[] arr, int target) {
        int l = 0;
        while(l < arr.length - 1 && arr[l] != target){
            l++;
        }
        if(arr[l] == target){
            return l;
        }else{
            return -1;
        }
    }
}
```