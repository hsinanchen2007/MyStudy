```
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] res = new int[A.length];
        Queue<Integer> odd = new LinkedList<>();
        Queue<Integer> even = new LinkedList<>();

        for (int i = 0; i < A.length; i++) {
            if((A[i] & 1) == 1){
                odd.add(A[i]);
            }else{
                even.add(A[i]);
            }
        }

        for (int i = 0; i < A.length; i++) {
            if((i & 1) == 1){
                res[i] = odd.poll();
            } else {
                res[i] = even.poll();
            }
        }
        return res;
    }
}
```
