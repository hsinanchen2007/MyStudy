### 解题思路
二维数组按顺序转为一维即可，然后用队列存储，输出即可，睿智难度。

### 代码

```java
class Vector2D {

    private Queue<Integer> queue = new LinkedList<>();
    
    public Vector2D(int[][] v) {
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j < v[i].length; j++){
                queue.offer(v[i][j]);
            }
        }
    }

    public int next() {
        return queue.poll();
    }

    public boolean hasNext() {
        return !queue.isEmpty();
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(v);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```