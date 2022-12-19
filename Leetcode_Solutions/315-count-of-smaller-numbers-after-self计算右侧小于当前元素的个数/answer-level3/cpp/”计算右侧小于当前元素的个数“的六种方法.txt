给定一个整数数组 *nums*，按要求返回一个新数组 *counts*。数组 *counts* 有该性质： `counts[i]` 的值是  `nums[i]` 右侧小于 `nums[i]` 的元素的数量。

> 示例:

> ```
> 输入: [5,2,6,1]
> 输出: [2,1,1,0] 
> //解释:
> 5 的右侧有 2 个更小的元素 (2 和 1).
> 2 的右侧仅有 1 个更小的元素 (1).
> 6 的右侧有 1 个更小的元素 (1).
> 1 的右侧有 0 个更小的元素.
> ```

## 1. 暴力模拟法
暴力模拟法思路非常简单，就是每次都从末尾找比`num[i]`小的数并计数，然后放到结果数组即可。

```cpp
vector<int> countSmaller(vector<int>& nums) {
	int n=nums.size();
	vector<int>ans(n,0);
	int t;
	for(int i=n-2;i>=0;i--){
		t=0;
		for(int j=n-1;j>i;j--){
			if(nums[j]<nums[i])
				t++;
		}
		ans[i]=t;
	}
	return ans;
}
```
但这样带来的算法效率会非常的低，原因在于每次寻找比`num[i]`小的数都需要从末尾遍历一次，所以时间复杂度为$O(n^2)$



## 2. 模拟法+查找
我们从暴力模拟法为起点进一步优化，我们看到每次我们都要从末尾遍历相同的元素，实际上我们可以建立一个保持排序的数组sorted_num。
这个数组代表：在nums[i]之后所有的数，并且已经排好序。
每次在nums数组出现新的需要判断的数就要插入到这个sorted_num，然后在这个数通过二分查找到下界(可以用STL自带的lower_bound()) 减去sorted_num.begin()就是比nums[i]小的元素个数了。
```cpp
class Solution {
public:
vector<int> countSmaller(vector<int>& nums) {
    vector<int> sorted_num;
    /*建立一个保持排序的数组*/
    vector<int> res;
    /*用于保存结果的数组*/
    for(int i=nums.size()-1;i>=0;i--){
        auto iter = lower_bound(sorted_num.begin(),sorted_num.end(),nums[i]);
        /*通过lower_bound()二分寻找下界，返回一个迭代器(也就是相对于sorted_num的index)*/
        int pos = iter-sorted_num.begin();
        /*
        通过排序数组的二分查找性质，我们可以知道iter-sorted_num.begin()(可以理解成sorted_num数组的起始位置)就是
        题目需要的比nums[i]小的数字个数    
        */
        sorted_num.insert(iter,nums[i]);
        /*这时nums[i]已经使用完了，需要给以后的数字拿来判断
        插入后要保持sorted_num排序，所以nums[i]插入到iter位置*/
        res.push_back(pos);
    }
    reverse(res.begin(),res.end());
    /*一路上都是倒序插入的，所以在最后要逆转数组*/
    return res;
}
};
```

 未使用的STL的lower_bound()的模拟法加查找代码，因为减少了函数调用，效率会高很多

```cpp
class Solution {
 public:
     vector<int> countSmaller(vector<int>& nums) {
         vector<int>t,res(nums.size());
　　　　　　/*初始化t,res*/
         for(int i=nums.size()-1;i>=0;i--){
             int left=0,right=t.size();
　　　　　　　　/*下面是一个在t数组里二分查找的过程*/
             while (left<right){
                 int mid=left+(right-left)/2;
                 if(t[mid]>=nums[i]){
                     right= mid;
                 }
                 else{
                     left=mid+1;
                 }
             }
             res[i]=right;
             t.insert(t.begin()+right,nums[i]);
         }
         return res;
     }
 };
```

 

 

## 3. 记忆化+排序

还有个很第二种方法比较类似的方法，就是用STL的pari记录:没有排序前每个num[i]对应的下标i,pair<int,int>:nums[i]->i。

记录完之后进行排序。 然后利用已排序的性质进行查找，代码有些复杂且用到了一些位操作的知识，比较难想到，但也是一种非常好的方法。

```cpp
const int MAXN = 100007;

int cnt[MAXN],n;
/*数组cnt[i]用于记录出现元素nums[i]的个数*/
class Solution {
public:
    inline void add(int k)
    {
        for(; k <= n; k += -k&k) cnt[k] += 1;
    }
    
    int sum(int k)
    {
        int res = 0;
        for(; k; k -= -k&k) res += cnt[k];
        return res;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> A;
        /*建立一个从数组内容到未排序前索引的映射A*/
        for(int i = 0; i < n; i ++) {
            A.push_back({nums[i], i+1});
        }
        memset(cnt, 0, sizeof(cnt));
        sort(A.begin(), A.end());
        /*进行排序*/
        for(int i = 0; i < n; i ++) {
            int id = A[i].second;
            int t = sum(n) - sum(id);
            ans[id-1] = t;
            add(id);
        }
        return ans;
    }
};
```



