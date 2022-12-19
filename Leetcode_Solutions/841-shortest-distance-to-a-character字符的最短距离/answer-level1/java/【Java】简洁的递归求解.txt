## 思路
- 生成一个记录最短距离的数组distance，元素的初始值为Integer.MAX_VALUE
- 遍历字符数组，当碰到和C相同的字符时，开始左右递归：
   - 递归函数的参数：
       - 记录最短距离的distance数组
       - 开始递归时那个与C字符相同的元素的下标值index
       - 当前递归到的下标值cur
       - 步长，1代表向左，-1代表向右
   - 递归的处理逻辑：
       1. 设定退出条件：超出字符数组边界
       2. 比较index和cur差值的绝对值
       3. distance的cur下标位置的元素，取原值与差值的最小值
- 循环结束，返回distance
## 代码
```java[]
public class Solution {
    public int[] shortestToChar(String S, char C) {
        char[] cs = S.toCharArray();
        int [] distance = new int[cs.length];
        for (int i = 0; i < distance.length; i++) {
            distance[i] = Integer.MAX_VALUE;
        }

        for (int i = 0; i < cs.length; i++) {
            if (cs[i] == C) {
                rescurse(distance, i, i, 1);
                rescurse(distance, i, i, -1);
            }
        }

        return distance;
    }

    private void rescurse(int[] distance, int index, int cur, int path) {
        if (cur < 0 || cur  > distance.length - 1) {
            return;
        }

        distance[cur] = Math.min(distance[cur], Math.abs(index - cur));

        rescurse(distance, index, cur + path, path);
    }
}
```