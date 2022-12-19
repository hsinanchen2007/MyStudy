### 解题思路
太菜了所以时间空间都挺慢，写完想了想其实可以简化很多，代码不用写这么长

以下是本菜鸡的解题思路
如果能直接在数组中找到x，那么通过左右两个指针不断比较差值大小，填进一个新数组中
否则就通过二分法最终输出left 和 right，差值为1
比较下标为left和right的值，找到最接近x的那个数，如果一样则优先left
然后重复上述双指针的操作，依次填入新数组中
最后再考虑一下指针溢出的情况就可以了

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findClosestElements = function (arr, k, x) {
    let left = 0;
    let right = arr.length - 1;
    let mid;
    let out = [];

    if (arr.indexOf(x) !== -1) {
        var i = arr.indexOf(x);
        var j = arr.indexOf(x);
        let count = 1;
        out.push(arr[i]);
        i -= 1;
        j += 1;
        while (count < k) {
            if (i < 0) {
                out.push(arr[j])
                count += 1
                j += 1
                continue
            }
            if (j > arr.length - 1) {
                out.unshift(arr[i])
                count += 1
                i -= 1
                continue
            }
            if (Math.abs(arr[i] - x) > (Math.abs(arr[j] - x))) {
                out.push(arr[j])
                count += 1
                j += 1
            }
            else {
                out.unshift(arr[i])
                count += 1
                i -= 1
            }
        }

    }
    else {
        if (x < arr[0]) {
            for (let a = 0; a < k; a++) {
                out.push(arr[a])
            }
            return out;
        }
        if (x > arr[arr.length - 1]) {
            for (let b = arr.length - k; b < arr.length; b++) {
                out.push(arr[b])
            }
            return out;
        }
        while (Math.abs(left - right) > 1) {
            mid = Math.round((left + right) / 2);
            if ((arr[mid] - x) !== 0) {
                if ((arr[mid] - x) > 0) {
                    right = mid;
                }
                else {
                    left = mid
                }
            }
            else break
        }
        let count = 1;
        if (Math.abs(arr[left] - x) > (Math.abs(arr[right] - x))) {
            mid = right;
            right = mid + 1;
        }
        else { 
            mid = left 
            left = mid - 1;
            }
        out.push(arr[mid]);
        if (k === 1) {    
            return out;
        }
        
        
        while (count < k) {
            if (left < 0) {
                out.push(arr[right])
                count += 1
                right += 1
                continue
            }
            if (right > arr.length - 1) {
                out.unshift(arr[left])
                count += 1
                left -= 1
                continue
            }
            if (Math.abs(arr[left] - x) > (Math.abs(arr[right] - x))) {
                out.push(arr[right])
                count += 1
                right += 1
            }
            else {
                out.unshift(arr[left])
                count += 1
                left -= 1
            }
        }
        
    }
    return out;
    };
```