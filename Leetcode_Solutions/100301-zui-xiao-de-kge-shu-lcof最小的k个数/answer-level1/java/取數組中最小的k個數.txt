### 解题思路
此处撰写解题思路
先排序使用 Arrays.sort()方法

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
 Arrays.sort(arr);
        int []res=new int[k];
        for (int i=0;i<k;i++){
            res[i]=arr[i];
        }
        return res;
    }
}
```