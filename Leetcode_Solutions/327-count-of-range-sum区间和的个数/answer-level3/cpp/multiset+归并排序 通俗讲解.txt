首先强推[yzpag的题解](https://leetcode-cn.com/problems/count-of-range-sum/solution/327qu-jian-he-de-ge-shu-ti-jie-zong-he-by-xu-yuan-/)
基本上我的题解就是他的题解更加通俗一点，这么多晦涩难懂的题解里，这个题解是比较好的，而且数学公式证明很到位
建议大家看我题解从头看到尾，不要跳，困难题是恶心一点
# 1. 首先来个暴力法试一试(unsolved)
```
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int nums_size=nums.size();
        int answer=0;
        for (int i=0;i<nums_size;++i)
        {
            long long sum=0;
            for (int j=i;j<nums_size;++j)
            {
                sum+=nums.at(j);
                if (sum>=lower && sum<=upper)
                    ++answer;
            }
        }
        return answer;
    }
};
```
当然是不可能AC的，这辈子都不可能AC的
原因就在于我们每次求一个区间的和都是O(N)的复杂度，加上一共有N个数字，导致复杂度上升到O(N^2)
- 所以第一步我们想到的是去**优化求单个区间和的复杂度**
- 所以就想到了通过**前缀和prefix**的方法，降低复杂度到O(1)
- 关于前缀和可以看下[303.区域和检索 - 数组不可变](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0303.区域和检索%20-%20数组不可变)
- 其实无非就是**区间[i,j]的和=sum.at(j)-sum.at(i)** j>i

# 2. multiset/AVL树/将sum.at(i)排好序
- 首先题目要求的是 **lower<=区间[i,j]的和<=upper**
- 通过前缀和 **区间[i,j]的和=sum.at(j)-sum.at(i)**
- 可得 **lower <= sum.at(j)-sum.at(i) <= upper**
因为我们处理的时候肯定是先弄好了i再去弄j的，即j>i的
我们倘若编写时候按照 **lower+sum.at(i) <= sum.at(j) <= upper+sum.at(i)** 那我们和暴力法就没有什么区别了，复杂度都是O(N)
- 可以换种思路，把sum.at(i)放在表达式的中间，下面数学推导
1. 题目要求 *lower <= sum.at(j)-sum.at(i) <= upper*
2. 将sum.at(j)移出中间 *lower-sum.at(j) <= -sum.at(i) <= upper-sum.at(j)*
3. 再提出负号 *sum.at(j)-upper <= sum.at(i) <= sum.at(j)-lower*
- 所以最后关键东东来了 就是 **sum.at(j)-upper <= sum.at(i) <= sum.at(j)-lower**
- 我们所需要的就是在算出sum.at(j)的情况下，对所有的sum.at(i)，找到匹配上一行表达式的所有i的可能结果
那我们难道是对着i一个一个遍历嘛，那不又回到暴力O(N)了
哦吼，前功尽弃，小朋友，你是否有很多问号？
那我们想，我们最常用的查找方式是啥？折半查找(二分查找)
那折半查找前提是什么，数组有序啊
- 所以我们如果保证了所有的sum.at(i)是有序的，是不是就可以用折半查找了
- 就想到了用mutiset自动排序的特性
[mutiset知识](https://www.cnblogs.com/ChinaHook/p/6985444.html)
- 刚好他有lower_bound,upper_bound这两个折半的查找函数，更加舒服了
- 最后通过[distance](https://blog.csdn.net/xuanyin235/article/details/78526919)来结合，直接搞定当j确定时，满足表达式的i的个数

代码
```
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> helper;
        helper.insert(0);
        int ans=0;
        long long sum=0;
        for (int &i:nums)
        {
            sum+=i;
            ans+=distance(helper.lower_bound(sum-upper),helper.upper_bound(sum-lower));
            helper.insert(sum);
        }
        return ans;
    }
};
```

# 3. 归并排序
首先要明白归并排序，以下是相关题和讲解
[148.排序链表](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0148.排序链表)
[315.计算右侧小于当前元素的个数](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0315.计算右侧小于当前元素的个数)
[B站归并排序讲解](https://www.bilibili.com/video/av9982752/)
明白归并排序基本规则：采用二分的方法，处理的是将两个已经有序的数组，排成一个有序的大数组
可能会疑问到为什么要用到归并排序呢？
1. 首先记住题目的要求 **lower <= sum.at(j)-sum.at(i) <= upper**
2. 归并排序中，处理的是两个有序的数组，在multiset方法中，我们就通过有序来优化效率，这里有序也是有帮助的
3. 归并排序分成两个数组，我们就可以理解成左半部分和右半部分，就可以进一步想成左边对应着i，右边对应着j
4. 那么我们可以设立指针，左边对应着i，右边对应着j，就可以通过在排序的过程中求出**sum.at(j)-sum.at(i)**
5. 而且归并排序是O(NlogN)，挺多因素都对本题有帮助

那么要怎么操作呢，我们举一个**例子**(注意前缀和数组前面要有一个0)
`倘若一个nums={2,-1,3,6,4};lower=2;upper=5 前缀和sum={0,2,1,4,10,14}`
我们就演示最后一步折半查找时如何操作sum来求得最后一步的答案
此时因为前面的归并排序，sum的左半部分和右半部分已经有序了即`sum={0,1,2,    4,10,14}`
- 我们在前面设定的是左边对应的是i，右边对应的是j，题目的要求表达式是**lower <= sum.at(j)-sum.at(i) <= upper**
- 我们可以固定i，来找所有的j的可能，在找完后，再移动i，再重复找j的操作
- 我们设left_p来表示i，left_p=左边的第一个元素
- 现在我们就来开始找j了，右边符合题目的j可以有多个，所以我们要找的是**符合题目要求的j的区间**，可以理解为 *符合的j.begin(),符合的j.end()*
1. 按照迭代器的设计方法来规定 符合要求的j的区间，即 **[begin,end)**
2. 设right_ans_begin来表示右边符合题目要求的j的区间的begin，指向区间的第一个元素
3. 设right_ans_end来表示右边符合题目要求的j的区间的end，指向区间最后一个元素的下一个元素
4. 既然题目要求 **lower <= sum.at(j)-sum.at(i)**，那对于begin指针，我们如果是遇到 **sum.at(j)-sum.at(i)<lower** 的话，因为left_p即i是已经固定了的，增大差的方式就只有增大被减数，而归并排序的左右部分都是已经有序的了，所以我们只需要将right_ans_begin即j向后移，即是增大被减数了，寻找到符合题目要求为止就停止向后移
`while (sum.at(right_ans_begin)-sum.at(left_p)<lower)    ++right_ans_begin;`
5. 既然题目要求 **sum.at(j)-sum.at(i) <= upper**，对于end指针，我们因为是结束的边界，且数组有序，在减数sum.at(i)一定的情况下，无限增大被减数，是会造成>upper即不符合题目要求的情况出现的，所以我们就一直检测 **sum.at(right_ans_end)-sum.at(left_p)<=upper**是否满足即可，满足则移动right_ans_end，不满足则跳出循环
`while (sum.at(right_ans_end)-sum.at(left_p)<=upper)    ++right_ans_end;`
- 现在我们找好了在i确定不变下，符合题目要求的j的区间了，因为是[begin,end)，所以right_ans_end-right_ans_begin即是区间的个数了
- 现在就可以移动i了，即++left_p
- 那我们是否是需要重置j的边界right_ans_begin,right_ans_end呢？
1. 记住题目要求**lower <= sum.at(j)-sum.at(i) <= upper**
2. 那么 **lower+sum.at(i) <= sum.at(j) <= upper+sum.at(i)**
3. 此时因为移动了i，且归并排序是操作有序的数组，即新的sum.at(i)一定是变大了的，那么对应的新的sum.at(j)的取值也是变大的，意思就是在右边中，小的值(比上一个i对应的符合题目要求的j的区间的值 还要小的值，即j.begin()前面的值)必然是不符合的
4. 即增大了i，新的j的区间只有两种情况: 旧的j.begin 新的j.beign 旧的j.end 新的j.end；或： 旧的j.begin 旧的j.end 新的j.begin 新的j.end
5. 所以我们不需要重置j的边界right_ans_begin,right_ans_end，这里也算是优化的一步
- 当我们遍历完所以的i，即已经找全了这一步归并排序所有的符合题目要求的区间组合
- 别忘了基础是前面的归并排序已经帮你排好了左右都是有序的部分，所以我们在找完ans后，要进行排序
可以手撕但是看到别人代码里有inplace_merge这个函数,STL真的是啥玩意都有，学到了学到了
- [inplace_merge](http://c.biancheng.net/view/568.html)
- 再完成排序后我们就可以返回递归了，直到完成完整的排序，所有的区间和的个数我们就也找出来了

代码
```
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int nums_size=nums.size();
        vector<long long> sum(nums_size+1);
        sum.at(0)=0;
        for (int i=0;i<nums_size;++i)
            sum.at(i+1)=nums.at(i)+sum.at(i);
        return merge(sum,lower,upper,0,sum.size());
    }
    int merge(vector<long long>& sum,const int lower,const int upper,int start,int end)
    {
        if (end-start<=1)
            return 0;
        int mid=start+(end-start)/2;
        int left_part=merge(sum,lower,upper,start,mid);
        int right_part=merge(sum,lower,upper,mid,end);
        int result=merge_sort(sum,lower,upper,start,mid,end);
        return left_part+right_part+result;
    }
    int merge_sort(vector<long long>& sum,const int lower,const int upper,int start,int mid,int end)
    {
        int ans=0;
        int right_ans_begin=mid,right_ans_end=mid;
        for (int left_p=start;left_p<mid;++left_p)
        {
            while (right_ans_begin<end && sum.at(right_ans_begin)-sum.at(left_p)<lower)
                ++right_ans_begin;
            while (right_ans_end<end && sum.at(right_ans_end)-sum.at(left_p)<=upper)
                ++right_ans_end;
            ans+=(right_ans_end-right_ans_begin);
        }
        inplace_merge(sum.begin()+start,sum.begin()+mid,sum.begin()+end);
        return ans;
    }
};
```

本题解较长啊。。不好意思。。。还有不懂评论区交流
群里大佬表示可以通过线段树来，每增加一个元素更新一次线段树，如果有人做出来了可以贴下想法


