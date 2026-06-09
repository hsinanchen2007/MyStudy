### 解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        if(n==0){
            return new int[]{};
        }
        int s=(int)Math.pow(10,n);
        int[] res=new int[s-1];
        for(int i=1;i<s;i++){
            res[i-1]=i;
        }
        return res;
    }
}
```