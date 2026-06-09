

### 代码

```javascript
function fraction(cont) {
  let up = 1, down = cont[cont.length - 1];
  for (var i = cont.length - 2; i >= 0; --i) {
    up += cont[i] * down;
    [up, down] = [down, up];
  }
  return [down, up];
}
```