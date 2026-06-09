        因为是按从小到大的顺序对所有排列进行排序标号的。可以根据k的大小，直接来推断各个位的数字。   
    对于n个数排列，第一位的一定是从1开始非严格递增到n的。例如：
    n=3时，首位的变化为1->1->2->2->3->3。
    n=4时，首位的变化为：1->1->1->1->1->1->2->2->2->2->2->2->。。。。-->3->3->3->3->3->3->
    4->4->4->4->4->4。
        通过观察不难发现，对于n个数的集合排列，其首位的变化周期为，(n-1)!。从数学角度讲，n个数的排
    列数为n！，当我们确定首位后，即相当于从n中取出一个数，对剩下的（n-1）个数进行排列组合，再分别与
    确定的首位组合，从而生成n个数的排列。所以对于第一位可以由式子（1）决定
                local=(k-1)/(n-1)!+1          （1）
        这里local并不是原始集合里元素的位置，而是可用集合里的元素位置。对于第一位，由于还没有取出元
    素，故所有元素都是可用的，按照1式里求得的local查找相应元素。对于后面的位，比如第二位的时候，
    由于我们刚刚在求第一位时，已经取出了一个元素，例如，第一位上取出了3，实际上此时可用的元素集合
    就为{1,2,4,5,6，。。。，n},此时假设local为4，实际上应取出元素5。
        当我们求得第一位的元素值，并且取出后，此时k更新为：
               k=(k-1)%(n-1)!+1                （2）
    可用集合的元素数量就变为n-1,即n=n-1。此时，又回到了问题的开始，如此递归直到取出所有元素。
    具体的实现代码如下：

```C++ []
class Solution {
public:
    string getPermutation(int n, int k) {
        string ori;
        string ans;
        vector<bool> flag(n,true);
        for(int i=0;i<n;i++)
        {
            ori.push_back(i+'1');
        }
        int j=0;
        while(n!=1)
        {
            int local;
            local=(k-1)/(jiecheng(n-1))+1;
            j=0;
            while(local>0)
            {
                if(flag[j]==true)
                {
                    --local;
                }
                ++j;
            }
            ans.push_back(ori[--j]);
            flag[j]=false;
            k=(k-1)%(jiecheng(n-1))+1;
            n=n-1;
        }
        j=0;
        while(flag[j]!=true)
        {
            j++;
        }
        ans.push_back(ori[j]);
        return ans;
    }
public:
    int jiecheng(int n)
    {
        int ans=1;
        for(;n>=1;--n)
        {
            ans*=n;
        }
        return ans;
    }
};
```




