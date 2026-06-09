这是@杨添伦题解中的分类。
最后一题，考虑四种情况：
1、前缀数组中所有数字的频率只有两种，设为A和B，其中A=B+1，且只有一个数字频率为A；
2、前缀数组中所有数字的频率只有两种，其中只有一个数字的频率为1，其他数字的频率都大于1且相等；
3、整个数组的数字的频率都是1；
4、整个数组都是同一个数字。

对应的处理：
1、把前缀数组中频率为A的数字删去1个即可；
2、把前缀数组中频率为1的数字删去即可；
3、整个数组删去任意一个数字都可；
4、整个数组删去任意一个数字都可。

作者：yang-tian-lun
链接：https://leetcode-cn.com/problems/maximum-equal-frequency/solution/conkao-lu-san-chong-qing-kuang-by-yang-tian-lun/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

在代码中cnt是对每个数字出现的频率进行计数。fre[i] = j是记录，频率i下 有j个数字。
maxcnt 是记录出现的最大频率是多少。
对于上述四种情况，我们可以依次来写。
说明：i+1是代表当前前缀的长度，详见代码。
第一种：前缀数组中所有数字的频率只有两种，设为A和B，其中A=B+1，且只有一个数字频率为A；
fre[maxcnt] = 1(A只出现一次)。
(fre[maxcnt - 1] - 1)(即是B) * (maxcnt - 1)(B出现的次数。) + maxcnt = i + 1;//为什么要减1，因为A在累加的过程中，一定会出现B次。
第二种：
fre[maxcnt] * maxcnt + 1 == i + 1;
fre[maxcnt] * maxcnt是除了情况2中只有一个数字频率为1的其他数。+ 1 是加上这个数 所以总和是总长度。
第三种：
maxcnt = 1,即是 3、整个数组的数字的频率都是1；
第四种：整个数组都是同一个数字。
fre[maxcnt] = 1;maxcnt  = i + 1;其实第一种情况可以化简成这个。但是为了容易理解，这样写。
解释
(fre[maxcnt - 1] - 1)(即是B) * (maxcnt - 1)(B出现的次数。) + maxcnt = i + 1; 当所有的数组都是同一数字时，fre[maxcnt - 1] = 1；所以原式化简为0 + maxcnt.
```
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
       map<int,int> cnt,fre;
       int maxcnt = 0;
       int ans = 0;
       for(int i = 0;i < nums.size();i++)
       {
           //数字nums[i]出现的次数
           cnt[nums[i]]++;
           //记录出现的最大次数
           maxcnt = max(maxcnt,cnt[nums[i]]);
           //当前次数的频率
           fre[cnt[nums[i]]]++;
           if(
               (fre[maxcnt] == 1 && (fre[maxcnt - 1] - 1) * (maxcnt - 1) + maxcnt == i + 1)//第一种情况
                ||(fre[maxcnt] == 1 && maxcnt == i + 1)//第四种情况，其实第一种情况可以化简成这个。但是为了容易理解，这样写。
                ||(fre[maxcnt] * maxcnt + 1 == i + 1)//第二种情况
                 )
                 ans = i + 1;
       }
       if(maxcnt == 1) ans = nums.size();//第三种情况
        return ans;
    }
};

```

