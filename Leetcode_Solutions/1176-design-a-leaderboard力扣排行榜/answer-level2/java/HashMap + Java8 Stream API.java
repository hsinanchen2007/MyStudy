### 解题思路

自从JAVA8加入了Lambda Expressions 和 Stream API后。就有了函数式编程的感觉了！ Oh Yeah...

### 代码

```java
class Leaderboard {

    Map<Integer, Integer> ranking;

    public Leaderboard() {
        ranking = new HashMap<>();
    }
    
    public void addScore(int playerId, int score) {
        ranking.put(playerId, ranking.getOrDefault(playerId, 0) + score);
    }
    
    public int top(int K) { // 邪恶的代码... ...
        return ranking.values()
            .stream()
            .sorted(Comparator.reverseOrder())
            .limit(K)
            .mapToInt(i -> i)
            .sum();
    }
    
    public void reset(int playerId) {
        ranking.remove(playerId);
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */
```