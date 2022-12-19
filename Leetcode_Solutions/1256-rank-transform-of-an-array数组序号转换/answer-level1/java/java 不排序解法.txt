# **解题思路**
首先求出数组的最大值和最小值，接着创建一个可以存放该区间的数组temp，遍历参数arr数组，对temp对应的位置进行标记，表示该数存在，这样我们就间接得到了排序后的数组，然后直接计数+1即可。

注：这方法不是我想出来的，看题解没有这个解法就搬运了一下，解法是看提交里的代码来的。
<br>

```java []
public int[] arrayRankTransform(int[] arr) {
        int cnt = 1;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int[] ans = new int[arr.length];
        //找出数组的最大和最小值
        for ( int i = 0; i < arr.length; i++ ) {
            max = Math.max(max, arr[i]);
            min = Math.min(min, arr[i]);
        }
        int[] temp = new int[max-min+1];
        //标记该数存在
        for ( int i = 0; i < arr.length; i++ ) {
            temp[arr[i]-min] = 1;
        }
        //间接获得了排序后的数组
        for ( int i = 0; i < temp.length; i++ ) {
            if ( temp[i] > 0 ) temp[i] = cnt++;
        }
        for ( int i = 0; i < arr.length; i++ ) {
            ans[i] = temp[arr[i]-min];
        }
        return ans;
    }
```
