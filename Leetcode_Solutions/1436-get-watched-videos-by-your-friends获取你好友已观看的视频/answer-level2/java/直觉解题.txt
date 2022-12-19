解题思路：
1.遍历每一层朋友，直到遍历到给定层次
2.统计给定层次所有朋友观看的视频，并排序

public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        List<Integer> lastLevelIds = new ArrayList<Integer>();
        lastLevelIds.add(id);
        map.put(id,0);
        List<Integer> currentLevelIds = new ArrayList<Integer>();
        
        for (int i = 1; i <= level; i++) {
            for (int j : lastLevelIds) {
                for (int tmpid : friends[j]) {
                    if (!map.containsKey(tmpid)) {
                        map.put(tmpid,i);
                        currentLevelIds.add(tmpid);
                    }
                }
            }
            lastLevelIds = currentLevelIds;
            currentLevelIds = new ArrayList<Integer>();
        }
        Map<String,Integer> videoMaps = new HashMap<String, Integer>();
        for (int tmpid : lastLevelIds) {
            for (String video : watchedVideos.get(tmpid)) {
                if (videoMaps.containsKey(video)) {
                    videoMaps.put(video, videoMaps.get(video) + 1);
                } else {
                    videoMaps.put(video, 1);
                }
            }
        }
        Comparator<Map.Entry<String, Integer>> c = new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if (o1.getValue().intValue() == o2.getValue().intValue()) {
                    return o1.getKey().compareTo(o2.getKey());
                } else {
                    return o1.getValue() - o2.getValue();
                }
            }
        };
        List<Map.Entry<String, Integer>> ls = new ArrayList<Map.Entry<String, Integer>>(videoMaps.entrySet());
        Collections.sort(ls, c);
        List<String> r = new ArrayList<>();
        for (Map.Entry<String, Integer> item : ls) {
            r.add(item.getKey());
        }
        return r;
    }
直观思路解题，没有优化，后面可以用优先级队列，代码更简单些