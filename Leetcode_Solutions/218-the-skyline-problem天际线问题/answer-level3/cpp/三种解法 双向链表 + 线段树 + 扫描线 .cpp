# 天际线问题

城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。现在，假设您获得了城市风光照片（图A）上显示的所有建筑物的位置和高度，请编写一个程序以输出由这些建筑物形成的天际线（图B）。

![天际线](https://pic.leetcode-cn.com/16516e2fc719cf33b9447d6fa29e96eb9ade2e1b7849b76011b9cb0e5b171c3b-1581677956842.png)

每个建筑物的几何信息用三元组 $[L_i，R_i，H_i]$ 表示，其中 $L_i$ 和 $R_i$ 分别是第 $i$ 座建筑物左右边缘的 x 坐标，$H_i$ 是其高度。可以保证 $0 ≤ L_i$, $R_i ≤ INT\_MAX$, $0 < H_i ≤ INT\_MAX$ 和 $R_i - L_i > 0$。您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。

例如，图A中所有建筑物的尺寸记录为：[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] 。

输出是以 $[ [x_1,y_1], [x_2, y_2], [x_3, y_3], ... ]$ 格式的“关键点”（图B中的红点）的列表，它们唯一地定义了天际线。关键点是水平线段的左端点。请注意，最右侧建筑物的最后一个关键点仅用于标记天际线的终点，并始终为零高度。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

例如，图B中的天际线应该表示为：[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]。

说明:

任何输入列表中的建筑物数量保证在 [0, 10000] 范围内。
输入列表已经按左 x 坐标 Li  进行升序排列。
输出列表必须按 x 位排序。
输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

------

## 双向链表

这道题让我联想到了上个学期OS课写的连续内存分配，当时我是用的双向链表来维护内存空间。没有采用线性表是为了更方便调试（~~就是懒没错~~），印象中室友写了个线性表就因为一个小问题花了好多时间来debug(雾。

言归正传，这道题也可以利用同样的思想来维护一段空间，我们用如下的数据结构来表示每一个独立区间（所谓独立区间就是与其相邻区间高度不同的区间）。

```c++
struct Node {
    int height;
    int left;
    int right;
    Node* next;
    Node* pre;
    bool isPoint()
    {
        return left == right;
    }
    Node(int i, int j): left(i), right(j),height(0) {}
    Node(int i, int j, int h): left(i), right(j),height(h) {}
    Node(int h): left(NULL), right(NULL), height(h) {}
};
```

初始区间为`[INT_MIN, INT_MAX]`，其高度为0。之后每加入一个新的建筑，都要更新一次区间。区间更新逻辑如下

1. 新加入建筑物的高度小于等于其覆盖到区间的高度，不产生影响。
2. 新加入建筑物的高度大于其覆盖区间的高度，则将覆盖区间的高度更新为新建筑的高度。

由于并不是所有的区间都是恰好被新加入的建筑物覆盖的，因此我们还考虑区间的拆分问题。

对于上面的这些问题，我的思路如下

1. 先确定新建筑物波及的区间。
2. 对头区间和尾区间进行特殊处理（因为只有头尾区间才会面临区间拆分的可能性）
3. 对头尾之间的其他区间进行同高度合并。

具体实现在如下代码中，关键步骤有注释

```c++
struct Node {
    int height;
    int left;
    int right;
    Node* next;
    Node* pre;
    bool isPoint()
    {
        return left == right;
    }
    Node(int i, int j): left(i), right(j),height(0) {}
    Node(int i, int j, int h): left(i), right(j),height(h) {}
    Node(int h): left(NULL), right(NULL), height(h) {}
};

// 在left，right间加入cur
void connect(Node* left, Node* right, Node* cur)
{
    left->next = cur;
    cur->next = right;
    right->pre = cur;
    cur->pre = left;
}

// 删除结点cur
void deleteNode(Node*cur)
{
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;
    delete cur;
}

//向左合并，直到遇到头节点或者高度不同的区间
void leftMerge(Node* cur)
{
    Node* pre = cur->pre;
    while(pre->height != -1 && pre->height == cur->height)
    {
        cur->left = pre->left;
        deleteNode(pre);
        pre = cur->pre;
    }
}

//向右合并，直到遇到尾节点或者高度不同的区间
void rightMerge(Node* cur)
{
    Node* next = cur->next;
    while(next->height != -1 && next->height == cur->height)
    {
        cur->right = next->right;
        deleteNode(next);
        next = cur->next;
    }
    
}


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())   return {};
        Node* head = new Node(-1);
        Node* tail = new Node(-1);
        Node* tmp = new Node(INT_MIN, INT_MAX);
        connect(head,tail,tmp);


        for(auto& b: buildings)
        {
            int left = b[0];
            int right = b[1];
            int height = b[2];

            Node* cur = head->next;
            while(cur != tail)
            {
                if(left >= cur->right)  
                {
                    cur = cur->next;
                    continue;
                }
                else    //找到头区间
                {
                    if(right <= cur->right) // 若新加入区间正好落在头区间内
                    {
                        if(height > cur->height)
                        {
                            Node* tmp1 = new Node(left,right,height);
                            Node* tmp2 = NULL;
                            if(cur->right != right)
                                tmp2 = new Node(right, cur->right,cur->height);
                            cur->right = left;
                            connect(cur, cur->next, tmp1);
                            if(tmp2)
                                connect(tmp1,tmp1->next,tmp2);
                            if(cur->isPoint())  deleteNode(cur);
                            leftMerge(tmp1);    
                            rightMerge(tmp1);
                            //左右合并相同高度的区间
                        }
                        
                    }
                    else
                    {
                        Node* h = cur;  //头区间
                        Node* t = cur->next;    // 确定尾区间
                        while(t->right < right)
                        {
                            if(height > t->height)
                                t->height = height;
                            t = t->next;
                        }

                        // 单独处理头区间
                        if(h->height < height)
                        {
                            if(h->left == left) // 新建筑物左侧与头区间左侧重合
                            {
                                h->height = height;
                                leftMerge(h);
                            }
                            else
                            {
                                Node* tmp = new Node(left,h->right, height);
                                h->right = left;
                                connect(h,h->next,tmp);
                                h = tmp;
                            }
                        }

                        //单独处理尾区间
                        if(t->height < height)
                        {
                            if(t->right == right)   // 新建筑物右侧与尾区间左侧重合
                            {
                                t->height= height;
                                rightMerge(t);
                            }
                            else
                            {
                                Node* tmp = new Node(right, t->right, t->height);
                                t->right = right;
                                t->height = height;
                                connect(t,t->next,tmp);
                            }
                        }

                        // 合并头尾区间之间的同高度区间
                        Node* p = h;
                        int temp = t->right;
                        while(p!=tail && p->right <= temp)
                        {
                            rightMerge(p);
                            p = p->next;
                        }
                        


                    }
                    break;
                }
            }

        }

        vector<vector<int>> res;
        Node* p = head->next;
        if(p->height != 0)  // INT_MIN也被建筑物覆盖的情况
            res.push_back({p->left, p->height});
        p = p->next;
        
        while(p != tail)
        {
            
            res.push_back({p->left, p->height});
            p = p->next;
        }

        // INT_MAX也被建筑物覆盖的情况
        p = p->pre;
        if(p->height != 0 && p->right == INT_MAX)
            res.push_back({INT_MAX,0});
        return res;
    }
};
```

> 这个方法最坏情况的时间复杂度是$O(n^2)$（建筑物序列按左坐标升序排列且不重合）。但在通常情况下，由于建筑物重合的缘故，区间的数目会处在一个比较低的水平，对于处理实际问题来说也不失为一个好的方法。最终leetcode执行用时20ms,击败100%用户；内存消耗13.8MB，击败99.11%用户也证明了这一点。

## 扫描线

接下来我们来换一种思路，先来考虑一下关键点生成的条件。我们知道由于建筑物重合的缘故，每一个坐标可能被多个建筑物覆盖，我们在这点上看到的天际线正是这些建筑物中最高的那一个产生的。为了便于表述我们将坐标`i`处的天际线高度记为`h[i]`。从左至右遍历每一个坐标，当`h[i]`改变了，关键点就产生了。

根据这个思路我们不难想到可以用堆来维护加入建筑物左右两侧的高度（对应c++中的`multiset`）。特别注意，为了区分左右两侧，建筑物的左侧高度用负数表示，右侧高度用正数表示。

```c++
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> new_set;
        multiset<int> height;
        vector<vector<int>> res;

        for(auto& b: buildings)
        {
            new_set.push_back({b[0], -b[2]});   
            new_set.push_back({b[1], b[2]});
        }

        sort(new_set.begin(), new_set.end());
        height.insert(0);
        int pre = 0;
        int cur = 0;
        for(auto line: new_set)
        {
            if(line.second < 0) height.insert(-line.second);
            else    height.erase(height.find(line.second));
            cur = *height.rbegin();
            if(cur != pre)  //转折点
            {
                res.push_back({line.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
```

## 线段树

用[线段树](http://www.gavinld.com/2020/02/16/线段树/)处理区间问题是一个好的思路。具体的实现思路如下

1. 离散化坐标，建立新坐标和原坐标之间的映射。

2. 延迟更新思路-当节点对应的区间落入待更新的区间中对该节点的高度进行更新，其子节点延迟更新。

   ```c++
   void update(int root, int tl, int tr, int l, int r, int height)
   {
       if(l > tr || r < tl)    return;
       else if(l <= tl && tr <= r)	//节点对应的区间落入待更新的区间中
       {
           if(height > Tree[root].height)
               Tree[root].height = height;
       }
       else
       {
           int mid = (tl + tr) / 2;
           update(2*root, tl, mid, l, r, height);
           update(2*root+1, mid+1, tr, l, r, height);
       }
   }
   ```

3. 关键点的导出，为了方便起见我们只考虑叶子节点。同时因为我们的更新思路是带延迟的，还要记得先对探索到的中间节点执行更新下达操作。

   ```c++
   void queryRes(vector<vector<int>>& res, int root)
   {
       if(Tree[root].isLeaf)	// 叶子节点
       {
           if(res.empty() || res.back()[1] != Tree[root].height)	//和前一个小区间高度不同，关键点出现！
               res.push_back({Tree[root].left, Tree[root].height});
       }
       else
       {
           if(Tree[root].height > 0)	//下达更新
           {
               Tree[2*root].height = max(Tree[2*root].height, Tree[root].height);
               Tree[2*root+1].height = max(Tree[2*root+1].height, Tree[root].height);
           }
           queryRes(res, 2*root);
           queryRes(res, 2*root+1);
       }
   }
   ```

   

完整代码如下

```c++
class Solution {
private:
    Node* Tree;
    unordered_map<int, int> dict1;   // 实际坐标->新坐标
    vector<int> dict2;
public:
    void build(int root, int l, int r)
    {
        //cout << root << '\t' << l << '\t' << r << endl;
        //cout << Tree[root].left << endl;
        if(l > r)   return;
        else if(l == r)
        {
            
            Tree[root].left = dict2[l];
            Tree[root].isLeaf = 1;
        }
        else
        {
            int mid = (l + r) / 2;
            build(root*2, l, mid);
            build(root*2+1,mid+1, r);
        }

    }
    void update(int root, int tl, int tr, int l, int r, int height)
    {
        if(l > tr || r < tl)    return;
        else if(l <= tl && tr <= r)
        {
            if(height > Tree[root].height)
                Tree[root].height = height;
        }
        else
        {
            int mid = (tl + tr) / 2;
            update(2*root, tl, mid, l, r, height);
            update(2*root+1, mid+1, tr, l, r, height);
        }
    }

    void queryRes(vector<vector<int>>& res, int root)
    {
        if(Tree[root].isLeaf)
        {
            if(res.empty() || res.back()[1] != Tree[root].height)
                res.push_back({Tree[root].left, Tree[root].height});
        }
        else
        {
            if(Tree[root].height > 0)
            {
                Tree[2*root].height = max(Tree[2*root].height, Tree[root].height);
                Tree[2*root+1].height = max(Tree[2*root+1].height, Tree[root].height);
            }
            queryRes(res, 2*root);
            queryRes(res, 2*root+1);
        }
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())   return {};
        set<int> st;
        vector<vector<int>> res;
        for(auto& b: buildings)
        {
            st.insert(b[0]);
            st.insert(b[1]);
        }
		
        // 离散化并建立映射
        int cnt = 0;
        for(auto iter = st.begin(); iter != st.end(); iter++)
        {
            dict2.push_back(*iter);
            dict1[*iter] = cnt++; 
        }

        Tree = new Node[4*cnt];

        build(1, 0, cnt-1);

        for(auto& b: buildings)
            update(1, 0, cnt-1, dict1[b[0]], dict1[b[1]]-1, b[2]);
        

        queryRes(res, 1);
        return res;

    }
};
```

