### 解题思路
投票算法：
我们且称符合条件的答案为长三数，最主要是要先分析出最多有两个长三数，因为条件要求大于length/3，所以只能有三种结果：2个长三数，1个长三数，没有长三数（因为题目并没有保证是有的）。
题目要求使用O（1）的空间，所以不能使用map类容器来帮助统计，因此根据分析，设置两个数来保存答案，并设置对应的票数。
那么如何投票呢？因为两个数的存在，所以我们需要分别检查是否等于两个数其中之一。但这里面存在一个先后问题。当等于1时，就不要判断等于2了，这样就可以保证两个数不同，因为先判断不等于1后，才会进行2的判断操作。赋值操作思路同判等思路。
我们将两个数都设置为数组第一个数，根据上面的推断，1会将开始相等的数都归于自己门下，所以2一定会重新赋值。这么打个比方，举例为0,0,1,0,2。a、b开始都初始化为0，前面有一堆数字，碰到一样的便拿到手里，否则先停住在原位，另一个从此位置重复上一个的操作，若两个都不等，则检查两人的票数，先检查第一个的，若是为0，将此数给他，因为他身上没钱了，先让他吃，若是有钱，则不饿，判断第二个，为0，没钱，给他，如果有钱，不饿。两人都不饿的时候，这个数就浪费了，两人都浪费了，都自减1。以上述例子说明：a先走，碰到第一个0，因为赋值就是它，所以一定相等，投a一票（这样还能保证a肯定是先有一票，不用被赋值，b赋值的时候肯定不是初始的数了，因为已经被a拿走），继续，碰到第二个0，投a一票，继续，碰到1，静止；b从a此时位置出发，由于前方0均被1洗劫一空，所以开始拿的0并没有用，a现在有两票，b有零票，所以，b先拿上这个1，投一票。继续，a走到0，三票，a走到2，不等，且不等b，两个都减一。最后0两票。这样就得出0是一个多数。最后还需要重新检测，检测0的个数，大于length/3，则是，否则不是。


### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int length=nums.size();
        if(length==0)
            return res;
        int nums1=nums[0];
        int times1=0;
        int nums2=nums[0];
        int times2=0;
        for(int i=0;i<length;i++)
        {
            if(nums[i]==nums1)
            {
                times1++;
            }
            else if(nums[i]==nums2)
            {
                times2++;
            }
            else if(times1==0)
            {
                nums1=nums[i];
                times1=1;
            }
            else if(times2==0)
            {
                nums2=nums[i];
                times2=1;
            }
            else
            {
                times1--;
                times2--;
            }
        }
        times1=0;
        times2=0;
        for(int i=0;i<length;i++)
        {
            if(nums[i]==nums1)
                times1++;
            else if(nums[i]==nums2)
                times2++;
        }
        if(times1>length/3)
            res.push_back(nums1);
        if(times2>length/3)
            res.push_back(nums2);
        return res;
    }
};
```