### 解题思路

当到达目的地时，还有时间且还有子结点，还是会继续往下跳，这点得注意

### 代码

```java
class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        Map<Integer, Integer> childNum = new HashMap<>();
        Map<Integer, Integer> parentPoint = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int[] singleEdges = edges[i];
            int key = singleEdges[0];
            int value = singleEdges[1];
            if(key > value){
                int temp = key;
                key = value;
                value = temp;
            }
            parentPoint.put(value, key);
            if (!childNum.containsKey(key)) {
                childNum.put(key, 1);
            } else {
                int num = childNum.get(key);
                num++;
                childNum.put(key, num);
            }
        }
        double rate = 1.0;
        int time = 0;
        int target2 = target;
        while (parentPoint.get(target) != null) {
            int parentTarget = parentPoint.get(target);
            int childNbr = childNum.get(parentTarget);
            rate = rate * 1 / childNbr;
            target = parentTarget;
            time++;
        }
        if(t<time || target != 1 || (t > time && childNum.get(target2)!=null && childNum.get(target2) > 0)){
            return 0.0;
        }
        return rate;

    }
}
```