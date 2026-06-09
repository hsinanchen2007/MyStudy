```cpp
const int N = 1e5 + 1;
struct Node{
    int val,left,right;
};
Node tree[N*4];
void push_up(int rt) {
    tree[rt].val = tree[rt<<1].val + tree[rt<<1|1].val;
}
void build(int rt,int left,int right) {
    tree[rt].left = left,tree[rt].right = right;
    if (left == right) {
        tree[rt].val = 0;
    }else{
        int mid = left + right >> 1;
        build(rt<<1,left,mid);
        build(rt<<1|1,mid + 1, right);
        push_up(rt);
    }
}
void modify(int rt,int pos,bool flag) {
    if (tree[rt].left == tree[rt].right) {
        if (flag) tree[rt].val++;
        else tree[rt].val--;
    }else{
        int mid = tree[rt].left + tree[rt].right >> 1;
        if (pos <= mid) {
            modify(rt<<1,pos,flag);
        }else{
            modify(rt<<1|1,pos,flag);
        }
        push_up(rt);
    }
}
int query(int rt,int left,int right) {
    if (tree[rt].left > right || tree[rt].right < left) return 0;
    if (tree[rt].left >= left && tree[rt].right <= right) return tree[rt].val;
    else{
        int mid = tree[rt].left + tree[rt].right >> 1;
        if (mid < left) {
            return query(rt<<1|1,left,right);
        }else if (mid >= right) {
            return query(rt<<1,left,right);
        }else{
            return query(rt<<1,left,mid) + query(rt<<1|1,mid + 1,right);
        }
    }
}
class Solution {
public:
    int inversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        for (int i = 0; i < n; i++) {
            nums[i] = lower_bound(arr.begin(),arr.end(),nums[i]) - arr.begin();
        }
        const int rt = 1;
        int left = 0,right = arr.size() - 1;
        build(rt,left,right);
        for (int i = 0; i < n; i++) {
            modify(rt,nums[i],true);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += query(rt,left,nums[i] - 1);
            modify(rt,nums[i],false);
        }
        return ans;
    }
};
```