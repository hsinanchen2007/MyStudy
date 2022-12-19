### 解题思路
这道题用先是排序，然后用的动态规划。
目前测试用例都能通过，但是超出时间限制，基本都是300ms左右。
求大神

### 代码

```java
public int bestSeqAtIndex(int[] height, int[] weight) {
        int [][]mix=new int[height.length][2];
        for (int i=0;i<height.length;i++){
            mix[i][0]=height[i];
            mix[i][1]=weight[i];
        }
        Arrays.sort(mix, new Comparator<int[]>() {
            @Override
            public int compare(int[] ints, int[] t1) {
                if (ints[0]-t1[0]!=0)
                    return ints[0]-t1[0];
                return ints[1]-t1[1];
            }
        });
        int[] f = new int[height.length];//存储最长子序列的数列
        for (int i = 0;i < height.length;i++)
            f[i] = 1;
        int max = 1;//最大值
        for (int i = 1;i < height.length;i++) {
            for (int j = 0;j < i;j++) {
                //更新条件，1是有序，2是长度能变长
                if (mix[i][1] > mix[j][1] && mix[i][0] > mix[j][0] && f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    if (f[i] > max) {
                        max = f[i];//更新最长的长度
                    }
                }
            }
        }
        return max;
    }