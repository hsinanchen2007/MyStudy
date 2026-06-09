### 解题思路
首先使用两个集合存储奇数和偶数，随后依次取出放入A中

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        List<Integer> ji = new ArrayList<Integer>();
        List<Integer> ou = new ArrayList<Integer>();
        for(int i = 0;i<A.length;i++) {
            if(A[i]%2==0) {
                ou.add(A[i]);
            }else {
                ji.add(A[i]);
            }
        }
        int count = 0;
        int i = 0;
        for(i = 0;i<ou.size();i++) {
            A[i] = ou.get(count++);
        }
        count = 0;
        for(;i<A.length;i++) {
            A[i] = ji.get(count++);
        }
        return A;

    }
}
```