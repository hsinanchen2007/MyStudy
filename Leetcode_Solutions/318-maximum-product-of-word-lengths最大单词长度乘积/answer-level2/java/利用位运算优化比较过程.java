```java
/**
 * 时间复杂度 O(n*n)
 * 空间复杂度O(2n)
 * abcd -> 00001111
 * efgh -> 11110000
 * 二者没有交集，进行与运算,结果为0，
 * 二者有交集，与运算的结果不为0
 */

class Solution {
    public int maxProduct(String[] words) {
        int N = words.length;
        int[] B = new int[N];
        int[] L = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = getBit(words[i]);
            L[i] = words[i].length();
        }
        int rst = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                // abcd -> 1111
                // def ->111000
                // d位置相交
                if ((B[i] & B[j]) != 0) continue;
                rst = Math.max(rst, L[i] * L[j]);
            }
        }
        return rst;
    }

  
    int getBit(String w) {
        int b = 0;
        for (char c : w.toCharArray()) {
            b |= (1 << (c - 'a'));//或运算
        }
        return b;
    }

    public static void main(String[] args) {
        String [] A={"a","aa","aaa","aaaa"};
        int s=new Solution().maxProduct(A);
        System.out.println(s);
    }

}
```