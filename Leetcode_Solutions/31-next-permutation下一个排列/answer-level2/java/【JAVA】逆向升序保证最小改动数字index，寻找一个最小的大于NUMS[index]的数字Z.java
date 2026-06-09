### 解题思路
高分解答的JAVA版本
思路也是：先逆序遍历，找到一个最先出现的升序（x,y），这里的XY是相邻数，那么我们就可以得到一个降序区间（y,nums.length-1)，由于（x,y）必定是第一个出现的升序，那么区间（y,nums.length-1)就可以保证是降序的
然后我们在这个降序区间里面逆序寻找第一个比X大的数字Z，将x,z进行转换，那么就保证了这次排列的更改从ABCXY***Z***改成了ABCZY***X***
由于前缀ABC是不变的，我们就可以判断XY***Z***跟ZY***X***的大小，毫无疑问后者是前者所能拿到的最小数（在只变换X那个位置的情况下），那么后续就简单了，我们只要将X之后的数字进行升序排列就行，因为后续的数字本身是降序的，那就直接进行翻转即可。

知识点总结：
    算法的步骤是先找到一个位置最靠后的升序，之后对改升序进行反转，反转的目的是让改升序的一个数字换成最小的较大数，

最靠后的升序表明了最小的代价，而寻找后续数字中最小的较大数（Z是比X大的最小数），因为只要将X变成Z，后续是升序，那么就是比之前排列大的数。这是只改变X的话，能得到的最大数，那么怎么保证是全局的下一个较大数呢，这就是（X,Y）的要求必须是最先出现的升序，因为最先出现（逆序）意味着这个升序位置是最靠后的，即权值最小，那么改动它所造成的数值变化最小。

逆向升序保证最小改动数字index，寻找一个最小的大于NUMS[index]的数字Z，交换nums[x]与Z，即实现index位置的最小变换，而后续的只要进行普通的升序即可，即打成最小数字。
### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int left=nums.length-1;
        int right=nums.length-1;

        for(;left>=0;left--)
        {
            if(nums[left]<nums[right])
                break;
            right=left;
        }
        if(left==-1)
            //todo first,exchange all nums;
            {
                exchange(nums,0,nums.length-1);
            }
        else
        {
            int newright=nums.length-1;
            while(newright>right)
            {
                if(nums[newright]>nums[left])
                    break;
                newright--;
            }
            
            int temp=nums[newright];
            nums[newright]=nums[left];
            nums[left]=temp;
            exchange(nums,right,nums.length-1);
                //exchange left newright,and reverse nums after right;;
            
        }
        return;

    }
    public void exchange(int[] nums, int left, int right)
    {
        int temp=0;
        while(left<right)
        {
            temp=nums[right];
            nums[right]=nums[left];
            nums[left]=temp;
            left++;
            right--;
        }
        return;
    }
}
```