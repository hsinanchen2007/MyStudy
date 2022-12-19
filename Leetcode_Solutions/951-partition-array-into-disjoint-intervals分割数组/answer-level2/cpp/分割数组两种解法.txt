> 首先枚举分割点的位置，只要把分割点左边数组的最大值，和分割点右边数组的最小值求出，然后比较这两个最值，只要左边的最大值小于等于右边的最小值即可满足。

**所以现在的问题只要枚举分割点，并维护左右的最值即可**

### 算法1：
> 思路来源：求数组的最大连续子序和，通过一个数组维护当前位置的往前往后的最值，然后枚举分割点的位置即可。
```
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0);
        vector<int> right(n,INT_MAX);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1],nums[i]);
        }
        for (int i = n - 2; ~i; i--) {
            right[i] = min(right[i+1],nums[i]);
        }
        for (auto i : left) {
            cout<<i<<" ";
        }
        cout<<endl;
        for (auto i : right) {
            cout<<i <<" ";
        }
        for (int i = 1; i < n; i++) {
            if (left[i - 1] <= right[i]) {
                return i;
            }
        }
        return 0;
    }
};
```
### 算法2：
> 杀鸡用牛刀，现在只要将分割点左边的最值求出，右边的最值求出，分割点已知，左区间已知，右区间已知，很容易想到线段树，使用线段树来维护区间的最值。
```
const int N = 30010;
struct Node{
    int left,right,max_,min_;
};
Node tree[4*N];

class Solution {
public:
    void push_up(int rt) {
        tree[rt].max_ = max(tree[rt<<1].max_,tree[rt<<1|1].max_);
        tree[rt].min_ = min(tree[rt<<1].min_,tree[rt<<1|1].min_);
    }
    void build(int rt,int left,int right,vector<int>& nums) {
        tree[rt].left = left;
        tree[rt].right = right;
        if (left == right) {
            tree[rt].max_ = tree[rt].min_ = nums[left];
        }else{
            int mid = left + right >> 1;
            build(rt<<1,left,mid,nums);
            build(rt<<1|1,mid+1,right,nums);
            push_up(rt);
        }
    }
    pair<int,int> query(int rt,int left,int right) {
        if (left > tree[rt].right || tree[rt].left > right) {
            return {INT_MAX,INT_MIN};
        }
        if (left <= tree[rt].left && tree[rt].right <= right) {
            return {tree[rt].min_,tree[rt].max_};
        }else {
            auto l = query(rt<<1,left,right);
            auto r = query(rt<<1|1,left,right);
            return {min(l.first,r.first),max(l.second,r.second)};
        }
    }
    int partitionDisjoint(vector<int>& A) {
        const int rt = 1;
        const int left = 0,right = A.size() - 1;
        build(rt,left,right,A);
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = query(rt,left,i).second;
            int r = query(rt,i + 1,right).first;
            if (l <= r) {
                return i + 1;
            }
        }
        return 0;
    }
};
```
