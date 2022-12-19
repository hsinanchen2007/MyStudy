主要思路是用TreeMap维护出现一次的区间和出现两次的区间。
在出现一次的区间中合并首尾连续以及出现包含关系的区间（出现两次的区间只需要用来判断是否冲突，可以不进行合并操作）。


    TreeMap<Integer, Integer> singleMap = new TreeMap<>();
    TreeMap<Integer, Integer> doubleMap = new TreeMap<>();

    public MyCalendarTwo() {

    }

    public boolean book(int start, int end) {
        Integer j = doubleMap.lowerKey(start);//出现两次区间中，起点小于start的
        Integer k = doubleMap.ceilingKey(start);//出现两次区间中，起点大于等于start的
        if (j != null && doubleMap.get(j) > start) {
            return false;
        }
        if (k != null && k < end) {
            return false;
        }
        Integer a = singleMap.lowerKey(start);
        Integer b = singleMap.ceilingKey(start);

        //完全没有冲突
        if ((a == null || singleMap.get(a) < start) && (b == null || b > end)) {
            singleMap.put(start, end);
            return true;
        }

        if (a == null || singleMap.get(a) < start) {
        } else {
            //与前一个区间有重叠部分，将重叠部分塞入doubleMap，同时在singleMap中合并当前区间和前一个区间
            Integer i = singleMap.get(a);
            singleMap.put(a, Math.max(end, i));
            addDouble(start, Math.min(end, i));
            start = a;
            end = Math.max(end, i);
        }

        //如果和后一个区间有冲突，冲突区域塞入doubleMap，同时在singleMap中合。
        //需要考虑当前准备插入的区间，同时包含了多个已有区间的情况，所以继续向后找
        //这里应该有优化点，直接查找后一个是比调用higherKey方法来得快的，没仔细想了
        while (b != null && b <= end) {
            Integer i = singleMap.get(b);
            addDouble(b, Math.min(end, i));
            singleMap.remove(b);
            singleMap.put(start, Math.max(end, i));
            end = Math.max(end, i);
            b = singleMap.higherKey(start);
        }

        return true;
    }

    public void addDouble(int start, int end) {
        if (start >= end) {
            return;
        }
        doubleMap.put(start, end);
    }
