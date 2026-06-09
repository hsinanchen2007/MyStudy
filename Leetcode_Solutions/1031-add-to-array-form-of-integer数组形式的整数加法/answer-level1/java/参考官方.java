```
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        for (int i = A.length -1; i >= 0; i--) {
            int temp = A[i] + K;
            A[i] = temp % 10;
            K = (temp) / 10;
            if (K == 0) {
                break;
            }
        }
        List<Integer>res = Arrays.stream(A).boxed().collect(Collectors.toList());
        // 如果 K 还没有加完，单独对K 处理。
        while (K > 0) {
            res.add(0, K % 10);
            K /= 10;
        }
        return res;
    }
}
```
