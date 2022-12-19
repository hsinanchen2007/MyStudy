本题首先是一个抽样问题，首先你要明白如何从n个元素中等概率随机抽取m个元素，方法有很多（可以自行去百度），和本题有关的思路是：每次取一个位置，然后从剩下的位置里继续每次取1个。那么如何将这些位置分开（取过的和未取过的）呢。可以使用交换的方法，每次取的位置，和尾部的位置内的元素进行交换，每次递减 n， 这样即使取到重复的位置，里面的元素也是不一样的啦！

仿照这个思路，本题也是交换尾部元素，但是这个交换的记录使用Map去存储，如果交换过，那么我们就读取原来的位置，如果没交换过，就使用当前的位置！
代码以及注释如下：

```Java
    private int row, col, n;
    private HashMap<Integer, Integer> posMap;
    private Random random;
    public Solution(int n_rows, int n_cols) {
        row = n_rows;
        col = n_cols;
        n = row * col;
        posMap = new HashMap<>();
        random = new Random();
    }
    
    public int[] flip() {
        if (n < 0) return null;
        //随机选择一个下标
        int r = random.nextInt(n--);
        int x = posMap.getOrDefault(r, r); // 查看是否存在交换关系
        // 原下标与尾部下标交换（使用map记录origin->tail交换关系）
        posMap.put(r, posMap.getOrDefault(n, n));
        return new int[]{x/col, x%col};
    }
    
    public void reset() {
        posMap = new HashMap<>();
        n = row * col;
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！