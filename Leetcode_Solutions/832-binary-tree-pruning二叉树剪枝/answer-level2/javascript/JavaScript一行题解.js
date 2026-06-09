```
var pruneTree = r => {if (!r) return null;[r.left,r.right]=[pruneTree(r.left),pruneTree(r.right)];return (r.val === 1 || r.left || r.right) ? r : null}
```