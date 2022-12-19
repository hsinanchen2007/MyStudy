### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int max=(int)Math.pow(10,n);
        int [] res=new int[max-1];
        for(int i=0;i<max-1;i++)
            res[i]=i+1;
        return res;
    }
}
```