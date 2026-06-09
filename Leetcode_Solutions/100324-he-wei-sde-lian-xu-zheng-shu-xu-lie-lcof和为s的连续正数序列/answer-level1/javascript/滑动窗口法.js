### 解题思路

具体看代码

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
  if (target < 3) return []
  let [start, end] = [1, 2]
  let tmp = [1, 2]
  let tmp_sum = 3
  const ans = []
  while (end < target) {
    if (tmp_sum === target) {
      ans.push([...tmp])
      tmp_sum += ++end
      tmp.push(end)
    } else if (tmp_sum < target) {
      tmp_sum += ++end
      tmp.push(end)
    } else {
      tmp_sum -= start++
      tmp.shift()
    }
  }
  return ans
};
```
### typescript 解法

```typescript
const findContinuousSequence = function(target: number): number[][] {
  if (target < 3) return []
  let [start, end] = [1, 2]
  let tmp: number[] = [1, 2]
  let tmp_sum = 3
  const ans: number[][] = []
  while (end < target) {
    if (tmp_sum === target) {
      ans.push([...tmp])
      tmp_sum += ++end
      tmp.push(end)
    } else if (tmp_sum < target) {
      tmp_sum += ++end
      tmp.push(end)
    } else {
      tmp_sum -= start++
      tmp.shift()
    }
  }
  return ans
}

```