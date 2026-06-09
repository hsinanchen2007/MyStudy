class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
    	List<Interval> res = new LinkedList<>();
    	
        List<Interval> intervalList = new ArrayList<>();
        for (List<Interval> employee : schedule) {
            intervalList.addAll(employee);
        }

    	PriorityQueue<Interval> pq = new PriorityQueue<>((o1, o2) -> o1.start != o2.start ? o1.start - o2.start : o2.end - o1.end);

    	for (int i = 0; i < intervalList.size(); i++) {
    		pq.add(intervalList.get(i));
    	}
    	
    	Interval baseInterval = new Interval(Integer.MIN_VALUE, -1);
    	while (!pq.isEmpty()) {
    		Interval intver = pq.poll();
    		if (intver.start - baseInterval.end > 0) {
    			res.add(new Interval(baseInterval.end, intver.start));
    			baseInterval.end = intver.end;
    		} else if (intver.start - baseInterval.end == 0) { 
    			baseInterval.end = intver.end;
    		} else if (intver.end - baseInterval.end > 0) {
    			baseInterval.end = intver.end;
    		}
    	}
    	res.remove(0);
    	return res;
    }
}