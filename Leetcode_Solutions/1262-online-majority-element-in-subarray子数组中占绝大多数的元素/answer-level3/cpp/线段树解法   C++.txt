看到楼下的解法，刚开始不太理解，后来用C++重新写了一遍，终于理解楼下的做法了.
解法非常巧妙，利用了众数的特性，解法非常榜。

```c++ []
struct SegTreeNode{
    int l;
    int r;
    int val;
    int count;
    SegTreeNode * left;
    SegTreeNode * right;
    SegTreeNode(int l,int r){
        this->l = l;
        this->r = r;
        this->val = 0;
        this->count = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

bool pushupTree(SegTreeNode * root){
    if(!root){
        return false;
    }
        
    if(root->left){
        root->val = root->left->val;
        root->count = root->left->count;
    }
    if(root->right){
        if(root->val == root->right->val){
            root->count += root->right->count;
        }else if(root->count >= root->right->count){
            root->count -= root->right->count;
        }else if(root->count < root->right->count){
            root->val = root->right->val;
            root->count = root->right->count - root->count;
        }
    }
    
    return root;
}

SegTreeNode * buildTree(vector<int> & arr,int l,int r){
    if(l > r){
        return NULL;
    }
    
    SegTreeNode * root = new SegTreeNode(l,r);
    if(l == r){
        root->val = arr[l];
        root->count = 1;
        return root;
    }
    
    int mid = (l+r)/2;
    root->left = buildTree(arr,l,mid);
    root->right = buildTree(arr,mid+1,r);
    pushupTree(root);
    
    return root;
}

bool searchTree(SegTreeNode * root,int l,int r,int &key,int &count){
    if(!root || l > r){
        return false;
    }
    
    if(root->r < l && root-> l > r){
        return false;
    }
  
    int mid = (root->l + root->r)/2;
    if(root->l >= l && root->r <= r){
        if(root->val == key){
            count += root->count;
        }else if(root->count > count){
            key = root->val;
            count = root->count - count;
        }else if(root->count <= count){
            count -= root->count;
        }
        return true;
    }
    
    if(mid >= l){
       searchTree(root->left,l,r,key,count); 
    }
    if(r >= mid +1){
        searchTree(root->right,l,r,key,count);
    }
    
    return true;
}

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        for(int i = 0;i < arr.size(); ++i){
            idx[arr[i]].push_back(i);
        }
        root = buildTree(arr,0,arr.size()-1);
    }
    
    int query(int left, int right, int threshold) {
        int key = 0;
        int count = 0;
        searchTree(root,left,right,key,count);
        if(key == 0 ||idx[key].size() < threshold){
            return -1;
        }
        
        auto it_l = lower_bound(idx[key].begin(),idx[key].end(),left);
        auto it_r = upper_bound(idx[key].begin(),idx[key].end(),right);
        if(it_r - it_l >= threshold){
            return key;
        }else{
            return -1;
        }
    }
private:
    unordered_map<int,vector<int>> idx;
    SegTreeNode * root;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```
```python []
class SegTreeNode(object):
    def __init__(self,l,r):
        self.l = l
        self.r = r
        self.val = 0
        self.cnt = 0
        self.left = None
        self.right = None
    
class SegTree(object):
    def __init__(self,arr):
        n = len(arr)
        self.keys = arr
        self.root = self.build(0,n-1)
        
    def build(self,l,r):
        if l > r:
            return None
        
        node = SegTreeNode(l,r)
        if l == r:
            node.val = self.keys[l]
            node.cnt = 1
            return node
        
        mid = (l+r)/2
        node.left = self.build(l,mid)
        node.right = self.build(mid+1,r)
        self.pushup(node)
        
        return node
    
    def pushup(self,node):
        if node is None:
            return False
        
        if node.left is not None:
            node.val = node.left.val
            node.cnt = node.left.cnt
        if node.right is not None:
            if node.val == node.right.val:
                node.cnt += node.right.cnt
            elif node.cnt >= node.right.cnt:
                node.cnt -= node.right.cnt
            elif node.cnt < node.right.cnt:
                node.val = node.right.val
                node.cnt = node.right.cnt - node.cnt
        
        return True
    
    def query(self,l,r):
        tar = [0,0]
        tar = self.search(self.root,l,r,0,0)
        
        if tar[0] == 0:
            return -1
        else:
            return tar[0]
    
    def search(self,node, l, r, key, cnt):
        if node is None or l > r:
            return [0,0]
        
        if node.l > r or node.r < l:
            return [0,0]
        
        if node.l >= l and node.r <= r:
            if node.val == key:
                cnt += node.cnt
            elif node.cnt >= cnt:
                key = node.val
                cnt = node.cnt - cnt
            elif node.cnt < cnt:
                cnt -= node.cnt
            
            return [key,cnt]
        
        mid = (node.l + node.r)/2
        res = [0,0]
        
        if mid >= l:
            res = self.search(node.left,l,r,key,cnt)
        if mid+1 <= r:
            res = self.search(node.right,l,r,res[0],res[1])
        
        return res
    
class MajorityChecker(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.tree = SegTree(arr)
        self.idx = collections.defaultdict(list)
        for i, num in enumerate(arr):
            self.idx[num] += [i]

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        maj = self.tree.query(left,right)
        if maj == 0:
            return -1
        
        l_idx = bisect.bisect_left(self.idx[maj], left)
        r_idx = bisect.bisect(self.idx[maj], right)
        if r_idx - l_idx >= threshold:
            return maj
        else:
            return -1
        
        


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
```