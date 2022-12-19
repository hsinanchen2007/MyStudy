### 解题思路
此处撰写解题思路
我的思路:
    遍历数组，判断数组的值是否和这个值相同，如果相同的话就直接返回这个值的下标
如果数组循环完了，那就说明没有找到这个值的下标，那么就直接返回-1;
### 代码

```java
class Solution {
    public int search(int[] arr, int target) {
        int index=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==target){
                return i;
            }
        }
        return -1;
    }
}
```