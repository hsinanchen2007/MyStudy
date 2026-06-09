abc axbxcxd
  ||
  \/
ab axbx
  ||
  \/
a ax

```
var isSubsequence = function (s, t) {
  if (s.length < 1) {
    return true;
  }
  const last = s[s.length - 1];
  const idx = t.lastIndexOf(last);
  if (idx === -1) {
    return false;
  }
  return isSubsequence(s.slice(0, -1), t.slice(0, idx));
};
```

