### 解题思路
读题后，其实就是要把深度均分，那么声明一个数组，记录每个括号对应的深度即可
而深度的计算也比较简单，由于只有小括号这一种，所以就看i与i-1是否相同
如果相同且是左括号，则深度+1
如果相同且是右括号，则深度-1
如果不同，则深度不变

通过一次遍历，即可完成整个深度的数组，遍历的同时，还能求得最大的深度

将最大深度除以2，得到深度分界线

再遍历一次深度数组，将大于深度分界线的置为1，其余的置为0即可

性能不高，但是能过
![image.png](https://pic.leetcode-cn.com/c31249cd2aee5345f581cd231f9582bf2efa12984b8332ebbff23ae29487e40a-image.png)


### 代码

```java
public class Solution {
    private static final char LEFT = '(';
    private static final char RIGHT = ')';

    public int[] maxDepthAfterSplit(String seq) {
        char[] array = seq.toCharArray();
        int[] depth = new int[array.length]; //深度数组
        depth[0] = 1;
        int maxDepth = 0;
        for (int i = 1; i < array.length; i++) {
            if (array[i] == array[i - 1]) { //如果与前一个字符相同，这要进行深度的增加或减少
                depth[i] = array[i] == LEFT ? depth[i - 1] + 1 : depth[i - 1] - 1;
                maxDepth = Math.max(depth[i], maxDepth);
            } else { // 如果与前一个字符不同，那么深度不变
                depth[i] = depth[i-1];
            }
        }

        int threshold = maxDepth / 2; //计算深度分界线
        for (int i = 0; i < depth.length; i++) {
            if (depth[i] > threshold) {
                depth[i] = 1;
            } else {
                depth[i] = 0;
            }
        }

        return depth;
    }
}
```