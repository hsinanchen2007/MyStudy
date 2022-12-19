### 解题思路
直接撸一个前缀树就行

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        if not nums:
            return
        self.nums = nums
        self.n = len(nums)
        self.tree = [0] * 4 * self.n
        def build_tree(arr,tree,node,start,end):
            if start == end:
                tree[node] = arr[start]
            else:
                mid = (start + end) // 2
                left_node = 2 * node + 1
                right_node = 2 * node + 2
                build_tree(arr,tree,left_node,start,mid)
                build_tree(arr,tree,right_node,mid + 1,end)
                tree[node] = tree[left_node] + tree[right_node]
        build_tree(self.nums,self.tree,0,0,self.n-1)

    def update(self, i: int, val: int) -> None:
        def update_tree(arr,tree,node,start,end,idx,val):
            if start == end:
                arr[idx] = val
                tree[node] = val
            else:
                mid = (start + end) // 2
                left_node = 2 * node + 1
                right_node = 2 * node + 2
                if idx >= start and idx <= mid:
                    update_tree(arr,tree,left_node,start,mid,idx,val)
                else:
                    update_tree(arr,tree,right_node,mid+1,end,idx,val)
                tree[node] = tree[left_node] + tree[right_node]
        return update_tree(self.nums,self.tree,0,0,self.n-1,i,val)

    def sumRange(self, i: int, j: int) -> int:
        def query_tree(arr, tree, node, start, end, L, R):
            if R < start or L > end:
                return 0
            elif L <= start and end <= R:
                return tree[node]
            elif start == end:
                return tree[node]
            else:
                mid = (start + end) // 2
                left_node = 2 * node + 1
                right_node = 2 * node + 2
                sum_left = query_tree(arr, tree, left_node, start, mid, L, R)
                sum_right = query_tree(arr, tree, right_node, mid + 1, end, L, R)
                return sum_left + sum_right
        return query_tree(self.nums,self.tree,0,0,self.n-1,i,j)

        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
```