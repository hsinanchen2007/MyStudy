var isSubtree = function(s, t) {
    var dig = arguments[2];
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s.val === t.val) {
        if (isSubtree(s.left, t.left, true) && isSubtree(s.right, t.right, true)) {
            return true;
        }else {
            return isSubtree(s.left, t) || isSubtree(s.right, t);
        }
    } else if (dig) {
        return false;
    } else {
        return isSubtree(s.left, t) || isSubtree(s.right, t);
    }
};