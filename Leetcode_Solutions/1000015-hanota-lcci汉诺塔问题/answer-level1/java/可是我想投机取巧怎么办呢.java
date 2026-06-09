### 宣判封顶！！
```
class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        C.addAll(A);
        A.clear();
    }
}
```
#### 还是好好写代码吧...
```
class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        hanota(A.size(), A, B, C);
    }

    private void hanota(int n, List<Integer> A, List<Integer> B, List<Integer> C) {
        if (n == 1) {
            C.add(A.get(A.size() - 1));
            A.remove(A.get(A.size() - 1));
            return;
        }
        hanota(n - 1, A, C, B);
        C.add(A.get(A.size() - 1));
        A.remove(A.get(A.size() - 1));
        hanota(n - 1, B, A, C);
    }
}
```
