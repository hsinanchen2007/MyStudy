### 解题思路
本人菜鸡，想不到很厉害的解法，借助哈希表写了一个，希望能起到一些参考价值。
1. 首先定义两个哈希表和表示时间顺序的变量 time：
    **推特表 tweet** : Integer 用来存储用户id，int[] text 用来存储用户发的文章，text[0] 为所属用户的标号，text[1] 为 time；
	**用户关注表 follow** : Integer 用来存储某用户的Id，List<Integer> 用来存储该用户的关注列表；
2. *postTweet()、follow()、unfollow()* 三个函数为 void，按照要求操作，注意一些用例可能出现的问题即可；
3. **getNewsFeed()** 首先获取**目前所有的推文**存入 List<int[]> res 中，再**按照 time 的值降序排序**，获取最前面的10个（或不足10个）添加入 List<Integer> ans 中，并最终返回结果（此处感觉可以优化）。

再说说解题过程中遇到的一些用例吧，有以下几个情况要注意：
```
1. 一个用户关注了别的用户，但是自己没有发推文；
2. 用户可以关注自己；
3. 用户关注的用户没发过推特；
3. 用户可以取关自己没有关注的人（即不需要先关注用户才能取关），包括自己；
4. 一通操作所有的用户一篇推文都没发；
```
呃，就是这样，希望能起到一点参考作用。如果有什么错误或者可以继续优化的地方，欢迎各位大佬批评和指导。

### 代码

```java
class Twitter {
	Map<Integer,List<int[]>> tweet; /* 推特表 */
	Map<Integer,List<Integer>> follow; /* 用户关注表 */
	int time; /* 标注推文发送的时间 */
    /** Initialize your data structure here. */
    public Twitter() {
    	time = 0;
    	tweet = new HashMap<>();
    	follow = new HashMap<>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
    	if(!tweet.containsKey(userId)) { /* 这个用户之前没有发送推文 */
    		List<int[]> list = new ArrayList<>();
    		int[] text = new int[2];
    		text[0] = tweetId;text[1] = time;
    		list.add(text);
    		tweet.put(userId,list);
    	}
    	else { /* 用户已经发过推文 */
    		List<int[]> list = tweet.get(userId);
    		int[] text = new int[2];
    		text[0] = tweetId;text[1] = time;
    		list.add(text);
    	}
    	time++; 
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
    	List<int[]> res = new ArrayList<>(); /* 获取推文 */
        List<Integer> ans = new ArrayList<>(); /* 保存目标推文并返回 */
        if(tweet.containsKey(userId)) { /* userId用户发过推文 */
            res.addAll(tweet.get(userId));
        }
    	if(follow.containsKey(userId)) { /* userId用户关注过别人 */
    		for(int i = 0;i < follow.get(userId).size();i++) {
    			if(tweet.containsKey(follow.get(userId).get(i))) { /* 关注的用户发过推文才加上 */
    				List<int[]> list = tweet.get(follow.get(userId).get(i));
    				res.addAll(list);
    			}
    		}
    	}
    	Collections.sort(res, new Comparator<int[]>() { /* 按照time的值对res进行降序排序 */
			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				return o2[1] - o1[1];
			}
    	});
    	while(res.size() != 0 && ans.size() < 10) {
    		int temp = res.remove(0)[0];
    		if(!ans.contains(temp)) ans.add(temp);
    	}
    	return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
    	if(!follow.containsKey(followerId)) { /* 用户没关注过别人 */
    		List<Integer> list = new ArrayList<>();
    		list.add(followeeId);
    		follow.put(followerId,list);
    	}
    	else { /* 用户已经关注过别人 */
    		List<Integer> list = follow.get(followerId);
    		list.add(followeeId);
    		follow.put(followerId,list);
    	}
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
    	List<Integer> list = follow.get(followerId);
    	if(list == null) return; /* 没人关注过别人的情况直接结束 */
    	for(int i = 0;i < list.size();i++) {
    		if(list.get(i) == followeeId) { 
    			list.remove(i);break;
    		}
    	}
    	follow.put(followerId,list);
    }
}
```