解题思路：
题目里有两个关键词，“相邻”和“评分高”，这意味着如果不相邻，他们之间的糖果数没有必然关系；如果两个相邻的分数相等，他们的糖果数可以一多一少、也可以一样。要求总糖果数最少，首先想到了贪心算法，先从N人中找出分数最低的人，有三种情况：
a.如果相邻两侧没有比他分数低的人，则他的数量为1。
b.如果一侧分数低，另一侧相等或高，则他的数量为低的那一侧的糖果数量加1。
c.如果两侧分数都比他低，则他的数量为两侧糖果数较大的那一侧的糖果数量加1。
一开始用暴力法，设置一个访问数组vis[]和一个糖果数组nums[]（num[]的元素全部初始化为1），不断从左往右找出未被访问的当前分数最低的人，按照上面三种情况求出每人的糖果数并存进nums[]中，标记vis[]中相应元素为true，最后对nums[]的元素进行累加得到总的糖果数。这种方法的时间复杂度是O(n2)，算法的正确性没问题，但是在提交时，发现有用例超时了！！！

我发现时间主要耗费在每次寻找最低分的两个for循环上，改用了C++的STL中的multimap来解题。multimap的特点是允许键值重复，且元素在插入时默认按照升序排列。对题目给出的一个分数排列，可以把分数作为key，把下标（位置）作为value，存进multimap中，每次只要按顺序遍历声明的multimap，即可得到当前的最低分以及对应的位置下标，每个人糖果数量计算方法同上面一样。不考虑multimap的内部构造，这种方法的时间复杂度为O(n)；考虑的话时间复杂度为O(nlogn)。
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        if(ratings.size()==1)
            return 1;
        int res=0,i=0,j=0;
        multimap<int, int>mp;
        for(i=0;i<ratings.size();++i)
            mp.insert(pair<int, int>(ratings[i], i));
        vector<int>nums;                     //每人糖果数量
        for(i=0;i<ratings.size();++i)       //初始化                
            nums.push_back(1);
        multimap<int, int>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            int minid = it->second;
            if(minid != 0 && minid != ratings.size()-1){    //在中间
                if(ratings[minid-1] >= ratings[minid] && ratings[minid+1] >= ratings[minid])
                    nums[minid]=1;
                else if(ratings[minid-1] >= ratings[minid] && ratings[minid+1] < ratings[minid])
                    nums[minid]=nums[minid+1]+1;
                else if(ratings[minid-1] < ratings[minid] && ratings[minid+1] >= ratings[minid])
                    nums[minid]=nums[minid-1]+1;
                else
                    nums[minid]=(nums[minid-1] > nums[minid+1] ? nums[minid-1] : nums[minid+1]) + 1;          
            }
            else if(minid == 0)                          //在开头
                nums[minid] = ratings[minid+1] >=ratings[minid]? 1 : nums[minid+1]+1;
            else                                         //在末尾
                nums[minid] = ratings[minid-1] >=ratings[minid]? 1 : nums[minid-1]+1;
        }
        for(i=0;i<ratings.size();++i)
            res+=nums[i];
        return res;
    }
};
```
