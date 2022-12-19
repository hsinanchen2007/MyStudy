All you guys know how to solve this problem. What I want to emphasize is you need to be very careful to skip the repeats. e.g.

```javascript
// while I go forward the next valid number (<=0)
while (nums[k + 1] === n) {
   k += 1
}
```

and

```js
// eqauls to the sum.
while (nums[l] === nums[++l]) {}
while (nums[r] === nums[--r]) {}
```
