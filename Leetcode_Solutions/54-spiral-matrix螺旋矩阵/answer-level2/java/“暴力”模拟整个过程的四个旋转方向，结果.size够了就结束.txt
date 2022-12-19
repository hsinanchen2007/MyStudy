**“暴力”模拟整个过程的四个旋转方向~**

每次收缩for循环的起始上下限，更新当前坐标位置，
结果.size够了就结束；
![java.PNG](https://pic.leetcode-cn.com/27982b70b56bfc0f99cd04ef01e36ba8c6658129b2ef549ff0c9e42fb4d9342b-java.PNG)

*（代码还有点繁琐，可简化，先贴为敬）*
```java []
    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> xie = new ArrayList<Integer>();
        if (matrix == null || matrix.length == 0) {
            return new ArrayList<Integer>();
        }
        int hMax = matrix.length;// 行边界值上限
        int hMin = 0; // 行边界下限
        int lMax = matrix[0].length; // 列边界上限
        int lMin = 0; // 列边界下线
        int nums = matrix.length * matrix[0].length;
        int h = 0;
        int l = 0;
        while (xie.size()!=nums) {
            // 列+【→】
            for (int l1 = lMin; l1 < lMax; l1++) {
                if (xie.size()==nums) {
                    break;
                }
                xie.add(Integer.valueOf(matrix[h][l1]));
                l = l1;
            }
            hMin++;
            // 行+【↓】
            for (int h1 = hMin; h1 < hMax; h1++) {
                if (xie.size()==nums) {
                    break;
                }
                xie.add(Integer.valueOf(matrix[h1][l]));
                h = h1;
            }
            lMax--;
            // 列-【←】
            for (int l2 = lMax - 1; l2 >= lMin; l2--) {
                if (xie.size()==nums) {
                    break;
                }
                xie.add(Integer.valueOf(matrix[h][l2]));
                l = l2;
            }
            hMax--;
            // 行-【↑】
            for (int h2 = hMax - 1; h2 >= hMin; h2--) {
                if (xie.size()==nums) {
                    break;
                }
                xie.add(Integer.valueOf(matrix[h2][l]));
                h = h2;
            }
            lMin++;
        }
        return xie;
    }
```