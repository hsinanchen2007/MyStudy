### 解题思路
根据余数定理 

`(a+b)%q=(a%q+b%q)%q` 

`(a * b) % p = (a % p * b % p) % p`

可以每添加一位求一次余数，然后在余数的基础上继续求下一位，依次类推

### 代码

```java
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> ans = new ArrayList<Boolean>();
        int state =0;
        for(int i=0;i<A.length;i++){
            state = ((state<<1)+A[i])%5;
            if(state==0) ans.add(Boolean.TRUE);
            else ans.add(Boolean.FALSE);
        }
        return ans;
    }
}
```