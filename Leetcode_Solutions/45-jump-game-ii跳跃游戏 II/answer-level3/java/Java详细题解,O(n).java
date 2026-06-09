- 执行用时 :3 ms, 在所有 Java 提交中击败了95.26%的用户
- 内存消耗 :41.4 MB, 在所有 Java 提交中击败了70.74%的用户


题解思路：
- 贪心算法的思想，每次都找能使自己跳得最远的位置，而且避免重复操作。时间复杂度O(n)。


来看例子：
1. nums=[2, 3, 1, 1, 1, 1, 1, 4]，`pos`表示索引（这个值其实不需要了），`tmpVal`表示上一次的最大覆盖范围，`maxVal`表示现在的最大覆盖范围，那开始时`pos=0，tmpVal=0，maxVal=nums[0]+0=2`，即向前跳跃(或者说覆盖)范围为2，那就`i`从`tmpVal+1`(上一个落点的最大范围+1) ->  `maxVal`(到这一次落点的最大范围)逐次+1搜索(因为上一次范围内搜索过的点就直接跳过，不用再重复了)，找到使`nums[i]+i`最大的`i`，即跳得最远的点。
2. 现在就在[3,1]里面找到`i=1，nums[i]=3，maxVal=3+1=4，count=1，tmpVal=2`
3. 下一步：从`tmpVal+1=3->maxVal=4`，[1(从左往右第2个1),1]里找到`i=4，nums[i]=1，maxVal=4+1=5，count=2，tmpVal=4`
4. 继续：从`tmpVal+1=5->maxVal=5`，[1(从左往右第4个1)]里找到`i=5，nums[i]=1，maxVal=5+1=6，count=3，tmpVal=5`
5. 继续：从`tmpVal+1=6->maxVal=6`，[1(从左往右第5个1)]里找到`i=6，nums[i]=1，maxVal=6+1=7，count=4，tmpVal=6`
6. 最后：`maxVal=7>=nums.length-1=7`，`count=5`，结束输出count。

再看一个例子：
1. nums=[2, 3, 1, 1, 4, 4, 1, 0, 1, 1, 3, 1, 0, 1]，开始时`pos=0，tmpVal=0，maxVal=nums[0]+0=2`，在[3,1]里面找到`i=1，nums[i]=3，maxVal=3+1=4，count=1，tmpVal=2`
2. 继续：从`tmpVal+1=3->maxVal=4`，[1,4]里找到`i=4，nums[i]=4，maxVal=4+4=8，count=2，tmpVal=4`
3. 继续：从`tmpVal+1=5->maxVal=8`，[4,1,0,1]里找到`i=5，nums[i]=4，maxVal=4+5=9`或者`i=8，nums[i]=1，maxVal=4+5=9`，`count=3，tmpVal=8`
4. 继续：从`tmpVal+1=9->maxVal=9`，[1]里找到`i=9，nums[i]=1，maxVal=1+9=10，count=4，tmpVal=9`
5. 继续：从`tmpVal+1=10->maxVal=10`，[3]里找到`i=10，nums[i]=3，maxVal=10+3=13，count=5，tmpVal=10`，
6. 最后：`maxVal=13>=nums.length-1=13`，`count=6`，结束输出count。


代码如下：

```Java []
class Solution {
    
    /**
     * 每次求max(a[i]+i),0<=i<=ai，当然是以上次跳跃落点为基础点
     * 能找到最大覆盖范围，时间复杂度为O(n)
     * @param nums
     * @return
     */
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;
        else if (nums[0] >= nums.length) return 1;
        else {
            //记录跳跃次数
            int count = 0;
            //现在位置索引
//            int now = 0;
            //记录上一次的最大范围
            int tmp = 0;
            //记录现在最大覆盖范围
            int maxVal = nums[0];
            //其实最多会执行n次,O(n)
            while (maxVal < nums.length - 1) {
                ++count;
                //记录最大覆盖范围
                int tmpmaxVal = maxVal;
                //找到最大覆盖范围
                for (int i = tmp + 1; i <= maxVal; i++) {
                    if (nums[i] + i  > tmpmaxVal) {
                        //记录
                        tmpmaxVal = nums[i] + i ;
                    }
                }
                //更新位置和范围
                tmp = maxVal;
                maxVal = tmpmaxVal;
            }
            ++count;
            return count;
        }
    }
}
```
