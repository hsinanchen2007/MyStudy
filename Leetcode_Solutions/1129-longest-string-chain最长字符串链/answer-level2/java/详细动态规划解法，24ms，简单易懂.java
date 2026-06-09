## 分析：

- 动态规划题。
- 首先先把数组按照每一个字符串的长度排一下序，这样为了词链短的一定在前面，而后面的则可能有更长的词链。
- 然后我们再来看题目所说的前身，我认为就是前者是后者的子序列并且前后之间的长度就相差1
- 那么这样就很简单了，LeetCode有判断子序列的题(见392题)。
- 那么现在的问题是我要怎找状态，其实很简单。
- 状态就是当前位置字符串的词链长度，而转移方程就是从当前字符串长度-1的字符串中去找哪些符合子序列，符合就将它的词链长度+1和自己比较。
- 那么又出现了另一个问题，就是怎么找到长度为当前字符串-1的字符串。
- 我自己的方法是开辟一个长度17的数组(因为最长字符串为16),然后把它们的下标放在它们对应的长度位置上，覆盖之前的下标。
- 那么这样就能找到任意一个字符串长度的最后一个位置下标，由于数组按长度排序，那么它之前的也都是和它长度一样的字符串。
- 另一种方法是用Hash表，把长度一样的放在一起。
- 另外：由于我实在不会用Java的用关键字排序，所以自己实现了一个按字符串长度的快速排序，速度还不错。
- 如果有谁知道java怎么按照关键字排序，麻烦告诉我一声。。。。

## 代码：

```java
class Solution {
    public int longestStrChain(String[] words) {
        int len = words.length;
        quickSort(words, 0, len - 1);
        int[] cnt = new int[17];
        Arrays.fill(cnt, -1);//-1就是不存在这样长度的字符串。
        for (int i = 0; i < len; i++) cnt[words[i].length()] = i;//存储长度一样的字符串最后那个的下标
        int[] dp = new int[len];
        Arrays.fill(dp, 1);//每个单词的词链至少也为1
        int ans = 1;
        for (int i = 0; i < len; i++) {
            int tarlen = words[i].length() - 1;//当前长度为words[i].length()，我要找比它小1的长度。
            int index = cnt[tarlen];//取出长度一样的最后那个下标
            if (index == -1) {//取不到说明没有这个长度的字符串，那么当前字符串的词链只可能是1。
                dp[i] = 1;
            } else {
                while (index >= 0 && words[index].length() == tarlen) {//长度一样的都检查一遍是不是子序列，注意下标不要越界。
                    if (check(words[index], words[i])) dp[i] = Math.max(dp[i], dp[index] + 1);
                    --index;
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }

    public boolean check(String s1, String s2) {//检查s1是否是s2的子序列，详情看392题
        int index = -1;
        for (char ch : s1.toCharArray()) {
            index = s2.indexOf(ch, index + 1);
            if (index == -1) return false;
        }
        return true;
    }

    public void quickSort(String[] A, int st, int en) {//快速排序，没什么好说的。
        if (st < en) {
            int point = partition(A, st, en);
            quickSort(A, st, point - 1);
            quickSort(A, point + 1, en);
        }
    }

    public int partition(String[] A, int st, int en) {
        Random r = new Random();
        int pivot = r.nextInt(en - st) + st + 1;
        String tmp = A[pivot];
        A[pivot] = A[en];A[en] = tmp;
        pivot = A[en].length();
        int i = st - 1;
        for (int j = st; j < en; j++) {
            if (A[j].length() < pivot) {
                tmp = A[j];
                A[j] = A[++i];
                A[i] = tmp;
            }
        }
        tmp = A[i+1];
        A[i+1] = A[en];
        A[en] = tmp;
        return i + 1;
    }
}
```