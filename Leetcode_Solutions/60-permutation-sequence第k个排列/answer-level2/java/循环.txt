### 解题思路

取余数编码方式

### 代码

```java
class Solution {
    public String getPermutation(int n, int k) {
        // k-1 = an*(n-1)! + an_1*(n-2)! + ... + a2*1! + a1*0!
        // 对于1234, 以1开头的3!,2开头的3!, 共4*3!, n=4, k=8
        // 8/3! = 1, [1,2,3,4]删除index=1 [1,3,4], k=9-3!=3
        // 2/2! = 1, [1,3,4]删除index=1, [1,4], k=2-2!=0
        // 0/1! = 0, [1,4]删除index=0
        // 存阶乘信息 f[n] = (n-1)!
        int[] fac = new int[n];
        fac[0] = 1;
        for(int i=1; i<n; i++){
            fac[i] = i * fac[i-1];
        }
        // 存列表信息, 需要删除
        LinkedList<Integer> list = new LinkedList<>();
        for(int i=0; i<n; i++){
            list.add(i+1);
        }
        StringBuilder result = new StringBuilder();
        k = k - 1;
        for(int i=0; i<n; i++){
           int index = k / fac[n-1-i];
           result.append(list.remove(index));
           k = k - index * fac[n-1-i];
        }
        return result.toString();
        
    }
}
```