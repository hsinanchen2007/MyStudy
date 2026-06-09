### 解题思路
先判断n的奇偶性，n为偶数就把数组的左半边等于负的右半边，这样数组之和就为0；n为奇数的话，要注意右半边数组的取值，且令下标为n/2的元素为0，也就是数组的中间元素。

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n]; 
        if(n % 2 == 0){
            for(int i = 0;i<n/2;i++){
                ans[i] = i+1;
                ans[i+n/2] = -i-1;
            }
        }else{
            for(int i = 0;i<n/2;i++){
                ans[i] = i+1;
                ans[i+n/2+1] = -i-1;
            }
            ans[n/2] = 0;
        }
        return ans;
    }
}
```