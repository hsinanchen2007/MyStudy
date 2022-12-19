### 解题思路
通过二维数组表示每个参赛团队每个名次的得票，其中行i表示每个参赛团队，列j表示团队得到第j-1名，数组的最后一列表示团队名（字母对应的整数值）。由于团队名为英文大写字母，因此可以用int[][] cnt = new int[26][27];表示。

例如votes = ["ABC","ACB","ABC","ACB","ACB"]可表示为：
```
   0  1  2  3
A  5  0  0  65
B  0  2  3  66
C  0  3  2  67
```

然后使用Arrays.sort()对二维数组进行排序，比较器中首先找到两个一维数组不相同的元素，位置为i：
- 如果i=o1.length，此时数组没有不相同元素（因为每行最后一列为字母值，所以如果没有不同元素，说明该行值都为0），返回0；
- 如果i=o1.length-1，此时两个团队排名都一致，通过字母顺序排序，即最后一列递增顺序；
- 否则，根据排名递减顺序排序。

最后遍历二维数组每一行，拼接最后一列的字母值，即得到所有团队排名的字符串。

### 代码

```java
class Solution {
    public String rankTeams(String[] votes) {
        if (votes.length == 1) return votes[0];

        int[][] cnt = new int[26][27];
        for (String vote : votes) {
            for (int j = 0; j < vote.length(); j++) {
                cnt[vote.charAt(j) - 'A'][j]++;
                cnt[vote.charAt(j) - 'A'][26] = vote.charAt(j);
            }
        }

        Arrays.sort(cnt, (o1, o2) -> {
            int i = 0;
            while (i < o1.length && o1[i] == o2[i]) {
                i++;
            }

            if (i == o1.length) {
                return 0;
            }

            if (i == o1.length - 1) {
                return o1[i] - o2[i];
            }

            return o2[i] - o1[i];
        });

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            if (cnt[i][26] == 0) continue;
            sb.append((char) (cnt[i][26]));
        }
        return sb.toString();
    }
}
```