利用G(i) = B(i+1) xor B(i)
```Java []
class Solution {
    public List<Integer> grayCode(int n) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < Math.pow(2, n); ++i) {
            list.add(bi2gray(i));
        }
        return list;
    }

    private static int bi2gray(int n) {
        int b_ip1, b_i = n % 2, ans = 0, i = 0;

        while (n != 0) {
            n >>>= 1;
            b_ip1 = n % 2;
            ans = ((b_i ^ b_ip1) << i++) | ans;
            b_i = b_ip1;
        }
        return ans;
    }
}
```

