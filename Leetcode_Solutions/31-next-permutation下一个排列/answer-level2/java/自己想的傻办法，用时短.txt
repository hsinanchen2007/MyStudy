### 解题思路
执行用时 :
1 ms, 在所有 Java 提交中击败了99.92%的用户
内存消耗 :41.4 MB, 在所有 Java 提交中击败了5.06%的用户

在数组中从最后向前遍历，在对应的位置j处，往后找，若能找到一个比j处大的数，则能通过交换让其更大。
找到那个比j处大却又比其他数小的数组数的位置，与j处的数交换，最后再对j后的数组排序即可。

### 代码

```java
class Solution {
    public int find(int[] nums,int j)
    {
        int smax=10000;
        int ind=0;
        boolean f=false;
        int k=j+1;
        while(k<nums.length)
        {
            if(nums[k]>nums[j]&&nums[k]<smax)
            {
                smax=nums[k];
                f=true;
                ind=k;
            }
            k++;
        }
        if(f)
        return ind;
        else return -1;
    }
    public void exchange(int[] nums,int i,int j)
    {
        int t=0;
        t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    public void nextPermutation(int[] nums) {
        int max=0;
        boolean flag=false;
       for(int i:nums)
       {
           if(max<i)
            max=i;
       } 
       for (int j=nums.length;j>=0;j--)
       {
           int k=find(nums,j);
           if(k!=-1)
          
           {
               flag=true;
               exchange(nums,j,k);
        //          int t=0;
        //    t=nums[k];
        //    nums[k]=nums[j];
        //    nums[j]=t;
              Arrays.sort(nums,++j,nums.length);
               break;
           }
       }
       if (!flag)
          Arrays.sort(nums);
    }
}
```