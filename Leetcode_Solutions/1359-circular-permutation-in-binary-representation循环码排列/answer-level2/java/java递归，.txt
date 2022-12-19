```
class Solution {
     public List<Integer> circularPermutation(int n, int start) {
        List<Integer> sk = circularPermutation2(n);
        List<Integer> out = new ArrayList<>();
        int mark = -1;

        for (int i = 0; i < sk.size(); i++) {
            if (mark == -1) {
                if (sk.get(i) == start) {
                    mark = i;
                    out.add(start);
                }
            } else {
                out.add(sk.get(i));
            }
        }
        for (int i = 0; i < mark; i++) {
            out.add(sk.get(i));
        }
        return out;
    }
    public List<Integer> circularPermutation2(int n) {
        if (n <= 0) return new ArrayList<>();
        else if (n == 1) {
            List<Integer> temp = new ArrayList<>();
            temp.add(0);
            temp.add(1);
            return temp;
        } else {
            List<Integer> temp = circularPermutation2(n - 1);
            int size = temp.size();
            for (int i = 0; i < size; i++) {
                temp.add(temp.get(size - 1 - i) + size);
            }
            return temp;
        }
    }

}
```
