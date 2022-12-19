关于摩尔投票法的操作步骤已经有不少题解说的很清楚了，但关于为什么这么做却少有提及，下面我结合自己的理解说说这么做为什么可行，如有不足之处，还望指出。
首先，我们看看这幅图：![改进的摩尔投票.PNG](https://pic.leetcode-cn.com/53488de814559877751e1b8661d12d7e7e74ad5da358e29ab31eda29c4058b1e-%E6%94%B9%E8%BF%9B%E7%9A%84%E6%91%A9%E5%B0%94%E6%8A%95%E7%A5%A8.PNG)
------经过一段投票，cand1、cand2与other的票数如图，这时候cand1与other票数一样多，cand2的票数不少于other（count1记录cand1-other，count2记录cand2-other），而参与投票的元素num要投给other，照理说count1--，count2--就完事了，但是发现conut1--之后变成-1了。                                  

------我们想办法看看能否舍弃一部分从而开始新的一轮投票。我们的任务是找出总的超过1/3的元素，我们来看一下，假设我们把other、cand1以及cand2中与other个数相同的部分先放一边，而找剩余部分（cand2蓝色及后面）的超过1/3的元素，这时候我们发现，假设总的存在超过1/3的元素，那么剩余的必定存在超过1/3的元素。因为前面部分other、cand1与cand2非蓝色部分长度相同，如果总超过1/3的元素是cand1或者cand2或者other中任意元素，那么这个元素在剩余部分占比肯定超过1/3。如果总超过1/3的元素是剩余部分某元素，那么此元素在剩余部分占比也肯定超过1/3。另外，假设总的不存在超过1/3的元素，那么剩余的可能存在也可能不存在超过1/3的元素。所以我们可以先找出剩余部分超过1/3的元素，再在这些元素里面筛选出总的超过1/3的元素。
    
-----而如何找出剩余部分超过1/3的元素呢，依然使用投票法，设定cand1、cand2进行投票（这时候可以cand1=num，count1=1，cand2与count2不变，然后再继续投票下去），如果能投票到最后，count不为0的元素就可能是剩余部分超过1/3的元素，count为0则肯定不是。因此可以在count不为0的元素里面筛选总的超过1/3的元素（其实就是从头遍历统计它们的次数，看是否超过1/3）。如果投票到中途又遇到如图的情况，那么继续像前面那样舍弃一部分在在剩余部分找超过1/3长度的元素
    
最终是这样的局面，如下图![摩尔投票.PNG](https://pic.leetcode-cn.com/a14d7da3284cc3e8336139fc004d51559f858860a2900963ceeacff869743463-%E6%91%A9%E5%B0%94%E6%8A%95%E7%A5%A8.PNG)
-----range1超过1/3长度的元素在range2超过1/3长度的元素里面选，而range2超过1/3长度的元素在range3超过1/3长度的元素里面选，以此类推，range1的超过1/3长度的元素再最后一个range的超过1/3长度的元素里面选就可以了。
-----这里附上java代码：
```
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans=new ArrayList<>();
        if(nums==null||nums.length==0) return ans;
        if(nums.length<=2){
           ans.add(nums[0]);
           if(nums.length>1&&nums[1]!=nums[0]) ans.add(nums[1]);
            return ans;
        }

        int candi1=nums[0]; int count1=0;
        int candi2=nums[0];int count2=0;
        int p=0;
        int len=nums.length;
        while (p!=len){//还没有到尽头
            int num=nums[p++];
            if(num==candi1) {
                count1++;
                continue;
            }
            if(num==candi2){
                count2++;
                continue;
            }
           if(count1==0){
               candi1=num;
               count1=1;
               continue;
           }
           if(count2==0){
               candi2=num;
               count2=1;
               continue;
           }
           count1--;
           count2--;
        }
        if(count1==0&&count2==0) return ans;
        if(count1!=0&&count2!=0&&candi1!=candi2){
            count1=0;
            count2=0;
            for(int number:nums){
                if(number==candi1) count1++;
                if(number==candi2) count2++;
            }
            if(count1>=len/3+1) ans.add(candi1);
            if(count2>=len/3+1) ans.add(candi2);
        }else if(count1!=0){
            count1=0;
            for(int number:nums){
                if(number==candi1) count1++;
            }
            if(count1>=len/3+1) ans.add(candi1);
        }else {
            count2=0;
            for(int number:nums){
                if(number==candi2) count2++;
            }
            if(count2>=len/3+1) ans.add(candi2);
        }
        return ans;
    }
}
```
