```javascript []
var mergeTrees = function(t1, t2) {
  return t1 || t2
    ? {
        val: ((t1 && t1.val) || 0) + ((t2 && t2.val) || 0),
        right: mergeTrees(t1 && t1.right, t2 && t2.right),
        left: mergeTrees(t1 && t1.left, t2 && t2.left)
      }
    : null;
};