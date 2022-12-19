### 分析法：双指针

这其实就是一道数学题，题意就是，给定一个有序数组`nums`和a、b、c作为输入，按升序输出二次方程的值：
1. 分两种情况讨论，`a==0`时是一次方程（也就是直线），`a!=0`时是二次方程
2. 对于一次方程，当`b>0`时，按照`nums`的顺序输出即可，当`b<=0`时，按照`nums`的逆序输出即可
3. 对于二次方程，可得到抛物线开口方向，`a>0`开口向上，反之开口向下；同时可得到抛物线对称轴`axis=-(b/(2*a))`，
4. 根据`axis`的位置，确定左右双指针`left/right`的位置，注意这里的边界条件
4. 当`left/right`指针均存在的时候，比较`left/right`到`axis`的距离，距离短的优先计算，计算完成之后左移`left`或者右移动`right`
5. 当`left`或者`right`仅存在一个的时候，仅移动一个即可，并计算结果；`left`和`right`均越界的时候，跳出循环
6. 根据`a>0`或者`a<0`判断开口方向，将4、5步的计算结果按照从前往后、从后往前排列，最后返回即可

```
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        return a != 0 ? sort_a_no_eq_0(nums, a, b, c) : sort_a_eq_0(nums, a, b, c);
    }

    public int[] sort_a_eq_0(int[] nums, int a, int b, int c){
        int[] result = new int[nums.length];
        for(int i = 0; i < nums.length; i++)
            result[b > 0? i: nums.length - 1 - i] = cal(a, b, c, nums[i]);
        return result;
    }


    public int[] sort_a_no_eq_0(int[] nums, int a, int b, int c) {
        int[] result = new int[nums.length];

        float axis = -((float)b/(2*a));
        int idx = a > 0?0:nums.length - 1;
        int left = -1, right = -1;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] >= axis){
                if(i < nums.length) right = i;
                if(i - 1 >= 0) left = i - 1;
                break;
            }
        }
        if(left == -1 && right == -1) left = nums.length - 1;

        while(true){
            int cur = 0;
            if(left >= 0 && right < nums.length) 
                cur = cal(a, b, c, (axis - nums[left] <= nums[right] - axis) ? nums[left--]:nums[right++]);
            else if(left >= 0 && (right >= nums.length || right == -1)) 
                cur = cal(a, b, c, nums[left--]);
            else if(left < 0 && right < nums.length) 
                cur = cal(a, b, c, nums[right++]);
            else break;
            result[idx] = cur;
            idx += (a > 0? 1: -1);
        }
        return result;
    }

    public int cal(int a, int b, int c, int x){
        return a * x * x + b * x + c;
    }
}
```

 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$，开辟了返回结果的空间

### 其他方法

 - 可以先对每个值计算二次方程值，再排序，这样不空间复杂度$O(1)$，时间复杂度$O(nlog(n))$
 - 二次函数的峰值位置可以用二分查找加速