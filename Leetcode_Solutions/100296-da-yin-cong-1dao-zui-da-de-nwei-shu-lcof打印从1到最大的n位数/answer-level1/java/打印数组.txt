### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        if(n == 0)
            return new int[0];

        int[] res = new int[(int)Math.pow(10,n) - 1];
        
        for(int i = 0; i < res.length; i++){
            res[i] = i+1;
        }
        return res;
    }
}
```