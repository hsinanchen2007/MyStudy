```
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> intervalList = new ArrayList<>();
        for (List<Interval> employee : schedule) {
            intervalList.addAll(employee);
        }

        intervalList.sort(Comparator.comparingInt(o -> o.start));
        List<Interval> merged = new ArrayList<>();
        // start merge
        for (int i = 1; i < intervalList.size(); i++) {
            Interval last = intervalList.get(i - 1);
            Interval current = intervalList.get(i);
            if (last.end >= current.start) {
                current.start = last.start;
                if (last.end > current.end) {
                    current.end = last.end;
                }
            } else {
                merged.add(last);
            }
            if (i == intervalList.size() - 1) {
                merged.add(current);
            }
        }
        if (merged.size() < 1) {
            return new ArrayList<>();
        }

        List<Interval> answer = new ArrayList<>(merged.size() - 1);
        for (int i = 1; i < merged.size(); i++) {
            answer.add(new Interval(merged.get(i - 1).end, merged.get(i).start));
        }
        return answer;
    }
}
```
