1. 先计算伪猜中
2. 再计算猜中, 减去伪猜中重复的
```java
class Solution {
    public int[] masterMind(String solution, String guess) {
        int[] result = new int[2];
        
        // 计算伪猜中
        int[] map = new int[90];
        for (char c : solution.toCharArray()) {
            map[c]++;
        }
        for (char c : guess.toCharArray()) {
            if (map[c]-- > 0) {
                result[1]++;
            }
        }

        // 计算猜中, 减去伪猜中重复的
        for (int i = 0; i < 4; i++) {
            if (solution.charAt(i) == guess.charAt(i)) {
                result[0]++;
                result[1]--;
            }
        }

        return result;
    }
}
```