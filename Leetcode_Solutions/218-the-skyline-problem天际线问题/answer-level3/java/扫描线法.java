### 解题思路
将每个建筑的起点和重点作为扫描点，然后依次遍历每个扫描点，更新当前点有效的建筑列表，根据该列表中的建筑的高度的最大值和之前的最大值进行比较，若不同，则该点为一个关键点，记录到最终结果中

### 代码

```java
class Solution {
    private static class Build {
        private int left;
        private int right;
        private int height;

        public Build(int left, int right, int height) {
            this.left = left;
            this.right = right;
            this.height = height;
        }
    }

    private Map<Integer, List<Build>> deadMap = new HashMap<>();
    private Map<Integer, List<Build>> burnMap = new HashMap<>();
    private List<Build> currentBuildList = new ArrayList<>();
    private List<Integer> keyPointList = new ArrayList<>();

    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> result = new ArrayList<>();

        for (int[] build: buildings) {
            keyPointList.add(build[0]);
            keyPointList.add(build[1]);
            if (!burnMap.containsKey(build[0])) {
                burnMap.put(build[0], new ArrayList<>());
            }
            if (!deadMap.containsKey(build[1])) {
                deadMap.put(build[1], new ArrayList<>());
            }

            Build b = new Build(build[0], build[1], build[2]);
            burnMap.get(build[0]).add(b);
            deadMap.get(build[1]).add(b);
        }

        keyPointList = keyPointList.stream().distinct().sorted().collect(Collectors.toList());
        int maxHeight = 0;

        for (int keyPoint: keyPointList) {
            if (burnMap.containsKey(keyPoint)) {
                currentBuildList.addAll(burnMap.get(keyPoint));
            }
            if (deadMap.containsKey(keyPoint)) {
                currentBuildList.removeAll(deadMap.get(keyPoint));
            }

            int newHeight = getMaxHeight();
            if (newHeight != maxHeight) {
                maxHeight = newHeight;

                List<Integer> record = new ArrayList<>();
                record.add(keyPoint);
                record.add(maxHeight);

                result.add(record);
            }
        }

        return result;
    }

    private int getMaxHeight() {
        int result = 0;
        for (Build build: currentBuildList) {
            result = Math.max(result, build.height);
        }
        return result;
    }
}
```