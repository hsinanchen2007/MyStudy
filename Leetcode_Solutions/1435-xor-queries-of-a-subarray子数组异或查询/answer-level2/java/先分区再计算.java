方法1：第一时间的想法，肯定不能一个个答案写啊，会超时啊，那我建立数组，使用动态规划，把所有的都列举出来，那最后的答案也就出来了，很可惜，内存不够，啪啪打脸，代码就不贴了。
方法2：暴力求解，哈哈，虽然要几百毫秒，咋说也是求出来了，代码在方法3中有使用，也就不重复粘贴了。
方法3：虽然暴力求出来了，但是还是心有不甘，想到之前的基数排序，我有个想法，我虽然不能直接得出答案，但是我可以把中间的大部分进行合并，这样也不用挨个计算了。
例如：queries[k] = [821,39384];
我们如果提前以100为界限进行，那就是计算821-899(79次)，900-39299(每100一次，284次)，39300-39384(85次)，共448次xor运算，原本是要进行38564次运算。
代码如下：

```

    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] ans = new int[queries.length];
        if (arr.length <= 1000) {
            //数组小，可用直接算
            for (int i = 0; i < queries.length; i++) {
                for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                    ans[i] ^= arr[j];
                }
            }
        } else {
            int step = (int) Math.sqrt(arr.length);
            int[] temp = new int[arr.length / step];
            //建立一些区域数组
            for (int i = 0; i < temp.length; i++) {
                for (int j = step * i; j < step * (i + 1); j++) {
                    temp[i] ^= arr[j];
                }
            }
            for (int i = 0; i < queries.length; i++) {
                if (queries[i][1] - queries[i][0] < step) {
                    //需要的计算量小
                    for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                        ans[i] ^= arr[j];
                    }
                    continue;
                }
                int l = (queries[i][0] + step - 1) / step;
                int r = queries[i][1] / step;
                //左边多出的部分
                for (int j = queries[i][0]; j < l * step; j++) {
                    ans[i] ^= arr[j];
                }
                //右边多出的部分
                for (int j = r * step; j <= queries[i][1]; j++) {
                    ans[i] ^= arr[j];
                }
                //把区域内的数值计算出来
                for (int j = l; j < r; j++) {
                    ans[i] ^= temp[j];
                }
            }
        }
        return ans;
    }

```
ps：现在还没想到更快的方法，唯一能有点进步的优化就是
int step = (int) Math.sqrt(arr.length)/2;
step折半，时间最快是46ms。