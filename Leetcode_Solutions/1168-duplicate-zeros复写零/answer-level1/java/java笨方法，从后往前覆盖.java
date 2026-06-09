### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void duplicateZeros(int[] arr) {
        for(int i = 0;i<arr.length-1;i++){
            if(arr[i] == 0){
                for(int j = arr.length-2;j > i;j--){
                    arr[j+1] = arr[j];
                }
                arr[i+1] = 0;
                i++;   //复制0后，i加2，跳过后一个0
            }
        }
    }
}
```