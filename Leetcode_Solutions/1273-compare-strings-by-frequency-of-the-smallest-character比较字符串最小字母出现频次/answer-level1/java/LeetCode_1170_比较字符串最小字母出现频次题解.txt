### 解题思路

首先计算出queries和words的f()值，之后查找符合`f(queries[i]) < f(W)`的个数即可。使用二分查找可提高速度，注意边界条件，即words中没有比f(queries)小的数字。

### 代码

```java
class Solution {
public int[] numSmallerByFrequency(String[] queries, String[] words) {
        // answer[i] 满足 f(queries[i]) < f(w)的词的数据， W是词汇表Words中的词

        int[] answer = getAns(queries);

        int[] wordAns = getAns(words);

        Arrays.sort(wordAns);

        int[] ans = new int[queries.length];
        for (int i = 0; i < answer.length; i++) {
            int l = 0;
            int r = wordAns.length - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (wordAns[mid] <= answer[i]) l = mid + 1;
                else r = mid;
            }

            if (wordAns[l] <= answer[i]) {
                ans[i] = 0;
            } else {
                ans[i] = (wordAns.length - r);
            }
        }

        return ans;
    }

    private int[] getAns(String[] queries) {
        int[] answer = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {
            answer[i] = f(queries[i]);
        }
        return answer;
    }

    private int f(String query) {
        // 拿到字符串中最小的字符
        char minChar = 'z';
        for (int i = 0; i < query.length(); i++) {
            if (query.charAt(i) < minChar) {
                minChar = query.charAt(i);
            }
        }

        int count = 0;
        for (int i = 0; i < query.length(); i++) {
            if (query.charAt(i) == minChar) {
                count ++;
            }
        }

        return count;
    }
}
```