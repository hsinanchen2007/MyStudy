class Solution {
    int low1 = Integer.MAX_VALUE;
    int low2 = Integer.MAX_VALUE;
    int high1;
    int high2;
    Map<Integer, Map<Integer, int[]>> data = new HashMap<>(500);
    int lng = 0;

    LinkedList<int[]> baseA = new LinkedList<>();
    LinkedList<int[]> baseB = new LinkedList<>();
    LinkedList<int[]> baseC = new LinkedList<>();

    public boolean isRectangleCover(int[][] rectangles) {
        for (int[] tmp : rectangles) {
            boolean flag = initData(tmp);
            if (!flag) {
                return false;
            }
        }
        baseA.add(new int[]{low1, low2, high1, high2});
        return isPerfect();
    }

    public int[] getOne(int lowX, int lowY) {
        Map<Integer, int[]> tmp = data.get(lowX);
        if (tmp == null) {
            return null;
        } else {
            if (tmp.containsKey(lowY)) {
                int[] res = tmp.get(lowY);
                tmp.remove(lowY);
                lng--;
                return res;
            }
            return null;
        }
    }

    public boolean addOne(int[] tmp) {
        int lowX = tmp[0];
        int lowY = tmp[1];
        if (!data.containsKey(lowX)) {
            Map<Integer, int[]> insert = new HashMap<>();
            insert.put(lowY, tmp);
            data.put(lowX, insert);
            lng++;
            return true;
        }
        Map<Integer, int[]> hasInsert = data.get(lowX);
        if (hasInsert.containsKey(lowY)) {
            return false;
        }
        hasInsert.put(lowY, tmp);
        lng++;
        return true;
    }

    private boolean initData(int[] tmp) {
        if (tmp[0] < low1) {
            low1 = tmp[0];
        }
        if (tmp[1] < low2) {
            low2 = tmp[1];
        }
        if (tmp[2] > high1) {
            high1 = tmp[2];
        }
        if (tmp[3] > high2) {
            high2 = tmp[3];
        }
        return addOne(tmp);
    }

    public boolean isPerfect() {
        while (!baseA.isEmpty() && lng != 0) {
            boolean oneFind = false;
            for (int[] tmp : baseA) {
                int[] ps = getOne(tmp[0], tmp[1]);
                if (ps != null) {
                    oneFind = true;
                    if (ps[2] == tmp[2] && ps[3] == tmp[3]) {
                        continue;
                    }
                    if (ps[3] == tmp[3]) {
                        tmp[0] = ps[2];
                        tmp[1] = ps[1];
                        baseB.add(tmp);
                        continue;
                    }
                    if (ps[2] == tmp[2]) {
                        if (ps[3] > tmp[3]) {
                            //增加
                            tmp[1] = tmp[3];
                            tmp[2] = ps[2];
                            tmp[3] = ps[3];
                            boolean f = addOne(tmp);
                            if (!f) {
                                return false;
                            }
                        } else {
                            //单
                            tmp[0] = ps[0];
                            tmp[1] = ps[3];
                            baseB.add(tmp);
                        }
                        continue;
                    } else {
                        if (ps[3] > tmp[3]) {
                            //增加双
                            int ps2 = ps[2];
                            int ps1 = ps[1];
                            ps[0] = tmp[0];
                            ps[1] = tmp[3];
                            boolean f = addOne(ps);
                            if (!f) {
                                return false;
                            }
                            tmp[0] = ps2;
                            tmp[1] = ps1;
                            baseB.add(tmp);
                        } else {
                            //单
                            int ps0 = ps[0];
                            int ps2 = ps[2];
                            int ps3 = ps[3];
                            int tmp2 = tmp[2];
                            tmp[0] = ps0;
                            tmp[1] = ps3;
                            baseB.add(tmp);
                            ps[0] = ps2;
                            ps[2] = tmp2;
                            baseB.add(ps);
                        }
                        continue;
                    }

                } else {
                    baseB.add(tmp);
                    continue;
                }
            }
            if (!oneFind) {
                return false;
            }
            baseC = baseA;
            baseA = baseB;
            baseB = baseC;
            baseB.clear();
        }
        if (baseA.isEmpty() && lng == 0) {
            return true;
        }
        return false;
    }
}