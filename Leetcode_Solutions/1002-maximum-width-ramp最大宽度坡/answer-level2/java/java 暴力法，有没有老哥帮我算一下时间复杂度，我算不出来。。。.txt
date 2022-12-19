一个指针从左到右，对于每一个从右向左找到第一个比左边的大的，那就是这个左边值的最大坡度。
另外加了两层筛选，如果左边的值到最右边的距离小于当前最大坡度，就没有必要去循环。
同理，子循环里面如果再向左遍历后的最大坡度小于当前最大坡度，也没必要去循环了。
可能我没有超时的原因就是加了这两层判断吧。接下来研究一下大家说的单调栈。
不过我有一个疑问，我的算法的空间复杂度是O（1）没错的，但是时间复杂度应该是多少呢？
左指针遍历不到n，但是具体是未知数。右指针虽然是未知数，但是期望值是1.5常数，因为平均两个数里面总有一个比基数大的。
希望有大牛答疑解惑。
```
class Solution {
    public int maxWidthRamp(int[] A) {
        int maxWidth=0;
        for(int i= 0;i<A.length-maxWidth;i++){
            for(int j =A.length-1;j>i+maxWidth;j--){
                if(A[i]<=A[j]){
                    maxWidth=Math.max(maxWidth,j-i);
                    break;
                }
            }
        }
        return maxWidth;
    }
}
```
