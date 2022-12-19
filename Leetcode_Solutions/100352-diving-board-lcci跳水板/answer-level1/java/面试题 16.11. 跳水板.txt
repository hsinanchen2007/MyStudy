### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        if(k==0)return new int[]{};//k等于0的情况
        if(shorter==longer)return new int[]{k*shorter};
        int[] res=new int[k+1];
        for(int i=0;i<=k;i++){
            res[i]=shorter*i+longer*(k-i);
        }
        Arrays.sort(res);
        return res;
    }
}
```