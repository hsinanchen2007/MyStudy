这个方法是空间换时间的经典案例。
你可以通过使用更多空间来降低时间复杂度。
在这个方法中，我们将给定的链表转成数组并利用数组来构建二叉搜索树。数组找中间元素只需要 O(1) 的时间，所以会降低整个算法的时间复杂度开销。
**算法**
将给定链表转成数组，将数组的头和尾记成 left 和 right 。找到中间元素 (left + right) / 2，记为 mid。这需要O(1) 时间开销，也是与上面算法主要改进的地方。将中间元素作为二叉搜索树的根。
递归构造二叉搜索树的左右两棵子树，两个子数组分别是 (left, mid - 1) 和 (mid + 1, right)。
class Solution {
public:
TreeNode* sortedListToBST(ListNode* head){
    if(!head)return NULL;
    if(head->next == nullptr) return new TreeNode(head->val);
    ListNode* p = head;
    vector<int> data;
    while(p){
        data.push_back(p->val);
        p = p->next;
}
  return convertListToBST(data,0, data.size() - 1);
}
    private: TreeNode* convertListToBST(vector<int>& nums,int left, int right) {
    if (left > right) {
      return NULL;
    }
    int mid = (left + right) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    if (left == right) {
      return node;
    }
    node->left = convertListToBST(nums,left, mid - 1);
    node->right = convertListToBST(nums,mid + 1, right);
    return node;
  }    
};
复杂度分析
时间复杂度：时间复杂度降到了 O(N) ，因为需要将链表转成数组。而取中间元素的开销变成了 O(1) 所以整体的时间复杂度降低了。
空间复杂度：因为我们利用额外空间换取了时间复杂度的降低，空间复杂度变成了O(N)，相较于之前算法的​O(logN)​ 有所提升，因为创建数组的开销。


