```
var sortedListToBST = function(head) {
    let child = head;
    const arr = [];
    while(child) {
        arr.push(child.val);
        child = child.next;
    }
    function buildTree(arr, left, right) {
        if(left > right) return null;
        if(left === right) return new TreeNode(arr[left]);
        else if (right - left === 1) {
            let r = new TreeNode(arr[right]);
            r.left = new TreeNode(arr[left]);
            return r;
        }
        let mid = (left + right + 1) >> 1;
        let root = new TreeNode(arr[mid])
        root.left = buildTree(arr, left, mid - 1);
        root.right = buildTree(arr, mid + 1, right);
        return root;
    }
    return buildTree(arr, 0, arr.length - 1);
};
```
