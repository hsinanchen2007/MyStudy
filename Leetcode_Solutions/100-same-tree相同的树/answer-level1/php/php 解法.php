```
function isSameTree($p, $q) {
    if($p===null && $q===null) return true;
    if($p===null || $q===null) return false;
    if($p->val===$q->val)
        return $this->isSameTree($p->left, $q->left)
                && $this->isSameTree($p->right, $q->right);
    return false;
}
```
