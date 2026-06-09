![image.png](https://pic.leetcode-cn.com/24f13eab38f632175e64c7ef6f082d773213fc2e0ae2efd2c1d132f4b9ebc746-image.png)

只要满足执行一次后方向改变（好比左拐，左拐，左拐，左拐），或互道原点，则多次执行一定会回到原点
```
public boolean isRobotBounded(String instructions) {
    char D = 'R';
    int[] result = new int[]{0, 0};
    for (char c : instructions.toCharArray()) {
        if ('G' == c) {
            if ('R' == D) {
                result[0] = result[0] + 1;
            } else if ('L' == D) {
                result[0] = result[0] - 1;
            } else if ('T' == D) {
                result[1] = result[1] + 1;
            } else if ('B' == D) {
                result[1] = result[1] - 1;
            }
        } else if ('L' == c) {
            if ('R' == D) {
                D = 'T';
            } else if ('L' == D) {
                D = 'B';
            } else if ('T' == D) {
                D = 'L';
            } else if ('B' == D) {
                D = 'R';
            }
        } else if ('R' == c) {
            if ('R' == D) {
                D = 'B';
            } else if ('L' == D) {
                D = 'T';
            } else if ('T' == D) {
                D = 'R';
            } else if ('B' == D) {
                D = 'L';
            }
        }
    }
    return D != 'R' || (result[0] == 0 && result[1] == 0);
}
```