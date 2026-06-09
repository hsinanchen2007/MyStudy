用Java代码，时间一般击败98%左右，内存在50%多到98%之间波动。

public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) return new int[0][0];
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            list.add(new int[]{intervals[i][0], intervals[i][1]});
        }
/*
        Collections.sort(list, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                int s1 = o1[1] - o1[0];
                int s2 = o2[1] - o2[0];
                if(s1 > s2) return -1;
                else if(s1 < s2) return 1;
                return 0;
            }
        });
*/
        boolean fresh = false;
        int start = 0;
        while (start < list.size()) {
            fresh = false;
            int[] data = list.get(start);
            for (int i = list.size() - 1; i > start; i--) {
                int[] tem = list.get(i);
                if (data[0] <= tem[0] && data[1] >= tem[0] || data[0] >= tem[0] && data[0] <= tem[1]) {
                    data[0] = Math.min(data[0], tem[0]);
                    data[1] = Math.max(data[1], tem[1]);
                    list.remove(i);
                    fresh = true;
                }
            }
            if(!fresh){
                start++;
            }
        }

        int[][] result = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }
        return result;

    }

没用什么技巧，就是遍历合并，然后删除
中间注释到那块我认为能提高效率，但在leetcode上反而降低了。
我有个思路，就是在一个数轴上把所有但区间都标志好，然后加上left，和right都标志，然后统计left和right的数量，当两个相等时，就认为找到了一个区间，但这个方法才击败70%左右但人。
我认为后面但两个都比第一个好，尤其是数量越多会越好，但提交后效率都不高，希望有大神能完善下这个思路。