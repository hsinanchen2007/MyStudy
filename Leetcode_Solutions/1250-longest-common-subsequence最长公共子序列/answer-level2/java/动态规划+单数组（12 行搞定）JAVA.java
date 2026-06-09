将两个字符串组成二维的矩阵,比如“ABA”和“AAC”。
  A B A
A
A
C

每个子矩阵的最后一个数即是公共序列(不同为 0，相同加 1)。

(A和 A 相同则为 1，代表A 与 A 这个矩阵中，只有一个公共序列)
  A B A
A 1
A
C

(第一行剩下为 1，表示 A 与 ABA 已经找到一个相同的)
  A B A
A 1 1 1
A
C

(第一列同理)

  A B A
A 1 1 1
A 1
C 1

(剩下的，如果行列字符相同，则为左上方矩阵的公共序列数+ 1，即(1) + 1 = (2))
解释：ABA 与 AA，在最后一个 A 的位置相同，所以其公共序列数 = 子序列 AB 与 A 的公共序列数 + 1(最后的 A 相同，所以+1 喽)。
  A  B  A
A 1 (1) 1
A 1  1 (2)
C 1

(如果行列字符不同，则取上与左的最大值，比如最后一个 _2_,对应的 A 和 C 不同，所以等于(1)和(2)的最大值，即为 2)
解释：取最大值代表，既然我自己不是公共序列中的一员，那我需要将之前矩阵的值延续下去。
  A  B   A
A 1  1   1
A 1  1  (2)
C 1 (1)  _2_

而最终这个 2，就是这个矩阵中的最大公共序列数了。


```
//执行用时 :6 ms, 在所有 java 提交中击败了100.00%的用户
//内存消耗 :33.8 MB, 在所有 java 提交中击败了100.00%的用户
public int longestCommonSubsequence(String text1, String text2) {
        int l1 = text1.length(), l2 = text2.length();
        char[] s1 = text1.toCharArray(), s2 = text2.toCharArray();
        int[] arr = new int[l2];
        int prev;
        for (int i = 0; i < l1; i++) {
            int tmp = 0;
            for (int j = 0; j < l2; j++) {
                prev = arr[j];
                if (s1[i] == s2[j]) arr[j] = tmp + 1;
                else if (j > 0) arr[j] = Math.max(arr[j], arr[j - 1]);
                tmp = prev;
            }
        }
        return arr[l2 - 1];
    }
```
