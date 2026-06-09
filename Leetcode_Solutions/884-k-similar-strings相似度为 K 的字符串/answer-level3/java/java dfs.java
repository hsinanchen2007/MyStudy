**思路**
1. 先找到A和B中两两错位的字母，进行交换。什么意思呢。比如A = "abcde", B = "debac",A中的a和d，与B中的d和a，只要交换一次，他们就相等了。
2. 然后dfs找到剩下的最小的交换次数。大致过程如下：
有一个索引，从0开始不断右移，在某一个位置(假设为from)的时候，如果A和B在这个位置的字符相等，则继续索引右移，否则在A中往后寻找到一个满足以下两个要求的字符：首先，这个字符与B[from]相等，并且这个字符不在正确的位置上（意思是说A中的那个字符在B中相同位置的字符不同，说明他一定要被换的）。而且，满足以上要求的字符可能会存在多个，最终求得这多种方案的最小交换次数即可。

```java
class Solution {
    private int len;

    private void swap(char[] arr, int i, int j) {
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private int backTrack(int from, char[] arr1, char[] arr2) {
        if (from == len) {
            return 0;
        }

        if (arr1[from] == arr2[from]) {
            return backTrack(from + 1, arr1, arr2);
        }

        int min = Integer.MAX_VALUE;
        for (int i = from + 1; i < len; i++) {
            if (arr1[i] == arr2[from] && arr1[i] != arr2[i]) {
                swap(arr1, i, from);
                int res = backTrack(from + 1, arr1, arr2);
                if (res < min) {
                    min = res;
                }
                swap(arr1, i, from);
            }
        }

        return min + 1;
    }

    // 预处理 a..b  b..a的场景，交换一次即可
    private int preProcess(char[] arr1, char[] arr2) {
        int len = arr1.length;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (arr1[i] == arr2[i]) {
                continue;
            }

            for (int j = i + 1; j < len; j++) {
                if (arr1[j] == arr2[i] && arr1[i] == arr2[j]) {
                    swap(arr1, i, j);
                    count++;
                    break;
                }
            }
        }

        return count;
    }

    public int kSimilarity(String str1, String str2) {
        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();
        len = arr1.length;
        int ansCount = preProcess(arr1, arr2);
        return ansCount + backTrack(0, arr1, arr2);
    }
}
```