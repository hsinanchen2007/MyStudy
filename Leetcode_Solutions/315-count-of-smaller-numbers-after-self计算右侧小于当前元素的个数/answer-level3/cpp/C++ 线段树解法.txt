首先构造如下线段树，每个圆圈表示一个结点，结点包含如下信息：

- 线段范围
    - start
    - end
- 线段范围内有几个元素
    - count
- 指向左右结点的指针
    - left（左结点的线段范围是[start, start+(end-start)/2]）
    - right(右结点的线段范围是[start+(end-start)/2+1, end])

如下是一个实例
![segment_tree.png](https://pic.leetcode-cn.com/5089a469295d9628c19a2bcad3573f16cbc1f02161a45de9bea44540b72d8f14-segment_tree.png)


根据这道题来说，线段树的操作函数有三个：

- build():构造线段树
    - 找出数组中最小和最大的元素，做为根节点的线段范围
    - 比如[2,3,4,1]的线段树根节点范围为[1,4]
- insert(int index)):插入一个元素，并更新线段树的count值
    - 比如实例图中插入元素3，则[1,4],[3,4],[3,3]的结点count值都+1
- count(int start, int end):返回[start, end]的count值
    - 比如要找小于元素(记为x)的个数，就是统计线段树中[min, x-1]的个数，其中min为线段树的最小值

对于这道题来说，步骤如下：

- 遍历数组，找到数组的min和max，构造线段树[min, max]
- 从右往左遍历，记当前元素为x
    - 统计线段树中[min, x-1]范围内的元素，即右侧小于x的元素个数
    - 往线段树中插入元素x，并更新线段树各个结点的count值

一个简单的示例

![leetcode315.png](https://pic.leetcode-cn.com/5437f33179ca9afbfc6043c3d556194bbdc4411978fd64ef803408b2f22693dd-leetcode315.png)



```cpp
struct SegmentTreeNode{
        int start;
        int end;
        int count;

        SegmentTreeNode* left;
        SegmentTreeNode* right;

        SegmentTreeNode(int _start, int _end):start(_start),end(_end) {
            count = 0;
            left = NULL;
            right = NULL;
        }
};

class Solution {
public:
    SegmentTreeNode* build(int start, int end){
        if (start > end)
            return NULL;
        
        SegmentTreeNode* root = new SegmentTreeNode(start, end);

        if (start == end){
            root->count = 0;
        }else{
            int mid = start + (end - start)/2;
            root->left = build(start, mid);
            root->right = build(mid+1, end);
        }
        return root;
    }

    int count(SegmentTreeNode* root, int start, int end){
        if (root == NULL || start>end)
            return 0;
        if (start==root->start && end==root->end){
            return root->count;
        }
        int mid = root->start + (root->end - root->start)/2;
        int leftcount = 0, rightcount = 0;

        if (start <= mid){
            if (mid < end)
                leftcount = count(root->left, start, mid);
            else
                leftcount = count(root->left, start, end);
        }

        if (mid < end){
            if (start <= mid)
                rightcount = count(root->right, mid+1, end);
            else
                rightcount = count(root->right, start, end);
        }

        return (leftcount + rightcount);
    }

    void insert(SegmentTreeNode* root, int index, int val){
        if (root->start==index && root->end==index){
            root->count += val;
            return;
        }

        int mid = root->start + (root->end - root->start)/2;
        if (index>=root->start && index<=mid){
            insert(root->left, index, val);
        }
        if (index>mid && index<=root->end){
            insert(root->right, index, val);
        }

        root->count = root->left->count + root->right->count;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        res.resize(nums.size());
        int start = nums[0];
        int end = nums[0];

        for (int i=1; i<nums.size(); i++){
            start = min(start, nums[i]);
            end = max(end, nums[i]);
        }

        SegmentTreeNode* root = build(start, end);

        for (int i=nums.size()-1; i>=0; i--){
            res[i] = count(root, start, nums[i]-1);
            insert(root, nums[i], 1);
        }  

        return res;      
    }
};
```

同步在博客上和公众号上：

[leetcode No315. Count of Smaller Numbers After Self](https://blog.csdn.net/u011391629/article/details/104631973)

![QR_258.jpg](https://pic.leetcode-cn.com/ab1f63a2597446319c8896feedbf7dbae802ee5f5bf91773c2706a0a68905d83-QR_258.jpg)

