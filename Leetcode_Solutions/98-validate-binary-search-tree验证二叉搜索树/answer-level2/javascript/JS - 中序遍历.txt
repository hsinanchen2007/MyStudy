```
var isValidBST = function(root) {
    let rtn = true;
    if (root) {
        let curr = -Infinity;
        const isValid = (val) => {
            if (rtn) {
                rtn = val > curr;
                curr = val;
            }
        }
        const visitTreeNode = (node) => {
            if (rtn && node) {
                const {val, left, right} = node;
                visitTreeNode(left);
                isValid(val);
                visitTreeNode(right);
            }
        }
        visitTreeNode(root);
    }
    return rtn;
};
```
