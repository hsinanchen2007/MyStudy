![QQ截图20200114141023.png](https://pic.leetcode-cn.com/97a0bdb86b1122fcabc64577e1f8f81a2ecb8d014433dc1c6e2a19392eb81fbb-QQ%E6%88%AA%E5%9B%BE20200114141023.png)
```java
// 莫非我是漏网之鱼?
public class SlidingWindowMaximum {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // 下一个窗口与当前最大值的区别在于，这个最大值可能是滑过的数字，也可能还在当前窗口中（所以仅需比较两次，重点在于确定最大数字的位置）

        // 特殊情况
        if(nums.length == 0)
            return new int[]{};

        // 初始化
        int res_len = nums.length - k + 1;
        int[] res = new int[res_len];
        int last_max = (int) Double.NEGATIVE_INFINITY;
        int last_max_index = -1, L = 0, R = k-1;

        while(R < nums.length){
            if(last_max_index < L){ // 如果最大值已经滑过了，得重新选举最大值
                last_max = (int) Double.NEGATIVE_INFINITY;  // reset最大值
                for(int i = L; i <= R; i++){
                    if(last_max < nums[i]){
                        last_max = nums[i];
                        last_max_index = i;
                        res[L] = last_max;
                    }
                }
            }
            else{                   // 否则仅需比较最大值与下一个位置的值的大小即可
                if(last_max < nums[R]){
                    last_max = nums[R];
                    last_max_index = R;
                    res[L] = last_max;
                }
                else
                    res[L] = last_max;
            }
            L++;
            R++;
        }

        return res;
    }
}

```
