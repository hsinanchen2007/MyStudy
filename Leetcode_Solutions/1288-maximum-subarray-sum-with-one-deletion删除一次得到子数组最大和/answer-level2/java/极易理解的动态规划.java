### 解题思路
首先 如果元素只有一个 那么就返回这个元素

做出2个数组prefixDp 和 suffixDp
prefixDp[i] 表示 从前往后 最后一个下标为i的 最大子数组和
suffixDp[i] 表示 从后往前 最后一个下标为i的 最大子数组和 
同时保存 中间过程中 最大的值

最后再遍历每一个可能被删除的 值的下标

例: 假设删除的 下标为 2  那么 当前位置的可能超过最大值的 只可能是 prefixDp[1] + suffixDp[3]
遍历所有可能,得到最大值


### 代码

```java
class Solution {
    public int maximumSum(int[] arr) {
        if(arr.length == 1)return arr[0];
        int[] prefixDp = new int[arr.length]; //正向DP  prefixDp[i]  从 0 到 i元素的 最大子数组和
        int[] suffixDp = new int[arr.length];   //逆向DP suffixDp[i]  从 arr.len 到 i 的最大子数组和
        prefixDp[0] = arr[0];
        suffixDp[arr.length-1] = arr[arr.length-1];
        int max = Integer.MIN_VALUE;
        for(int i=1;i<arr.length;i++){
            prefixDp[i] = Math.max(prefixDp[i-1] + arr[i] , arr[i]);
            max = Math.max(max,prefixDp[i]);
            suffixDp[arr.length-1-i] = Math.max(suffixDp[arr.length-i] + arr[arr.length-1-i],arr[arr.length-1-i]);
            max = Math.max(max,prefixDp[i]);
        }
        for(int i=0;i<arr.length;i++){  //删掉下标为i之后的最大值
            int left = i!=0 ? prefixDp[i-1] : 0;
            int right = i!=arr.length-1 ? suffixDp[i+1] : 0;
            max = Math.max(max,left+right);
        }
        return max;
    }
}
```