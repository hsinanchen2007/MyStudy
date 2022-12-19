### 解题思路
首先，对数组进行排序，此时找到最小值下标 i
其次，while(K>0) 遍历，对A[i] 进行取负，并判断i+1 的值和翻转后的值比较大小，找到当前最小值
以此类推。
最后，遍历求和。

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        Arrays.sort(A);
        int i = 0;
        while(K>0) {
            A[i] = -A[i];
            if(A[i+1] < A[i]) { 
                i++;
            }

            K--;
        }
        
        int ans = 0;
        for (int j : A) {
            ans += j;
        }
        return ans;
    }
}
```