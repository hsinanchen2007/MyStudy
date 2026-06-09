1、逐级获取盒子
2、获取盒子对应的钥匙
3、遍历盒子。如果对应盒子已打开，则获取对应糖果；如果对应盒子关闭，则查看是否有相应钥匙，有则获取糖果。

class Solution {


    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int max = 0;
        if (initialBoxes.length == 0) {
            return 0;
        }

        Set<Integer> containers = new HashSet<>();
        for (int boxes : initialBoxes) {
            containers.add(boxes);
            queryBoxes(containedBoxes, boxes, containers);
        }

        Set<Integer> keySet = new HashSet<>();
        for (int i = 0; i < containers.size(); i++) {
            for (int k : keys[i]) {
                keySet.add(k);
            }
        }

        for (int i = 0; i < status.length; i++) {
            if (containers.contains(i)) {
                if (status[i] == 1) {
                    max += candies[i];
                } else {
                    if (keySet.contains(i)) {
                        max += candies[i];
                    }
                }
            }
        }

        return max;
    }

    private void queryBoxes(int[][] containedBoxes, int boxes, Set<Integer> containers) {
        int[] container = containedBoxes[boxes];
        for (int con : container) {
            containers.add(con);
            queryBoxes(containedBoxes, con, containers);
        }
    }
}