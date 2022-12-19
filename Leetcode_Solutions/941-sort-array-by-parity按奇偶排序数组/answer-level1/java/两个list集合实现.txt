### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        List<Integer> odd = new ArrayList<>();
        List<Integer> even = new ArrayList<>();
        for(int i = 0;i<A.length;++i){
            if(A[i]%2 == 0){
                even.add(A[i]);
            }else {
                odd.add(A[i]);
            }
        }
        for(int n : odd){
            even.add(n);
        }

        for(int i = 0;i<A.length;i++)
        {
            A[i] = even.get(i);
        }
        return A;
    }
}
```