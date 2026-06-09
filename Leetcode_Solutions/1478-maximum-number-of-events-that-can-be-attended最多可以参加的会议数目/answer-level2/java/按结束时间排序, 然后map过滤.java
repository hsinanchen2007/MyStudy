class Solution {
    public int maxEvents(int[][] events) {
        
        int eventLength = events.length;
        if(eventLength == 1)
            return 1;
        // 构造一个map, 记录当前是否已经参加会议
        Map<Integer, Boolean> map = new HashMap<>();
        // 按照结束时间排序, 结束时间相同的开始时间早的在前
        Arrays.sort(events, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                if (o1[1]==o2[1]) return o1[0]-o2[0];
                return o1[1]-o2[1];
            }
        });
        
        // 遍历
        for(int i = 0; i < eventLength; i++) {
            
            // 如果当天没有参加过会议, 则添加该次会议的开始时间
            if(map.get(events[i][0]) == null) {
                map.put(events[i][0], true);
            }else {
                // 否则的话遍历结束时间范围
                int start = events[i][0];
                int end = events[i][1];
                while(end > start) {
                    start++;
                    // 如果在返回内有时间则参加会议, 并break
                    if(map.get(start) == null) {
                        map.put(start, true);
                        break;
                    }
                }
            }
        }
        // 最后返回总共参加了多少会议
        return map.size();
    }
}