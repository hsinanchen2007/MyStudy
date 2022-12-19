### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkIfExist(int[] arr) {
         for(int j=0;j<arr.length;j++){
             int temp = arr[j];
         for(int i=0;i<arr.length;i++){
             if(i==j)continue;
             if(temp==2*arr[i])return true;
         }
         }
         return false;
    }
}
```