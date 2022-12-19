看了一部分题解，发现了两种递归求解的方法，一种是把解空间当做二叉树进行深度优先或者广度优先的遍历，一种则是把解空间当做图进行深度优先的遍历。现分别进行分析
# 解空间当做二叉树进行遍历
解空间当做二叉树，每个结点就是本层对应的数字是否进入解后形成的临时结果，左子树是下一层对应数字进入解后形成的临时结果，右子树是下一层对应数字不进入解后形成的临时结果，那么，最后所有的叶子结点就是所有的最终结果。
![二叉树.jpg](https://pic.leetcode-cn.com/55864eb548755a124e5a5a05e9600089195a28c4ca2d82bb6c66df1ce865df38-%E4%BA%8C%E5%8F%89%E6%A0%91.jpg)

对这棵二叉树无论是先序中序后序或者层次遍历，最后的叶子结点就是解。
其他递归解法各个答案都有，举个层次遍历的例子：
```
class Solution3 {
public:
    struct result
    {
        vector<int> res;
        int pos;
        bool used;        
    };
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        queue<result> queue;
        queue.push({vector<int>(),0,true});
        queue.push({vector<int>(),0,false});
        while(!queue.empty())
        {
            result node = queue.front();
            queue.pop();
            if(node.pos==nums.size()-1)
            {
                if(node.used)
                    node.res.push_back(nums[node.pos]);
                res.push_back(node.res);
                continue;
            }
            else
            {
                if(node.used)
                    node.res.push_back(nums[node.pos]);
                queue.push({node.res,node.pos+1,true});
                queue.push({node.res,node.pos+1,false});
            }
        }
        return res;
    }
};
```

无论是何种遍历顺序，最后一定访问到了树中所有的结点，可以看到，每一个数字都作为二叉树的一层存在，其结点是该数字选取或者不选取后的临时结果，层高H的二叉树叶子结点总数是2^H-1 ，那么这种遍历的时间复杂度是O(2^N)

# 解空间当做图的深度优先遍历
解空间当做图，则这个图的结点构成依据是解里面元素的个数，即空集邻接了{1},{2},{3}，而集合
{1}邻接了{1,2},{1,3},集合{2}邻接{2,3}，集合{1,2}邻接了{1,2,3}
一种可能的图如下
![图.jpg](https://pic.leetcode-cn.com/e5faf1fe87c3c1284c3175d85cd9d4a48716fef8a038ca3a7ea8a962285b972e-%E5%9B%BE.jpg)

对于这种图，它的每一个结点是满足题目要求的一个解，结点之间的相邻关系取决于该结点是否还可以塞入其他元素。
对于这种图，一种遍历方法如下：
```
class Solutionx {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(0,0,ans,vec,nums);
        return ans;
    }
    void dfs(int step,int num,vector<vector <int>> &ans,vector<int>& vec,vector<int>nums)
    {
        if(num <= nums.size())
        {
            ans.push_back(vec);
        }
        for(int i = step;i < nums.size();i++)
        {
            vec.push_back(nums[i]);
            dfs(i + 1,num + 1,ans,vec,nums);
            vec.pop_back();//这就是回溯吧
        }
    }
};
```


对于这种递归回溯算法，如何计算其时间复杂度呢，一种方法是根据它遍历的元素个数确定，由于我们知道一共有2^N个组合解，那么无论何种遍历方法，最后找到的解一定是这么多，那么时间复杂度应该也是O(2^N),还有一种是程序分析的方法，如下：

我们认为`vec.push_back(nums[i]);`是一个关键操作，那么对于index=N-1时，该操作执行了一次
N-2时，该操作在本函数中执行了2次，在递归i+1时执行了一次，设T(N-1)表示index=N-1时关键操作的执行次数，则具体推导过程如下：
![微信图片_20200218155808.jpg](https://pic.leetcode-cn.com/ea398d5b851b50c0fb58e7b9092c3018d7a7f21f4fa62596e7fb670e3bc56a8b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200218155808.jpg)

最后，根据程序分析的方法，T(N-1)=1 , T(N-2)=2T(N-1)+1 , T(N-3)=2T(N-2)+1 ...  T(0)=2^N -1
所以，这种方法的时间复杂度依然是O(2^N)
