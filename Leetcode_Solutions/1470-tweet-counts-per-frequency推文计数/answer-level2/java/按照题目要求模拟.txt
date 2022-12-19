```
class TweetCounts {
	Map<String, List<Integer>> map = new HashMap<>();

	public TweetCounts() {

	}

	public void recordTweet(String tweetName, int time) {
		if (map.get(tweetName) == null) {
			map.put(tweetName, new ArrayList<>());
		}
		List<Integer> list = map.get(tweetName);
		list.add(time);
		Collections.sort(list);
		map.put(tweetName, list);
	}

	public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName,
													int startTime, int endTime) {
		List<Integer> results = new ArrayList<>();
		List<Integer> tweets = map.get(tweetName);
		int interval;
		switch (freq) {
			case "minute":
				interval = 60;
				break;
			case "hour":
				interval = 60 * 60;
				break;
			default:
				interval = 60 * 60 * 24;
				break;
		}

		for (int time = startTime; time <= endTime; time += interval) {
			int begin = time;
			int end = Math.min(time + interval, endTime + 1);
			long count = tweets.stream().filter(t -> t >= begin && t < end).count();
			results.add((int) count);
		}
		return results;
	}
}
```
