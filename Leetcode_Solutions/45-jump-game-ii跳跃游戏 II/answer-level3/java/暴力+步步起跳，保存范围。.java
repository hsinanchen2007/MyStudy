### 解题思路
此处撰写解题思路
第一种解法：注释掉的，是自己拍脑袋想的，在每个跳板上，以跳板的值作为范围进行遍历，更新范围之内的跳板步数，直到最终结果。
第二种解法：抄的高赞，就是从每一步进行思考，思考这一步能走多远，那么在这个多远的范围之内，都只需记录为走了x步，且在这一步里面，能走的最远的，也就是这里面所遍历出来的i+nums[i]的最大值，保存为最长范围，由于这个范围是可以缩减的，即比如这一步的最长范围是7，那么其实他是可以从i到i+7,这个范围必覆盖当前范围的最大值的下一个格子，所以当前范围的下一个格子就可以作为下一步的起跳点，下一步就从起跳点跳到最远范围，直到起最远范围大于nums的长度。
### 代码

```java
// class Solution {
//     public int jump(int[] nums) {
//         int len=nums.length;
//         int[] dp=new int[len];

//         for(int i=0;i<len;i++)
//             dp[i]=Integer.MAX_VALUE;
//        dp[0]=0;
//         for(int i=0;i<len;i++)
//         {
//             for(int step=1;step<=nums[i];step++)
//             {
//                 if(i+step>=len)
//                     break;
//                 int temp=dp[i]+1;
//                 dp[i+step]=Math.min(dp[i+step],temp);
//             }
//         }
//         return dp[len-1];
//     }
// }
class Solution {
    public int jump(int[] nums) {
        int len=nums.length;
        int start=0;
        int ans=0;
        int end=1;
        int max_range=0;
        while(end<len)
        {
            for(int i=start;i<end;i++)
            {
                max_range=Math.max(max_range,i+nums[i]);
            }
            start=end;
            end=max_range+1;
            ans++;
        }
        return ans;
    }
}

```