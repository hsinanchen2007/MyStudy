### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        //Set<Integer> set = new HashSet<Integer>();
        int cnt = 0;
        // for(int i = 0; i < A.length; i++){
        //     while(set.contains(A[i])){
        //         A[i] += 1;
        //         cnt++;
        //     }
        //     if(!set.contains(A[i])){
        //         set.add(A[i]);
        //     }
        // }

        if(A == null || A.length == 0){
            return cnt;
        }
        Arrays.sort(A);
        int target = A[0];
        for(int i = 1; i < A.length; i++){
            while(target >= A[i]){
                A[i] += 1;
                cnt++;
            }
            target = A[i];
        }
        return cnt;
    }
}
```