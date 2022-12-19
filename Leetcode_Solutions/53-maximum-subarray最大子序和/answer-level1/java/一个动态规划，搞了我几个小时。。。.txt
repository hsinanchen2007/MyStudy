最高赞还说“这道题用动态规划的思路并不难解决”。。。。我一个普通二本生表示，动态、分治的难度不分伯仲。。。

还是那句话：会者不难，难着不会。。。

代码的格式表达了我此刻的心情。。。。

各位小白随便看看就好，希望能对后继者有所启发。
```
class Solution {
    public int maxSubArray(int[] nums) {
        //动态规划算法的关键是找出重叠性子问题之间的关系
        /*
        思路：
        切入点：
            规模特征：数组长度，或者说，数组中整数个数，这里记作N
            重叠性子问题：长度为N-1。。。2，1数组的最大字段和
            重叠性：长度为N的依赖长度为N-1，或者说，前者基于后者
            注意！子问题间的规模递增值不一定都如本题一样是1，也可能是2，也可能是等比数列，几何式，指数式
            维系一张表：
            
        枚举；        MaxSubArray    AllSubArray
        N=1时:-2         [-2]       [-2]
        N=2时:-2,1      [1]         [-2 ],[1],[-2,1]
        N=3时:-2,1,-3   [1]
        最优指标：和最大？
        注意！以下分析是错误的（而且没分析完），是我走过的弯路。。。大家一笑而过就好，囧
        <!-- 分析：当前子段和是在上一子段和的基础上增加，
        当前子段和 = 上一子段和 + 新整数
        sum(a[n]) = sum(a[n-1]) + an
        要最大，则要求 sum(a[n-1])最大，且an为正
        所以需要判断an， -->
        我的这段代码再次印证了这句话：
            没分析清楚就开始动手写代码，此乃编程大忌！
        */
        int firstSubArraySum = nums[0];
        int maxSubArrSum =0;
         /*当前子段的子段只考虑两种情况，
         ①结尾元素构成的单元素子段，
        ②上一子段 与 结尾元素连接所构成的子段，也即是当前子段本身！！！
当前子段的最大字段和在这两个里面产生。而不是三个！上一子段归到上一子段考虑。*/
        int currentSubArrMaxSubArrSum = 0;
        int currentSubArrSubArr1Sum = 0;
        int currentSubArrSubArr2Sum = 0;
        if(nums.length <= 1){
            maxSubArrSum = firstSubArraySum;
            return maxSubArrSum;
        }else{
            for(int i=0;i<nums.length;i++){
                if(i == 0){
                    currentSubArrMaxSubArrSum = firstSubArraySum;
                maxSubArrSum = firstSubArraySum;
                }
                else{
                   currentSubArrSubArr1Sum = currentSubArrMaxSubArrSum+nums[i];

                        currentSubArrSubArr2Sum = nums[i];

                    currentSubArrMaxSubArrSum = (currentSubArrSubArr1Sum >currentSubArrSubArr2Sum ?currentSubArrSubArr1Sum:currentSubArrSubArr2Sum);
                }
                 if( currentSubArrMaxSubArrSum> maxSubArrSum){
                    maxSubArrSum = currentSubArrMaxSubArrSum;
                        }

                
            }
        }
                return maxSubArrSum;


        
    }
}
```
