# 思路
其实我写这道题的最初的思路就是暴力求解，把每一个出现的数据和其次数都记录下来，然后遍历就可以得知答案。
但是，这种方式占用的内存可能就比较大，因为要全部存下来。
然后参考了（https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/cong-zhu-wei-tong-ji-dao-luo-ji-biao-da-shi-fang-s/）这个老哥的答案。但是我没有照抄。那位老哥使用的计算每一位的方法，虽然时间复杂度是O（n）,但是实际上把整个数组遍历了32遍，也就是O（32n）。
我觉得这样反复存取要耗费很多时间，所以我的想法就是取到一个数据时就把它的信息全部统计好存下来。
也就是创建一个二维的数组count[][]。k=count[i][0]就代表第i个位0的数目是k个。所以需要创建一个32*2的数组。
但是这样还是有一点问题，因为极端情况下，计算一个数据进行31次计算，还是要耗费不少时间的。
所以为了减少处理一个数据的时间，我选择不按照二进制来处理，而按照十进制的表示形式来处理，即创建一个10*10的数组。（为什么选择10*10呢？因为十进制表示的情况下，每一位上只能是0-9这十个数组，同时int型数据所能表示的最大值为2147483647，也是10位。）然后k = count[i][j]就表示第i位上的数字j的个数为k个。
这样整个思路就有了。下边就是代码。（如果思路有什么问题的话，欢迎指出。）
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector <vector<int>> count(10,vector<int>(10,6));
        int len = nums.size(),temp,place,numdp;
        int i,j,re = 0;
        //cout<<INT_MAX<<endl;//INT_MAX的值为2147483647
        for(i = 0;i < len;i++)
        {
            temp = nums[i];
            place = 0;
            while(temp > 0)
            {
                numdp = temp%10;
                temp /= 10;
                count[place][numdp]++;
                place++;
            }
        }
        //temp = 1;
        for(i = 9;i >= 0;i--)
        {
            //temp *= 10;
            for(j = 0;j<10;j++)
            {
                if(count[i][j]%3 != 0)
                {
                    re = re*10 + j;
                    break;
                }
            }
        }
        return re;
    }
};
```
