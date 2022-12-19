### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
      int max=arr[arr.length-1];int flag=0;
      for(int i=arr.length-2;i>=0;i--){
          flag=arr[i];
          arr[i]=max;
          if(flag>max)
          max=flag;
      }
      arr[arr.length-1]=-1;
      return arr;
    }
}
```