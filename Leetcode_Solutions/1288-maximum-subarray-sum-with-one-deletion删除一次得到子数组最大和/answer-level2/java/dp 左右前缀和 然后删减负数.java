### 解题思路
找出左右前缀和
leftdp[i]、rightdp[i]分别代表从左到i和从右到i的最大子数组和
我们用max记录两者中最大那个，用于表示如果没有需要删减的数的时候的最大子数组和
接下来我们遍历arr数组，逐个尝试删减后的结果是否比max大
### 代码

```java
class Solution {
    public int maximumSum(int[] arr) {
        if(arr.length==1) return arr[0];
        //左右前缀和
        int[] leftdp = new int[arr.length];
        int[] rightdp = new int[arr.length];
        leftdp[0] = arr[0];
        rightdp[rightdp.length-1] = arr[arr.length-1];
        int max = Integer.MIN_VALUE;
        for(int i = 1;i<arr.length;i++){
            leftdp[i] = Math.max(leftdp[i-1]+arr[i],arr[i]);
            max = Math.max(max,leftdp[i]);
            rightdp[rightdp.length-i-1] = Math.max(rightdp[rightdp.length-i]+arr[arr.length-i-1],arr[arr.length-i-1]);
            max = Math.max(max,rightdp[rightdp.length-1-i]);
        }
        
        
        for(int i = 0;i<arr.length;i++){
            /*如果删减i 那么左前缀和就是leftdp[i-1] 右前缀和是rightdp[i+1],那么两者相加就是删除当前位置的子数组和*/
            //而且按理来说需要删减的只有负数
            if(arr[i]<0){
                int left = i==0?0:leftdp[i-1];
                int right = (i==arr.length-1)?0:rightdp[i+1];
                max = Math.max(left+right,max);
            } 
        }
        return max;
    }
}
```