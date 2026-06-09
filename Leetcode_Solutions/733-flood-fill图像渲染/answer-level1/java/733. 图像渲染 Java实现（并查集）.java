### 解题思路
    本人前一题解用深搜C实现的，换了Java写了遍并查集。

### 代码

```java
class Solution {
    private int[] root;
    private int[] rank;
    private int num;

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image == null || image.length <= 0) {
            return null;
        }
        if (image[sr][sc] == newColor) {
            return image;
        }
        this.num = image.length * image[0].length;
        this.root = new int[this.num];
        this.rank = new int[this.num];
        for (int i = 0; i < this.num; i++) {
            this.root[i] = i;
            this.rank[i] = 1;
        }
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                int index = i * image[0].length + j;
                if (i < image.length - 1 && image[i + 1][j] == image[i][j]) {
                    union(index, index + image[0].length);
                }
                if (j < image[0].length - 1 && image[i][j + 1] == image[i][j]) {
                    union(index, index + 1);
                }
            }
        }
        int sIndex = sr * image[0].length + sc;
        int sRoot = find(sIndex);
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                int index = i * image[0].length + j;
                if (sRoot == find(index)) {
                    image[i][j] = newColor;
                }
            }
        }
        return image;
    }

    private int find(int x) {
        if (root[x] == x) {
            return x;
        } else {
            return root[x] = find(root[x]);
        }
    }

    private void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rank[rootX] <= rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
        }
        if (rank[rootX] == rank[rootY] && rootX != rootY) {
            rank[rootY]++;
        }
        return;
    }

}
```