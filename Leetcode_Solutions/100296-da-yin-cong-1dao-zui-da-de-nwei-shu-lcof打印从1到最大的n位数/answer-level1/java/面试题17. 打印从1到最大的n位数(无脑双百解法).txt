### 解题思路
暂时不考虑大数情况，若大数则需使用字符串或字符数组

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int x=(int)Math.pow(10,n)-1;
        int[] res=new int[x];
        for(int i=0;i<x;i++){
            res[i]=i+1;
        }
        return res;
    }
}
```