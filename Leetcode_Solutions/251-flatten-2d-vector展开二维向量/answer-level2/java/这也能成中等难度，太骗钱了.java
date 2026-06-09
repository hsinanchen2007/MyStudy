### 解题思路
这也能成中等难度，太骗钱了

### 代码

```java
class Vector2D {

    private int[] ay;

    private int idx = -1;

    public Vector2D(int[][] v) {
        int count = 0;
        for (int i = 0; i < v.length; i++) {
            count = count + v[i].length;
        }
        ay = new int[count];
        count = 0;
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j < v[i].length; j++) {
                ay[count] = v[i][j];
                count++;
            }
        }
    }

    public int next() {
        idx++;
        return ay[idx];
    }

    public boolean hasNext() {
        if (idx + 1 < ay.length) {
            return true;
        }
        return false;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(v);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```