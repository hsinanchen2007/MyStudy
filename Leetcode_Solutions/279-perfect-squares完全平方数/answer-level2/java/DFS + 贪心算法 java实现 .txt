![QQ图片20200405100631.png](https://pic.leetcode-cn.com/5513ea525ec828ca9585515494c3bba1bd201e5713f594f227fd56b0f83d3cab-QQ%E5%9B%BE%E7%89%8720200405100631.png)


```
    //dfs + 贪心算法
    int res = Integer.MAX_VALUE;
    public int numSquares(int n) {
        int a = (int) Math.floor(Math.sqrt(n)); //向下取整 找到最大的完全平方数
        int[] num = new int[a]; //创建对应的数组
        for (int i = 0; i < a; i++) {
            num[i] = i + 1;
        }
        numChange(num.length - 1, num, 0, n);
        return res == Integer.MAX_VALUE ? 0 : res;
    }

    private void numChange(int index, int[] num, int count, int n) {
        if (n == 0) {
            res = Math.min(res, count);
        }
        if (index < 0) {
            return;
        }
        //i + count < res  这个是当前的个数和我们的res 进行比较 如果小于才进行替换 否则无意义
        //n / (num[index] * num[index]) 这个 利用乘除 代替加减
        for (int i = n / (num[index] * num[index]); i >= 0 && i + count < res; i--) {
            numChange(index - 1, num, count + i, n - i * num[index] * num[index]);
        }
    }
```
