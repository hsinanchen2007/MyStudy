### 解题思路
其实本质上还是一个排序问题，只不过这一次排序的思路不是比较两个队的大小，而是有一个特殊的排序规则。另一个难点就是如何定义一个合适的数据结构。这里我们可以定义一个二维数组，数组的列表示名次，而行则用来记录每个队在该名次得到的票数。比如，cnt[1][1] = 2，就表示B被投了2次第二名。

### 代码

```c
int cnt[30][30];

bool cmp(char a, char b) {
    a -= 'A', b -= 'A';
    for (int i = 0; i < 26; ++i) {
        if (cnt[a][i] > cnt[b][i]) return true;
        if (cnt[a][i] < cnt[b][i]) return false;
    }
    return a < b;
}

void swap(char *s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

char * rankTeams(char ** votes, int votesSize){
    int len = strlen(votes[0]);

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < votesSize; ++i) {
        for (int j = 0; j < len; ++j) {
            cnt[votes[i][j] - 'A'][j]++;
        }
    }

    char *ans = votes[0];
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (!cmp(ans[i], ans[j])) {
                swap(ans, i, j);
            }
        }
    }
    return ans;
}
```