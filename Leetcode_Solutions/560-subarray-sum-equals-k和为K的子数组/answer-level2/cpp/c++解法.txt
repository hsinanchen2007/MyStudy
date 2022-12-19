原理嘛很简单，与暴力解法不同的主要是**寻找答案思路的改变**
暴力解法就是一个一个加起来看看符不符合答案
       所以找答案的思路是 ***相加***
而这个用哈希表的办法找答案的思路是
                        ***相减***
用数列来解释：
对于数列{an}(n 是下标  此数列为a1,a2,a3······an)  设其前n项和为Sn(n为下标)(Sn = a1+a2+···+an)
那么我们要找ai,a(i+1),a(i+2),···,a(j)这个子数列 除了验证ai + a(i+1) + ···+aj外
还可以验证:Sj - S(i-1)          （ai + a(i+1) + ···+aj=Sj - S(i-1) ）
就是此方法的思路了(上面讨论的一切变量名与下方代码中变量名无直接关系)
```
//  hash_map      //k=0真有趣
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int n  = 0;                   //符合条件的子集个数
		int sum = 0;                  //for中目前i位置及之前的所有nums元素的和
		unordered_map <int,int> map;  //储存nums中和为a的前x项元素  的个数b  即为{[a,b]}
	    map[0]=1;                     //防止遗漏sum = k的情况 
		                               //(比如nums[0]=k  一开始的这一个就丢了)
		for (int i =0;i<nums.size();i++)
		{
			sum+=nums[i];    //求和 
            n+=map[sum - k]; //对map{[a,b]}如果符合 sum - k = a 那么说明sum - a = k 
			map[sum]++;      //那么sum a 两个和对应的下标之间的元素和就为k   
			                 //(看官方解的视频很好理解---)
		}
	return n;
    }
};
```

