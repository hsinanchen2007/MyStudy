使用桶排序
    public int findMinDifference(List<String> timePoints) {
        boolean[] times =new boolean[1440];
        for(String point : timePoints) {
            String[] args = point.split(":");
            int minutes = Integer.parseInt(args[0]) * 60 + Integer.parseInt(args[1]);
            if(times[minutes]) {
                return 0;
            }
            times[minutes] = true;
        }
        times = concat(times, times);
        int min = 2880;
        int length;
        int start = -1;
        for (int i = 0; i< 2880;i++) {
            if(!times[i]) {
                continue;
            }
            if(start == -1) {
                start = i;
                continue;
            }
            length = i - start;
            if(length < min) {
                min = length;
            }
            start = i;
        }
        return min;
    }
    static boolean[] concat(boolean[] a, boolean[] b) {
        boolean[] c= new boolean[a.length+b.length];
        System.arraycopy(a, 0, c, 0, a.length);
        System.arraycopy(b, 0, c, a.length, b.length);
        return c;
    }