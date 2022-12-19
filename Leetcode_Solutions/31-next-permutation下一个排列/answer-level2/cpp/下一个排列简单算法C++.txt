###解答结果
执行用时 :4 ms, 在所有 C++ 提交中击败了92.60%的用户
内存消耗 :14.4 MB, 在所有 C++ 提交中击败了5.09%的用户
### 解题思路
一开始我以为只是单纯的交换前一个数比后一个数小的相邻数元素就可以，但后来发现没那么简单。
其实正确的算法也是要找前一个数比后一个数小的相邻元素，将这两个数记为x和y，然后在y之后找到小于等于y且大于x的最小元素，记为z，然后交换x和z的位置；最后将y之后的元素排序即可。
就是要保证把x换成后面元素中比x大且最接近x的元素，满足题目排列的下一个的序列。
改进后算法思路如下：
1、从后遍历数组，当nums[i]>nums[i-1]，执行下列操作。
2、保存i，和nums[i]。theMin=nums[i],index=i;
3、逐个遍历i之后的数组元素，找到小于theMin大于nums[i-1]的数，将值赋给theMin，将下标赋给index；
4、交换nums[i-1]和nums[j]的值；
5、i之后的数组元素排序；

时间复杂度是O(n)
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tmp;
        bool flag=false;
        int theMin,index;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                theMin=nums[i],index=i;
                for (int j=i+1;j<nums.size();j++)
                {
                    if (nums[j]<theMin &&nums[j]> nums[i-1])
                    {
                        theMin=nums[j];
                        index=j;
                    }
                    if(nums[j]<= nums[i-1])
                        break;
                }
                nums[index]=nums[i-1];
                nums[i-1]=theMin;
                vector<int>::iterator start=nums.begin();
                while(i-->0)
                {
                    start++;
                }
                sort(start,nums.end());
                flag=true;
                break;
            }
        }
        if (!flag)
            reverse(nums.begin(), nums.end());
    }
};
```