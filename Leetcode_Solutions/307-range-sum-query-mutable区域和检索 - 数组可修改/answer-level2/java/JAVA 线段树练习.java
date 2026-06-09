这是一个标准的可以使用线段树解决的问题，用来练习手写线段树数据结构
一开始做的时候range碰到了边界错误，
因为我构建树的时候，左子树的范围是刚好到mid，所以查询和更新的时候右子树范围切记大于mid，不能等于
不然就和我一样是低级错误了
我最开始的range条件是这样的，
写出来警示自己

```
if(mid >= end){
    return range(root.left,start,end);
}else if(mid <= start){/这里应该改成mid < start
    return range(root.right,start,end);
}else if(end > mid && start < mid ){//这里应该改成start<=mid
    int left = range(root.left,start,mid);
    int right = range(root.right,mid+1,end);
    return left + right;
}

```


完整代码 15ms 96%
创建树O(log n)
更新树O(log n)
查找范围O(log n + k) k取决于范围与树区间的关系

```
class NumArray {

    SegmentTree tree;
    public NumArray(int[] nums) {
        tree = build(nums,0,nums.length-1);
    }
    
    public void update(int i, int val) {
        update(tree,i,val);
    }
    
    public int sumRange(int i, int j){
        return range(tree,i,j);
    }

    class SegmentTree{
        int start;
        int end;
        int sum;
        SegmentTree left;
        SegmentTree right;

        public SegmentTree(int start,int end,int val){
            this.start = start;
            this.end = end;
            this.sum = val;
        }
    }

    public SegmentTree build(int[]nums,int start,int end){
            if(nums.length == 0)return null;
            if(start == end) return new SegmentTree(start,end,nums[start]);
            int mid = (start + end)/2;
            SegmentTree root = new SegmentTree(start,end,0);
            root.left = build(nums,start,mid);
            root.right = build(nums,mid+1,end);
            root.sum = root.left.sum + root.right.sum; 
            return root;
    }

    public void update(SegmentTree root,int pos,int val){
        if(root.start == root.end && root.start == pos) {
            root.sum = val;
            return;
        }
        int mid = (root.start + root.end)/2;
        if(mid >= pos){
            update(root.left,pos,val);
        }else{
            update(root.right,pos,val);
        }
        root.sum = root.left.sum + root.right.sum;
    }

    public int range(SegmentTree root,int start,int end){
        if(end < start) return -1;
        if(root == null)return 0;
        if(root.start == start && root.end == end) return root.sum;
        int mid = (root.start + root.end)/2;
        if(mid >= end){
            return range(root.left,start,end);
        }else if(mid < start){
            return range(root.right,start,end);
        }else if(end > mid && start <= mid ){
            int left = range(root.left,start,mid);
            int right = range(root.right,mid+1,end);
            return left + right;
        }
        return -1;
    }
    
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```


附上我最开始写的dp解法,巨大的时间差距，用实战让我明白了，多次求解一个可变数组的范围和，dp就不太适合，虽然可能比暴力求解好一点点
如果更新数组不是那么频繁的话，但是终究每次更新以后都要进行一次O(n)时间的遍历更新

135ms  40.4%
 
```
class NumArray {

    private int[] sum;
    public NumArray(int[] nums) {
        sum = new int[nums.length];

        if(nums == null || nums.length<=0) {
            return;
        }
        sum[0] = nums[0];

        for(int i=1; i<nums.length; i++){

            sum[i] = nums[i]+sum[i-1];
            //System.out.print( sum[i]);
            //System.out.print(" ");
        }
         //System.out.println(" ");
    }
    
    public void update(int i, int val) {
        int temp = val - sum[0];
        if(i != 0){
            temp = val - sum[i]+sum[i-1];
        }
        for(int j = i; j < sum.length; j++){
            sum[j] = sum[j] + temp;
            //System.out.print( sum[j]);
            //System.out.print(" ");
        }
        //System.out.println(" ");
    }
    
    public int sumRange(int i, int j) {
        int res = 0;
        if(i>=1) return sum[j] - sum[i-1] ;
        return sum[j];     
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```

