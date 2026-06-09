### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int s=1;
        for(int j=0;j<n;j++){
            s=s*10;
        }
        int []a=new int[s-1];
        for(int i=1;i<s;i++){
            a[i-1]=i;
        }
        return a;
    }
}
```