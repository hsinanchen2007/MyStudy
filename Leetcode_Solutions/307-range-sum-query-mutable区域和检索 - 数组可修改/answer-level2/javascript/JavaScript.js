```
/**
 * @param {number[]} nums
 */
var NumArray = function (nums) {
    if(nums.length === 0) return;
    this.nums = nums;
    this.size = this.nums.length;
    this.tree = Array(3*nums.length).fill(0);

    build_tree(this.nums, this.tree, 0, 0, this.size - 1);

    function build_tree(arr, tree, node, start, end){
        if (start == end) {
            tree[node] = arr[start];
        } else {
            let mid = Math.floor((start + end) / 2);
            let left_node = 2 * node + 1;
            let right_node = 2 * node + 2;
            build_tree(arr, tree, left_node, start, mid);
            build_tree(arr, tree, right_node, mid+1, end);
            tree[node] = tree[left_node] + tree[right_node];
        }
    }
};

/** 
 * @param {number} i 
 * @param {number} val
 * @return {void}
 */
NumArray.prototype.update = function (i, val) {

    update_tree(this.nums, this.tree, 0, 0, this.size - 1, i, val);

    function update_tree(arr, tree, node, start, end, idx, val){
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return 
        } else {
            let mid =  Math.floor((start + end) / 2);
            let left_node = 2 * node + 1;
            let right_node = 2 * node + 2;
            if (idx >= start && idx <= mid) {
                update_tree(arr, tree, left_node, start, mid, idx, val)
            } else {
                update_tree(arr, tree, right_node, mid + 1, end, idx, val)
            }
           tree[node] = tree[left_node] + tree[right_node];
        }
    }
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function (i, j) {

    return query_tree(this.nums, this.tree, 0, 0, this.size - 1, i, j);

    function query_tree(arr, tree, node, start, end, L, R){
        if (R < start || L > end) {
            return 0;
        } else if (start >= end) {
            return arr[start];
        } else if (L <= start &&  R>=end) {
            return tree[node];
        } else {
            let mid = Math.floor((start + end) / 2);
            let left_node = 2 * node + 1;
            let right_node = 2 * node + 2;
            let sum_left = query_tree(arr, tree, left_node, start, mid, L, R);
            let sum_right = query_tree(arr, tree, right_node, mid + 1, end, L, R);
            return sum_left + sum_right;
        }
    }
};
/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * obj.update(i,val)
 * var param_2 = obj.sumRange(i,j)
 */
```