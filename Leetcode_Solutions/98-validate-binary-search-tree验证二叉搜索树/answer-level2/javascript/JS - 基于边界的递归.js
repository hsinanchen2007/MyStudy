```
var isValidBST = function(root, max = Infinity, min = -Infinity) {
    let rtn = true;
    if (root) {
        const {val, left, right} = root;
        rtn = val < max && val > min;
        if (rtn && left) {
            rtn = isValidBST(left, val, min);
        }
        if (rtn && right) {
            rtn = isValidBST(right, max, val);
        }
    }
    return rtn;
};
```
