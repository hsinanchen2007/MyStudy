**思路**
这里有两个是变化的，一个是拥有的盒子列表，一个是拥有的钥匙集合。dfs的过程就是不断更新这两个参数的过程，直到（盒子为空）或者（盒子都是关闭状态而且没有钥匙）的时候，递归终止。

```java
class Solution {
    private int ans = 0;
    private int[] status;
    private int[] candies;
    private int[][] keys;
    private int[][] containedBoxes;

    private void dfs(List<Integer> boxes, Set<Integer> keySet) {
        // 没有拥有任何盒子
        if (boxes.isEmpty()) {
            return;
        }

        List<Integer> nextBoxes = new ArrayList<>(boxes);
        boolean isAllZero = true;
        for (Integer box : boxes) {
            if (status[box] == 1 || keySet.contains(box)) {
                isAllZero = false;
                ans += candies[box];
                nextBoxes.remove(box);
                keySet.remove(box);
                for (Integer tmpBox : containedBoxes[box]) {
                    nextBoxes.add(tmpBox);
                    for (Integer key: keys[tmpBox]) {
                        keySet.add(key);
                    }
                }
            }
        }

        // 所有盒子都是关闭的，而且没有任何钥匙了。
        if (isAllZero) {
            return;
        }

        dfs(nextBoxes, keySet);
    }

    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        this.status = status;
        this.candies = candies;
        this.keys = keys;
        this.containedBoxes = containedBoxes;
        List<Integer> boxes = new ArrayList<>();
        for (int num : initialBoxes) {
            boxes.add(num);
        }

        Set<Integer> keySet = new HashSet<>();
        for (Integer box : boxes) {
            for (int key: keys[box]) {
                keySet.add(key);
            }
        }
        dfs(boxes, keySet);
        return ans;
    }
}
```
