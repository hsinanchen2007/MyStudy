/*
 * 本题在304号问题的基础上进行了更新操作，同时题目中有提示假设update和sumRange的调用次数同样
 * 这样就暗示了update的操作要比O(n)低，此时采用线段树的方法最为合适，最终耗时96 ms
 */

class NumArray {
	
	//接口定义在顶层类中，把线段树中两个小部分融合成一个部分，具体融合方法由用户定义
	private interface Merger<E>{
		E merge(E a, E b);
	}
	
	//定义一个线段树类
	private class SegmentTree<E>{
		
		private E[] tree;
		private E[] data;
		private Merger<E> merger;
			
		public SegmentTree(E[] arr, Merger<E> merger){
			//用户在定义好了线段树时就定下来了线段树是怎么融合的
			this.merger = merger;
			
			data = (E[]) new Object[arr.length];
			for (int i = 0; i < arr.length; i++) {
				data[i] = arr[i];
			}
			//创建时数组所需要的空间是要保存数组的4倍
			tree = (E[]) new Object[4 * arr.length];
			//创建一个线段树，最初始从0开始遍历所有
			buildSegmentTree(0,0,arr.length-1);
		}
		
		//在treeIndex的位置创建表示区间[l...r]的线段树
		private void buildSegmentTree(int treeIndex, int l, int r){
			//递归结束条件
			if (l == r) {
				tree[treeIndex] = data[l];
				return;
			}
			//定义下一次创建的起始位置，左右孩子都是同一个节点的孩子
			int leftTreeIndex = leftChild(treeIndex);
			int rightTreeIndex = rightChild(treeIndex);
			
			//int mid = (l + r) / 2;这样取值有时会造成负数，在本次中不会但有规范的写法，用规范格式
			int mid = l + (r -l) / 2;
			//递归创建左子树
			buildSegmentTree(leftTreeIndex, l, mid);
			buildSegmentTree(rightTreeIndex, mid + 1, r);
			
			//调用接口实现两部分融合
			tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]);
		}
		
		public int getSize(){
			return data.length;
		}
		
		public E get(int index){
			if (index < 0 || index >= data.length) {
				throw new IllegalArgumentException("Index is illegal.");
			}
			return data[index];
		}
		//返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
		private int leftChild(int index){
			return 2*index + 1; //索引值由树的性质决定
		}
		//返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
		private int rightChild(int index){
			return 2*index + 2; //索引值由树的性质决定
		}
		//返回区间[queryL, queryR]的值
		public E query(int queryL, int queryR){
			if (queryL < 0 || queryL >= data.length || queryR < 0 || queryR >= data.length) {
				 throw new IllegalArgumentException("Index is illegal.");
			}
			//一开始即为整个线段树的查找
			return query(0, 0, data.length - 1, queryL, queryR);
		}
		 //在以treeIndex为根的线段树中[l...r]的范围里，搜索区间[queryL...queryR]的值
		private E query(int treeIndex, int l, int r,int queryL, int queryR){
			//递归的终止条件
			if (l == queryL && r == queryR) {
				return tree[treeIndex];
			}
			int mid = l +(r - l) / 2; //标准操作
			
			// treeIndex的节点分为[l...mid]和[mid+1...r]两部分
			int leftTreeIndex = leftChild(treeIndex);
			int rightTreeIndex = rightChild(treeIndex);
			if (queryL >= mid + 1) {
				 return query(rightTreeIndex, mid + 1, r, queryL, queryR);
			}else if (queryR <= mid) {
				 return query(leftTreeIndex, l, mid, queryL, queryR);
			}
			//查询到的左右两部分
			E leftResult = query(leftTreeIndex, l, mid, queryL, mid);
            E rightResult = query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
			//对左右两部分进行合并
			return merger.merge(leftResult, rightResult);
		}
		
		//将index位置的值更新为e
		public void set(int index, E e){
			if (index < 0 || index >= data.length) {
				throw new IllegalArgumentException("Index is illegal");
			}
			//更新数组中的元素
			data[index] = e;
			//更新线段树中的元素
			set(0, 0, data.length-1, index, e);
		}
		//以treeIndex为根的线段树中更新index的值为e
		private void set(int treeIndex, int l, int r, int index, E e){
			//递归终止条件
			if (l == r) {
				tree[treeIndex] = e;
				return;
			}
			int mid = l + (r-l) /2;
			//treeIndex的节点分为[l...mid]和[mid+1...r]两部分
			int leftTreeIndex = leftChild(treeIndex);
			int rightTreeIndex = rightChild(treeIndex);
			if (index >= mid + 1) {
				//更新右子树
				set(rightTreeIndex, mid+1, r, index, e);
			}else {
				//更新左子树
				set(leftTreeIndex, l, mid, index, e);
			}
			//跟新的时候不仅要把叶子节点更新还要把父节点也跟新了，因为父节点中包含了叶子节点的元素.因此重新合并组合成新的父节点
			tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]); 
		}
		
		@Override
	    public String toString(){
	        StringBuilder res = new StringBuilder();
	        res.append('[');
	        for(int i = 0 ; i < tree.length ; i ++){
	            if(tree[i] != null)
	                res.append(tree[i]);
	            else
	                res.append("null");

	            if(i != tree.length - 1)
	                res.append(", ");
	        }
	        res.append(']');
	        return res.toString();
	    }
	}	

    private SegmentTree<Integer> segmentTree;

	public NumArray(int[] nums) {
        if (nums.length > 0) {
			Integer[] data = new Integer[nums.length];
			for (int i = 0; i < nums.length; i++) {
				data[i] = nums[i];			
			}			
			segmentTree = new SegmentTree<>(data, new Merger<Integer>() {
				@Override
				public Integer merge(Integer a, Integer b) {
					return a+b;
				}
			});
			//在JDK1.8中可以用lambda表达式 segmentTree = new SegmentTree<>(data, (a,b)->a+b);
		}
    }
	
	public void update(int i, int val) {
		if(segmentTree == null)
            throw new IllegalArgumentException("Error");
        segmentTree.set(i, val);
	}
	
    public int sumRange(int i, int j) {        
    	if (segmentTree == null) {
    		 throw new IllegalArgumentException("Segment Tree is null");
		}
    	return segmentTree.query(i,j);
    }
}