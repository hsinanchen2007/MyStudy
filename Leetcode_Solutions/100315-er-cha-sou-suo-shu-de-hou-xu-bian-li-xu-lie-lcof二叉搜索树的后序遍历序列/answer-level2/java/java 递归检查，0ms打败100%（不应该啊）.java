```
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return test(postorder, 0, postorder.length);  // [0, postorder.length) 左闭右开
    }
    
    private boolean test(int[] postorder, int start, int end) {

        if (end - start <= 2) { // 只有两个节点以下的子序列，肯定是一个合法的序列。
            return true;
        }
        int mid = postorder[end-1];
        
        int i = start;
        while (i < end-1){          // 假设前半部分合法，找到第一个大于mid的元素的index
            if(postorder[i] > mid){
                break;
            }
            i ++;
        }
        for (int j = i; j < end; j++) { // 检查后半部分
            if (postorder[j] < mid) {
                return false;
            }
        }
        return test(postorder, start, i) && test(postorder, i, end-1);        
    }
}
```
时间复杂度：对平衡的树，是O(nlogn),对退化成链表的二叉搜索树，O(n2)。
ps:划分子序列的时候很容易出现"off-by-one"的问题（反正我经常出错），后来看了STL的某一个二分查找实现，用[left, right)表示区间以后情况大大改善，脑子也不纠结+1-1的问题了。

