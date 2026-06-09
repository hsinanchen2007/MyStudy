思路：1.首先判断是否存在下一个更大的排列：
利用中间变量tmp，如果有一个数比后面一个数小，表示还可以生成更大的排列
如果中间变量没有变化，则表示排列是递减的，直接交换位置。
2.如果tmp变化了，记录下最后一个位置。
比如输入样例：[5,7,4,5,3,2]
这时候tmp指向4的位置，后面必然是一个递减的序列，不然tmp必然指向靠后的位置
然后逆序遍历，直到tmp，找到第一个大学nums[tmp]的元素，并交换位置
比如这里，交换之后[5,7,5,4,3,2]
然后剩下的[tmp+1,s-1]区间的元素反转过来即可
```
void swap(int &a,int &b)
    {
        int tmp=a;
        a=b;
        b=tmp;
    }
    void nextPermutation(vector<int>& nums) {
        int s=nums.size();
        if(s<=1)
            return;
        int i,tmp=-1;
        for(i=0;i<s-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                tmp=i;
            }
        }
        if(tmp==-1)
        {
            int j=0,k=s-1;
            while(j<k)
            {
                swap(nums[j++],nums[k--]);
            }
            return;
        }
        else
        {
            int k;
            for(k=s-1;k>tmp;k--)
            {
                if(nums[k]>nums[tmp])
                {
                    swap(nums[k],nums[tmp++]);
                    break;
                }
            }
            k=s-1;
            while(tmp<k)
            {
                swap(nums[k--],nums[tmp++]);
            }
        }
    }
```
