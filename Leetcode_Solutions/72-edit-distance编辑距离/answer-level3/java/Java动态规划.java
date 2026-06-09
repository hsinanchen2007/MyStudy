
```
int[][] cost = new int[word1.length()+1][word2.length()+1];
    for (int i = 0; i <= word2.length(); i++) {
      cost[0][i] = i;
    }
    for (int i = 0; i <= word1.length(); i++) {
      cost[i][0] = i;
    }

    for (int i = 1; i <= word1.length(); i++) {
      for (int j = 1; j <= word2.length(); j++) {
        int minCost = Math.min(cost[i-1][j], cost[i][j-1]) + 1;
        if (word1.charAt(i-1) == word2.charAt(j-1)) {
          minCost = Math.min(minCost, cost[i-1][j-1]);
        }
        else {
          minCost = Math.min(minCost, cost[i-1][j-1] + 1);
        }
        cost[i][j] = minCost;
      }
    }
    return cost[word1.length()][word2.length()];
```
