### 解题思路
1.用一个map来记录用户发布的全部推文
2.推文发布存在时间的先后顺序，这时候可以想到treeMap是一个天生有序的集合
3.这里为什么用treeMap而不是treeSet呢，因为会存在一个用户在同一个时间多次调用recordTweet，这样推文的数目就不是简单的1个，而是会有多个的存在，于是再用一个空间，在存储在time的时间，发布了多少条推特。

用TreeMap比用List时间复杂度更低一些，因为用**TreeMap**查找记录，直接通过**二分查找定位**，这一步节省了很多时间，定位到开始的位置之后，接着就是迭代查找后继了（这明明就是跳表呀）。

本人提交记录来看，用treeMap的时间消耗在170ms-190ms，而用list的时间消耗450ms。时间的优化还是蛮可观的。

![QQ图片20200110144421.png](https://pic.leetcode-cn.com/71cdab6c33c803047d9391eb22274e0a93d91c3241bcbae5692f4872661d8c42-QQ%E5%9B%BE%E7%89%8720200110144421.png)

不过本人觉得构造**跳表**的化，时间应该比用treeMap更快。插入的时候就是二分插入保证有序，遍历的时候，一样二分查找到start，然后往后遍历。十分符合跳表的思想。有意愿的同学可以尝试一下构造跳表来解决。

ps:这个题恶心的大家都知道了，线上bug，测试用例和显示的不一样。

### 代码

```java
class TweetCounts {

    // key 用户->推文时间->该时间推文发布数目
    private Map<String, TreeMap<Integer,Integer>> userTweetMap;
    
    public TweetCounts() {
        userTweetMap = new HashMap<>();
    }

    // 发布推文
    public void recordTweet(String tweetName, int time) {
        // 当前用户推文集合
        TreeMap<Integer, Integer> tweetMap = userTweetMap.computeIfAbsent(tweetName, k -> new TreeMap<>());
        // 推文时间记录，比之前次数多1
        tweetMap.put(time,tweetMap.getOrDefault(time,0) + 1);// 推文加入
    }

    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        List<Integer> res = new ArrayList<>();
        if (!userTweetMap.containsKey(tweetName)){
            res.add(0);
            return res;
        }
        int freqTime = 1;
        if ("minute".equals(freq)){
            freqTime = 60;
        }else if ("hour".equals(freq)){
            freqTime = 3600;
        }else if ("day".equals(freq)){
            freqTime = 86400;
        }
        // 用户的全部推文时间集合
        TreeMap<Integer,Integer> tweetMap = userTweetMap.get(tweetName);
        int start = startTime;
        int end = Math.min(start + freqTime,endTime + 1);
        while (start <= endTime){
            int count = 0;
            // 找到发文时间大于等于start的推文
            Map.Entry<Integer,Integer> entry = tweetMap.ceilingEntry(start);
            while (entry != null && entry.getKey() < end){
                count += entry.getValue();// 推文数累加
                // 找比当前大的推文时间
                entry = tweetMap.higherEntry(entry.getKey());
            }
            res.add(count);
            // 时间后移
            start = end;
            end = Math.min(end + freqTime,endTime + 1);
        }
        return res;
    }
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```