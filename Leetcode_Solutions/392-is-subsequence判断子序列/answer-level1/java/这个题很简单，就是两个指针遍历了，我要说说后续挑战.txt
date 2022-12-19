后续挑战，有大量的S，T不变，这种情况下很明显，得空间换时间，具体怎么个换法呢。
可以建表解决，设定这样一个二维数组，每行的数组分别对应一个字符，将T的某个位置的下一个该字符的位置存入数组中

比如： T=abcbbacbbdcca，T长度有13，字符集为：a/b/c/d
建立4行14列的二维数组new int[4][14]，加入第i列表示a，那么arr[i][j]表示T[j]位置开始的下一个a字符的位置
```
T index -1  0   1   2   3   4   5   6   7   8   9   10  11  12
T char      a   b   c   b   b   a   c   b   b   d   c   c   a

index   0   1   2   3   4   5   6   7   8   9   10  11  12  13

a       0   5   5   5   5   5   12  12  12  12  12  12  12  -1
b       1   1   3   3   4   7   7   7   8   -1  -1  -1  -1  -1 
c       2   2   2   6   6   6   6   10  10  10  10  11  -1  -1
d       9   9   9   9   9   9   9   9   9   9   -1  -1  -1  -1
```
建立这样的一个二维数组表，时间复杂度为字符集大小 * (T长度 + 1)

当查询字符串S=bcdcb时的步骤，序列从0开始计数
> 1. 取S第0个字符为b，对应第1行，取arr[1][-1 + 1]=1
> 2. 取S第1个字符为c，对应第2行，取arr[2][1 + 1]=2
> 3. 取S第2个字符为d，对应第3行，取arr[3][2 + 1]=9
> 4. 取S第3个字符为c，对应第2行，取arr[2][9 + 1]=10
> 5. 取S第5个字符为b，对应第1行，取arr[1][10 + 1]=-1，值为-1，所以不存在b，字符串S不是T子序列


由于题目没有限定字符集，所以得自己生成一次字符集，如果有限制是26英文字母，数组可以直接是new int[26][]

java 代码如下，如果是多次使用一般是调用一次compile，后面检测都调用test

```java
class Solution {

    Map<Character, Integer> map;

    int[][] nextPositions;

    public void compile(String t) {
        map = new HashMap<>();
        char[] chars = t.toCharArray();
        int idx = 0;
        for (char c : chars) {
            Integer hash = map.get(c);
            if (hash == null) {
                map.put(c, idx);
                idx++;
            }
        }

        nextPositions = new int[idx][];
        int tlen = chars.length;
        for (int i = 0; i < idx; i++) {
            nextPositions[i] = new int[tlen + 1];
            Arrays.fill(nextPositions[i], -1);
        }

        int[] counts = new int[idx];
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            
            int hash = map.get(c);
            int p = counts[hash];
            for (; p <= i; p++) {
                nextPositions[hash][p] = i;
            }
            counts[hash] = p;
        }
    }

    public boolean test(String s) {
        int pos = -1;
        for (char c : s.toCharArray()) {
            Integer hash = map.get(c);
            if (hash == null) {
                return false;
            }
            pos = nextPositions[hash][pos + 1];
            
            if (pos == -1) {
                return false;
            }
        }
        return true;
    }

    public boolean isSubsequence(String s, String t) {
        compile(t);

        return test(s);
    }
}
```