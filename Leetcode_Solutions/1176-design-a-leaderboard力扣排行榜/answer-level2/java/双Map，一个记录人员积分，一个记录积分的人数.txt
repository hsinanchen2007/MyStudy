### 解题思路

1.一个Map作为playId和对应score的映射，找到对应人数的积分
2.另一个TreeMap实现score的排序，和记录当前score上有多少个用户，然后统计top K

因为TreeMap天生是一个二分有序，查找元素很快，每次从最大的开始，然后找前驱即可。

效率方面，非常高效，10ms左右
![1111.png](https://pic.leetcode-cn.com/3114ded9d02764147b2288c4eb8856eca4ab31c0bad0e9b0d5ce97fb05d7be3c-1111.png)


### 代码

```java
class Leaderboard {

    // key 人员 value 分数
    private Map<Integer,Integer> m_rank;
    // key 分数 value 同分人数
    private TreeMap<Integer,Integer> m_score;// 分数

    public Leaderboard() {
        m_rank = new HashMap<>();
        m_score = new TreeMap<>();
    }

    public void addScore(int playerId, int score) {
        Integer oldScore = m_rank.get(playerId);
        if (oldScore != null) {
            // 旧积分人数处理
            oldScoreNumProcess(oldScore);
            score += oldScore;
        }
        // 选手分数更新
        m_rank.put(playerId,score);
        // 分数排名更新
        m_score.put(score,m_score.getOrDefault(score,0) + 1);
    }

    private void oldScoreNumProcess(int score){
        int scoreNum = m_score.get(score);
        if (scoreNum <= 1){
            // 该积分没有人了，积分移除
            m_score.remove(score);
        } else {
            // 该积分人数减一
            m_score.put(score,scoreNum - 1);
        }
    }
    
    public int top(int K) {
        int sumScore = 0;
        // 最大的积分
        Map.Entry<Integer,Integer> scoreEntry = m_score.lastEntry();
        while (K > 0 && scoreEntry != null){
            // key 分数 value 人数
            // 积分人数如果大于K了，取K个人，否则全部取出
            int num = Math.min(scoreEntry.getValue(),K);
            // 分数*数量
            sumScore += scoreEntry.getKey() * num;
            // 分数前移，找小的
            scoreEntry = m_score.lowerEntry(scoreEntry.getKey());
            K-= num;
        }
        return sumScore;
    }

    public void reset(int playerId) {
        // 选手积分
        int score = m_rank.get(playerId);
        // 选手积分清零
        m_rank.put(playerId,0);
        // 积分人数处理
        oldScoreNumProcess(score);
        // 0分人数+1
        m_score.put(0,m_score.getOrDefault(0,0) + 1);
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