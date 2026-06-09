```
void build_tree(vector<int>& nums, vector<int>& tree, int node, int start, int end) {
        if(start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(nums, tree, left_node, start, mid);
        build_tree(nums, tree, right_node, mid+1, end);
        
        tree[node] = tree[left_node] + tree[right_node];
        return;
    }
    void update_tree(vector<int>& nums, vector<int>& tree, int node, int start, int end, int idx, int val) {
        if(start == end) {
            nums[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        //说明在左子树
        if(idx >= start && idx <= mid) {
            update_tree(nums, tree, left_node, start, mid, idx, val);

        } else {
            update_tree(nums, tree, right_node, mid+1, end, idx, val);
        }
        tree[node] = tree[left_node] + tree[right_node];
        return;
    }
    int query_tree(vector<int>& nums, vector<int>& tree, int node, int start, int end, int L, int R) {
        if(L > end || R < start) {
            return 0;
        } 
        if(L >= start && R <= end) {
            return tree[node];
        }
        if(start == end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left = query_tree(nums, tree, left_node, start, mid, L, R);
        int sum_right = query_tree(nums, tree, right_node, mid+1, end, L, R);
        return sum_left + sum_right;
    }
```
