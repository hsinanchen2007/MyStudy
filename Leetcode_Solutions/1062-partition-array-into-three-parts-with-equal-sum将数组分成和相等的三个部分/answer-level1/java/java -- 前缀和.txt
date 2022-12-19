### 解题思路
利用前缀去累加和，减少运算量

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        int[] dict = new int[A.length];
        dict[0]=A[0];
        for(int i=1;i<A.length;i++){
            dict[i]=dict[i-1]+A[i];
        }
        if(dict[A.length-1]%3!=0)return false;
        sum = dict[A.length-1]/3;
        for(int i=0;i<A.length;i++){
            if(dict[i]==sum){
                for(int j=i+1;j<A.length-1;j++){
                    if(dict[j]-dict[i]==sum && dict[A.length-1]-dict[j]==sum  )
                        return true;
                }
            }
        }
        return false;
    }
}
```