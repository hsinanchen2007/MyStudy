4ms 和 0ms 轮流出现的一个普通方法（借用额外存储空间）
![image.png](https://pic.leetcode-cn.com/0fed24f2ebb91635e8b2d2b0332376ef6a4dac3e536c82071dcbf4da4743e881-image.png)
```C++ []
class Solution {
public:
    int reverse(int x)
    {
        vector<int> nums;
        //循环判断末位是否为0
         for(int i=0;i<200;i++)//200是随便一个值，>上限就OK
        {
            if(x%10==0) x=x/10;
            else break;
        }
        //每位数字依次放进数组，放进的顺序正好是反转的顺序
        for(int i=0;i<200;i++)
        {
            if(x==0) break;
            nums.push_back(x%10);
            x=x/10;            
        }
        //判断溢出+输出
        int j=0,size=nums.size();
        for(int i=0;i<nums.size();i++,size--)
        {
            j+=nums[i]*pow(10,size-1);
            if(j>=pow(2,31)-1||j<=-pow(2,31)) return 0;//溢出判断放在循环内是因为，某一次累加可能就溢出了
        }       
        return j;
    }
};
```