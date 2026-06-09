### 解题思路
感觉就是道模拟题，题目读懂就能写了

### 代码

```java
class TweetCounts {
    
    Map<String, List> m = new HashMap<>();

    public TweetCounts() {
        
    }
    
    public void recordTweet(String tweetName, int time) {
        if (m.containsKey(tweetName)) {
            List l = m.get(tweetName);
            l.add(time);
        } else {
            List<Integer> l = new ArrayList<>();
            l.add(time);
            m.put(tweetName, l);
        }
    }
    
    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        List<Integer> res = new ArrayList<>();
        if (m.containsKey(tweetName)) {
            List<Integer> l = (List<Integer>)m.get(tweetName);
            int dis = 0;
            if (freq.equals("minute")) dis = 60;
            else if (freq.equals("hour")) dis = 3600;
            else dis = 24 * 3600;
            int delta;
            delta = (endTime - startTime) / dis + 1;
            for (int i = 0; i < delta; i++) {
                int sum = 0;
                for (int a : l) {
                    if (a >= startTime + i * dis && a < Math.min((startTime + (i + 1) * dis), endTime + 1)) sum++;
                }
                res.add(sum);
            }
            return res;
        } else {
            return res;
        }
    }
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```