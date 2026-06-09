### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int num = 0;
        for(int i=0;i<n;i++){
            num = num*10+9;
        }
        int [] arr = new int[num];
        for(int j=0;j<num;j++){
           arr[j]=j+1;
        }
        return arr;
    }
}
```