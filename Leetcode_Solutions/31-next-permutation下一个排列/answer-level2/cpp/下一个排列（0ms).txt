### 解题思路
![QQ图片20200114220539.png](https://pic.leetcode-cn.com/1fdf97eb1a38365e4cfd5f92cea0c676e1c318cc8d989806f9aec05972ecbd5b-QQ%E5%9B%BE%E7%89%8720200114220539.png)

+ 题目的意思就是让你找到比该数大的下一个数，如果没找到，返回该排列的一个最小排列
1. 先把元素个数等于0，1的排列直接输出。
2. 从右往左遍历，找到第一个相邻的逆序数（如 1，3，2），由于该数(1)右边的序列已经有序，从右边的有序数列中找出比1大的最小数，即从最右遍历，找到第一个比1大的数，将两者交换位置。
3. 由于已经进行了最高位的交换，将该数（1）右边的序列直接有序排列（sort（））即可。
## 注意##
sor排序的范围是左闭右开区间！


### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0||nums.size() == 1)
            return;
            
        for(vector<int>::reverse_iterator it = nums.rbegin();(it+1)!=nums.rend();it++) 
            if(*(it+1)<*it)  //找到第一个无序，将有序中的比该值大的最小值交换过来
            {
               //开始找该值
                vector<int>::reverse_iterator it1 = nums.rbegin();
                while((*it1)<=*(it+1))
                    it1++;
                int temp = *it1;
                *it1 = *(it+1);
                *(it+1) = temp;
                //再向前做相反调整，即最小序列
                sort(nums.rbegin(),it+1,greater<int>());  //注意sort的在闭右开区间
                return;
            }
        sort(nums.begin(),nums.end());
    }
};
```