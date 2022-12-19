```
class Solution {
    public int kthLargest(TreeNode root, int k) {
        int[] result = new int[2];
        Arrays.fill(result, 0);
        post2orderkthLargest(root, result, k);
        return result[1];
    }
    public void post2orderkthLargest(TreeNode r, int[] result, int k){
        if(r!=null && result[0] != k){
            post2orderkthLargest(r.right, result, k);
            result[0] ++;
            if(result[0] == k)
                result[1] = r.val;
            post2orderkthLargest(r.left, result, k);
        }
    }
}
```
用result数组控制递归和存储结果。

因为题目限制k为合理值，不考虑k>size的情况。