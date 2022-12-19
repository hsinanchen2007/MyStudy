本题的关键在于要想到异或运算的性质：x^0=x。

求出从0到i位置的异或和，那么[i,j]的异或和为xors[0,i] ^ xors[0,j+1]。

xors[0,i] = arr[0] ^ arr[1] ^ ... arr[i-1]
xors[0,j+1] = arr[0] ^ arr[1] ^ ... arr[i-1] ^ arr[i] ^ ... arr[j]
xors[0,i] ^ xors[i,j+1] = 0 ^ 0 ^ ... arr[i] ^ ... arr[j] = xors[i,j+1]
```
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] xors = new int[arr.length + 1];
        for (int i = 1; i <= arr.length; i++) {
            xors[i] = xors[i - 1] ^ arr[i - 1];
        }

        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }
        return ans;
    }
}
```

