用的双指针法解的，时间复杂度是O(n)
先定义一个first=0和last=-1的指针
用first进行遍历并且求一步一步遍历的总值sum，将sum和目标值进行比较，如果满足条件并且长度更小的话，
就更新更短的长度，然后再last++,进行遍历，看看能不能有更优解。
-           nums[--2-----3-----1-----2-----4-----3]      last=-1; first=0;
-           last  first
-           last       first
-           last              first 
-           last                   first                
- 此时sum==8>7，len=4,在进行last++，first不变，如下：
-                 last             first    
- 此时sum-=nums[last],sum==5<7,则fir++
-                 last                   first 
- 只要sum大于目标值，则进行last++，否则first++，最后求得最小的长度就可以了
-                                        last   first   
 **  - 代码如下**
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int fisrt=0;
        int last=-1,flag=last;//flag为标志
        int len=nums.size()+1;//初始值len始终会比数组的值长，之后能更好的进行比较
        int sum=0;
        while(fisrt<nums.size()&&last<fisrt)
        {
            if(flag==last)//此时last没有滑动过，就进行sum+
           { sum+=nums[fisrt];}
           else if(flag!=last)//last++过，此时区间减小了，所以要减去最前面的一位
           {
               sum-=nums[last];
               flag++;
           }
            if(sum>=s&&len>fisrt-last)//找出最小符合条件的长度
            {
                len=fisrt-last;
                if(last+1==fisrt) {fisrt++;}
                else {last++;}
                continue;
            }
            else if(sum>=s&&len<=fisrt-last)//符合条件但是长度没有更小的话，再继续缩小区间长度从而进行比较
            {
                last++;continue;
            }
            fisrt++;
        }
        if(len==nums.size()+1) return 0;//如果没有符合条件的连续子数组，长度会不变，就返回0
        return len;
    }
};
```

第一次写题解，有什么更好的意见评论见！
