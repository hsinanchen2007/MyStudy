# 思路
这道题的前提就是N对情侣（$2N$个人）坐在$2N$个座位上，也就是说每个位置上都有人，没有空位。那么最后想要让情侣并肩坐在一起，只能是每两个座位一对情侣。而且情侣的编号是$(0，1),(2，3), ... ,(2N-2, 2N-1)$,也就是说每对情侣编号中，奇数编号比偶数编号大1。发现这个规律之后就很简单了，我们从第0位开始，判断第$0、2、4、...、2N-2$位置上的人跟他们下一个位置上的人是否为情侣，如果不是，则找到他们的情侣与他们的下一个位置上的人进行交换即可。最终交换的总次数就是答案。具体代码如下：
```java
 public int minSwapsCouples(int[] row) {
        int ans = 0;
        int n = row.length;
        int[] indexArr = new int[n];

        for (int i = 0; i < n; i++) {
            indexArr[row[i]] = i;
        }

        int next = 0;
        for (int i = 0; i < n; i += 2) {
            next = (row[i] & 1) == 0 ? row[i] + 1 : row[i] - 1;
            if (next == row[i + 1]) {
                continue;
            }

            // 其实无需真正执行交换操作，由于进入i + 1位置的人现在已经配对到情侣了，后面不会再用到了，
            // 因此只要更新离开i+1位置的那个人的信息即可
            int swapedIndex = indexArr[next];
            indexArr[row[i+1]] = swapedIndex;
            row[swapedIndex] = row[i + 1];
            ans++;
        }

        return ans;
    }
```
# 复杂度分析
通过上述代码，明显可得
时间复杂度 $O(N)$
空间复杂度 $O(N)$