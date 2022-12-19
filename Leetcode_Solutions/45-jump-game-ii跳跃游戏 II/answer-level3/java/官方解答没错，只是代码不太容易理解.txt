虽然只是一道简单的贪心法的题而已，其实难度不大，但是答案的代码并不容易看懂，写得很巧妙，说答案错了的人都是没看懂。
先抄一下官方的解答：

```
public int jump(int[] nums) {
    int position = nums.length - 1; //要找的位置
    int steps = 0;
    while (position != 0) { //是否到了第 0 个位置
        for (int i = 0; i < position; i++) {
            if (nums[i] >= position - i) {
                position = i; //更新要找的位置
                steps++;
                break;
            }
        }
    }
    return steps;
}
```

题目里说了一定能跳得到最后一个点，既然能跳到最后一个点就意味着每个点都能跳得到。假设我们是从第n个点跳到最后一个点的，那么就意味着从n到最后一个节点每个点都能到达，同理，如果我们是从点m跳到点n的，那么也说明m到n中的任意一个点都能到达，以此类推，从第1个点到最后一个点，每一个点都可以到达，所以中间有没有0都没关系，只要能到达最后一个点就说明每一个点都能到达，所以对每个点计算他能到达的最远处是对的，即：

 `maxPosition = Math.max(maxPosition, nums[i] + i); ` 

但是有一个地方可以优化，当maxPosition>=length-1时，我们已经找到了解，等下次循环到i==end的时候steps++，end=maxPosition再然后一直到循环结束i都不可能等于end，因此在`maxPosition = Math.max(maxPosition, nums[i] + i); ` 这句话后面可以加上：

```
            if(maxPosition>=nums.length-1){
                return (steps+1);
            }
```
最后编译用时2ms，超过95%用户

顺便贴一下自己的代码，写得比较直观，冗余比较多，比标准答案写得难看，但是内存稍微节约了一点

```
    public int jump(int[] nums) {
        int maxPosition = 0;
        int step = 0;
        int i = 0;
        while (maxPosition < nums.length - 1) {
            int max=0;
            if (i + nums[i] >= nums.length - 1) {
                return step + 1;
            }
            for (int j = i+1; j <= i + nums[i]; j++) {
                if(max<=j+nums[j]){
                    max=nums[j]+j;
                    maxPosition=j;
                }
                if (max >= nums.length - 1) {
                    return step + 2;
                }
            }
            i = maxPosition;
            step++;
        }
        return step;
    }
```
除此之外，我刚开始还想到了一种动态规划的方法，因为这样的题从直觉上来看真的比较动规，思路很简单，d[0]=0，d[1]=1，之后的元素等于他前面所有元素里可以跳到该点的最小值，即：

```
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= i - j && ans[j] < min) {
                    min = ans[j];
                }
            }
```
最后ans[i]=min

这样用了两层循环，时间复杂度是O(n2)，倒数第二个案例就超时了，不过也可以作为一个思路：

```
 public int jump(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        int[] ans = new int[nums.length];
        ans[0] = 0;
        ans[1] = 1;
        for (int i = 2; i < nums.length; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= i - j && ans[j] < min) {
                    min = ans[j];
                }
            }
            if (min == Integer.MAX_VALUE) {//因为每个点都能跳到，所以这里就算不做这个判断也不要紧，主要是怕数值超过int最大值，溢出了变成负数
                ans[i] = min;
            } else {
                ans[i] = min + 1;
            }
        }
        return ans[ans.length - 1];
    }
```
