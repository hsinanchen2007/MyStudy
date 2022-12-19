### 解题思路
代码是参考官方的，不过官方写的太复杂了，我看了蛮长时间的！

思路是：
创建数组tails用来保存从左到右遍历数组所得的最长上升子序列；
每遍历一个元素时，都使用二分查找法找到该元素应该在tails数组的索引；

关于元素替换：
像序列10,9,2,5,3,7,21,18
它在遍历时会遇到tails数组由2,5,7 👉 2,3,7
元素3替换了元素5的位置，在暂时遍历到这里时，3和5都在2和7之间，它们是处于同一水平位置的，所以替换后并不会影响结果；
而会为后面万一出现3和5中间的数（例如：4，他将代替5，会和3处同一水平位置）这种特殊情况做准备；
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
         int[] tails = new int[nums.length];
        int res = 0;
        for(int num : nums) {
            int i = 0, j = res;
            while(i < j) {	
                int m = (i + j) / 2;
                if(tails[m] < num) i = m + 1;
                else j = m;
            }
            tails[i] = num;
            if(res == j) res++;
        }
        return res;
    }
}
```