我们假设dp[i][j][k] 表示到达第ｉ个字符时，第一根手指在字符ｊ上，第二根手指在字符ｋ上，这种情况下的最小移动次数　
（设word第一个字母的下标从１开始）
```
const int INF = (int)1e9 + 10;

int dp[335][26][26]; // dp[i][j][k]表示到达第i个字符时，第一个手指在第j号字母上，第二个手指在第k号字母上花费的最小值
pair<int,int> position[26];
int dist[26][26];

int minimumDistance(string word) {
  for (int i = 0; i < 26; i++) {
    position[i] = {i / 6, i % 6};
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      dist[i][j] = abs(position[i].first - position[j].first) + abs(position[i].second - position[j].second);
    }
  }
  for (int i = 0; i <= 300; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  //i = 0的时候，表示在第一个字符之前，手指无论放在哪个字符上的代价都是０，因为起始位置是零代价的，不计入移动总距离，
  for (int j = 0; j < 26; j++) {
    for (int k = 0; k < 26; k++) {
      dp[0][j][k] = 0;
    }
  }
  for (int i = 0; i < (int)word.size(); i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        int f = (int)(word[i] - 'A');
        dp[i + 1][f][k] = min(dp[i + 1][f][k], dp[i][j][k] + dist[j][f]); // 更新第一根手指从ｊ移动到ｆ的最小代价
        dp[i + 1][j][f] = min(dp[i + 1][j][f], dp[i][j][k] + dist[k][f]);// 更新第二根手指从ｋ移动到ｆ的最小代价
      }
    }
  }
  int Min = INF;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      Min = min(Min, dp[(int)word.size()][i][j]);
    }
  }
  return Min;
}
```



