看着没有人写java的题解，就把我的发一下
一开始我也用的暴力解法，for循环嵌套，结果时间超时，之后用了曼哈顿距离求解

执行用时 :10 ms, 在所有 java 提交中击败了71.91%的用户
内存消耗 :45.9 MB, 在所有 java 提交中击败了100.00%的用户

```
class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int[] num={1,-1};
        int ans=0;
        for (int i = 0; i < num.length; i++) {
            for (int j = 0; j < num.length; j++) {
                for (int k = 0; k < num.length; k++) {
                    int max=-1000000,min=1000000;
                    for (int i1 = 0; i1 < arr1.length; i1++) {
                        max=Math.max(max,arr1[i1]*num[i]+arr2[i1]*num[j]+i1*num[k]);
                        min=Math.min(min,arr1[i1]*num[i]+arr2[i1]*num[j]+i1*num[k]);
                    }
                    ans=Math.max(ans,max-min);
                }
            }
        }
        return ans;
    }
}
```

