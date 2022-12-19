本人新手
这道题本质其实主要还是看数组里有没有0，如果没有0，那么无论怎么走都可以走到终点
出现零的时候，就需要考虑一下了。

什么情况才能使得跳跃在0处停止呢？
就是前面的数字给的数值不足以让其跨过这个零。
设x处为0，那么x-1处如果跨不过0，那么该值必须小于或等于1，
x-2处必须小于或等于2....以此类推，就得出了一个大致的结论

即，若x为0，x-n处的数字若出现大于n的，那么这个0就可以被跨越过去。反之则跨不过去
当然，还有一个例外，就是这个0本身是最后一位的时候，那么只要能到这个0即可，不需要跨过去。
根据上面的思路就有了以下的代码

```
class Solution {
   public boolean canJump(int[] nums) {
        if(nums.length==1){
            return true;
        }
        boolean f1 =true;
            
            for (int x = 0; x < nums.length; x++) {
                if(nums[x]==0){
                    f1=false;

                    for(int y=x-1;y>=0;y--){
                        if(nums[y]>x-y){
                            f1=true;
                        }
                    }
                    
                    if(!f1){
                        if(x==nums.length-1){
                            f1=true;
                        }else {
                        return f1;
                        }
                    }
                    

                }
            }
            return f1;

    }
}
```