## 4. 二叉搜索树

作为一个经常刷leetcode的人来说，刚开始看到这种方法简直是跪着看完的。建立一个二叉搜索树，每个树的结点都有变量val这个结点的值和变量count记录小于该结点的个数。
因为count的最后一个值的结果一定是0，所有先把0放入count数组，并建立一个以val为nums[i-1]的单独结点树。

逆序读nums[i]并建立二叉搜素树，首先排除nums.size()==0的情况，每读取一个nums[i]，先去搜索树寻找这个nums[i]对应的答案，
找到答案之后返回给引用参数count_small，再把nums[i]这个值作为新的结点的val插入。 
最后需要将树的结点delete以防内存浪费。
代码有详细注释。时间复杂度为O(nlogn)
```cpp
struct BSTNode{
    int val;
    int count;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x)
    : val(x)
    , left(NULL)
    , right(NULL)
    , count(0)
    {}
};
/*建立一个二分查找树，每个树结点有四个值,分别是:
 int val;这个结点代表的值val
 int count;这个val代表的次数也就是在nums数组种比val小的数的个数
 left 左子树指针
 right 右子树指针
 一个构造函数，构造函数如上定义
 */

void BST_insert(BSTNode *node,BSTNode *insert_node,int &count_small)
{
    if(node->val >= insert_node->val)
    {
        /*插入的结点更小,被比较结点(即node)的count++，然后插入到左子树(如果不为空)*/
        node->count++;
        if(node->left)
        {
            BST_insert(node->left,insert_node,count_small);
        }
        else
        {
            /*左子树为空，插入结点就作为当前结点的左孩子*/
            node->left = insert_node;
        }
    }
    else{
        /*插入的结点更大，需要在右子树(如果不为空)继续找*/
        count_small += node->count + 1;
        if(node->right)
        {
            BST_insert(node->right,insert_node,count_small);
        }
        else
        {
            /*当前右子树为空，插入结点作为当前结点右孩子*/
            node->right = insert_node;
        }
    }
}
/*count_small作为一个引用的参数，在递归寻找子树的时候作为一个“类似全局变量”的存在*/


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        /*如果数组为空返回空值*/
        if(n==0)return {};
        vector<int> count;
        count.push_back(0);
        /*建立一个二叉搜素树*/
        BSTNode* node=new BSTNode(nums[n-1]);
        int count_small;
        for(int i = 1;i < n;i++)
        {
            count_small = 0;
            BST_insert(node,new BSTNode(nums[n-i-1]),count_small);
            count.push_back(count_small);
        }
        /*最后不要忘记删除树节点*/
        delete node;
        reverse(count.begin(),count.end());
        /*push_back的时候是逆序的，此时只要将count数组reverse即可*/
        return count;
    }
};
```



## 5. 利用归并排序

这题比较“官方的”解法，因为这一道题我是在分治算法中找到的，所以我认为这一题出题的目的就是考查使用归并排序过程中求解满足条件的“点对”。代码直接引用了leetcode上的答案，
因为我觉得其注释已经非常完全了。这里我引用了一道我做别的题时写的题解，和下面这个代码思路是一样的。

在归并排序的过程中利用数组间已经有的大小关系，算出所需的解

每一次merge都将一个数组分成 **left**(即`nums[l]~nums[mid]`) 和**right**(即`nums[mid+1]~nums[r]`)两个区间
其中：

 1. left、right两个区间中满足条件的对数已经在上一次二分中算出
 2. 每次二分只需要算出**left** 和 **right** 之间满足条件的对数即可

对right中的每个元素，用**findl,findr**指针在**left区间**中划定连续的范围即可

题目要求的点对要符合以下条件:

**i<j  且nums[i]>nums[j]**

由归并排序升序的性质，可以知道

$$
nums[index]\leq nums[mid](index \leq mid) 
$$
$$
nums[index]\geq nums[mid](index \geq mid)
$$




我们只需要遍历**right**中的数并在**left**区间找到对应范围，这个范围只需要满足第二个条件**nums[i]>nums[j]**即可，因为第一个条件是一定满足了的。(**i<mid<j**)

步骤：

 1. 利用归并排序递归求解两个子区间内部对数并进行归并排序，此时**left**和**right**为递增区间
 2. 排序的同时遍历 在**right**区间中的数(设为**nums[i]**)，**left**区间找到满足这个条件的范围**findl~findr**,**findr~findl**即为左区间和 **nums[i]**匹配的点个数。


时间复杂度：$O(nlogn)$

