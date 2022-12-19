class Solution {
    public int[][] findContinuousSequence(int target) {
        if(target == 1){
            return new int[0][0];
        }

        int maxT = target / 2;
        int doubleT = target * 2;
        TreeMap<Integer, Integer> result = new TreeMap<>();
        for (int i = 1; i < maxT; i++) {
            for (int j = 2; j < maxT; j++) {
                int temp = j * (i + i + j - 1);
                if(temp == doubleT){
                    result.put(i, j);
                }else if(temp > doubleT){
                    break;
                }
            }
        }
        if(target % 2 == 1){
            result.put(maxT, 2);
        }

        int[][] res = new int[result.size()][];
        AtomicInteger index = new AtomicInteger();
        result.forEach((k, v)->res[index.getAndIncrement()] = buildSeq(k, v));
        
        return res;
    }
    public int[] buildSeq(int s, int c){
        int[] r = new int[c];
        int i = 0;
        for (int j = 0; j < c; j++) {
            r[i++] = s + j;
        }
        return r;
    }
}