```cpp

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>count;//保存结果
        vector<pair<int,int> > num;//关联每个数和它的序号
        for(int i =0;i<nums.size();++i)
        {
            count.push_back(0);
            num.push_back(make_pair(nums[i],i));//保存每个数和它在原数组中的序号，以免在排序过程中打乱顺序
        }
        merge_sort(num,count);
        return count;
    }
    
    //归并排序
    void merge_sort(vector<pair<int,int> >& vec, vector<int>& count)
    {
        if(vec.size()<2)
            return;
        
        int mid = vec.size()/2;
        vector<pair<int,int> > sub_vec1;
        vector<pair<int,int> > sub_vec2;
        for(int i =0;i<mid;++i)
            sub_vec1.push_back(vec[i]);
        for(int i =mid;i< vec.size();++i)
            sub_vec2.push_back(vec[i]);
        
        merge_sort(sub_vec1,count);
        merge_sort(sub_vec2,count);
        vec.clear();
        merge(sub_vec1,sub_vec2,vec,count);
    }
    
    //合并两数组
    void merge(vector<pair<int,int> >& sub_vec1,vector<pair<int,int> >& sub_vec2, vector<pair<int,int> >& vec, vector<int>& count)
    {
        int i =0;
        int j =0;
        while(i < sub_vec1.size() && j < sub_vec2.size())
        {
            if(sub_vec1[i].first <= sub_vec2[j].first )
            {
                vec.push_back(sub_vec1[i]);
                count[sub_vec1[i].second] += j;//这句话和下面注释的地方就是这道题和归并排序的主要不同之处
                i++;
            }else{
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        
        for(;i<sub_vec1.size();++i)
        {
            vec.push_back(sub_vec1[i]);
            count[sub_vec1[i].second] += j;// -。-
        }
        for(;j<sub_vec2.size();++j)
        {
            vec.push_back(sub_vec2[j]);           
        }
    }
};
```


## 6. 使用树状数组

这种解法比较少见，速度却是惊人的快。


　树状数组中*getSum(index)*作用是求原始数组**nums**中小于或等于当前index的数的和，此处用来统计逆序数，可以把getSum(x)看作是**nums**中小于x的数的个数的和。

 以题目中的测试数据`[5, 2, 6, 1]`为例：

初始状态数组c中元素全部置为0
- 插入5时，大于等于5的所有记录的值+1，此时比5小的数的个数为0；
- 插入2时，大于等于2的所有记录的值+1，此时比2小的数的个数为0，比5小的数的个数为1；
- 插入6时，大于等于6的所有记录的值+1，此时比6小的数的个数为2(`getSum(6-1)=2`)，比2小的数的个数为0，比5小的数的个数为1(`getSum(5-1)=1`)；
- 插入1时，大于等于1的所有记录的值+1，此时比1小的数的个数为0，比6小的数的个数为3(`getSum(6-1)=3`)，比2小的数的个数为1(`getSum(2-1)=1`)，比5小的数的个数为2(`getSum(5-1)=2`)；

 可以看出当把每个数都遍历一遍后，数组arr中分别记录了比每个数小的数的个数之和，题目要求每个数右侧比它小的数的个数，因此用总数减掉每个数左侧比它小的数的个数就可得到。

　从插入元素的过程可以看出，每次插入一个元素时，数组arr中记录的值刚好是插入当前元素之前比该元素小的元素的个数（即当前元素左侧比它小的元素个数），因此只需要在插入一个数之前做一次求和，并用一个数组记录该值即可。

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>count;//保存结果
        vector<pair<int,int> > num;//关联每个数和它的序号
        for(int i =0;i<nums.size();++i)
        {
            count.push_back(0);
            num.push_back(make_pair(nums[i],i));//保存每个数和它在原数组中的序号，以免在排序过程中打乱顺序
        }
        merge_sort(num,count);
        return count;
    }
    
    //归并排序
    void merge_sort(vector<pair<int,int> >& vec, vector<int>& count)
    {
        if(vec.size()<2)
            return;
        
        int mid = vec.size()/2;
        vector<pair<int,int> > sub_vec1;
        vector<pair<int,int> > sub_vec2;
        for(int i =0;i<mid;++i)
            sub_vec1.push_back(vec[i]);
        for(int i =mid;i< vec.size();++i)
            sub_vec2.push_back(vec[i]);
        
        merge_sort(sub_vec1,count);
        merge_sort(sub_vec2,count);
        vec.clear();
        merge(sub_vec1,sub_vec2,vec,count);
    }
    
    //合并两数组
    void merge(vector<pair<int,int> >& sub_vec1,vector<pair<int,int> >& sub_vec2, vector<pair<int,int> >& vec, vector<int>& count)
    {
        int i =0;
        int j =0;
        while(i < sub_vec1.size() && j < sub_vec2.size())
        {
            if(sub_vec1[i].first <= sub_vec2[j].first )
            {
                vec.push_back(sub_vec1[i]);
                count[sub_vec1[i].second] += j;//这句话和下面注释的地方就是这道题和归并排序的主要不同之处
                i++;
            }else{
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        
        for(;i<sub_vec1.size();++i)
        {
            vec.push_back(sub_vec1[i]);
            count[sub_vec1[i].second] += j;// -。-
        }
        for(;j<sub_vec2.size();++j)
        {
            vec.push_back(sub_vec2[j]);           
        }
    }
};
```