*法一：找到最大数的索引*

```js
var validMountainArray = function(A) {
    let max = A[0];
    let maxIndex = 0;
    let ALen = A.length
    if (ALen < 3) {
        return false
    } else {
        A.forEach((item, index) => {
            if (item > max) {
                max = item;
                maxIndex = index
            }
        })
        if (maxIndex === 0 || maxIndex === ALen - 1) {
            return false
        } else {
            for (let i = 0; i < maxIndex; i++) {
                if (A[i] >= A[i+1]) {
                    return false
                }
            }
            for (let i = maxIndex; i < ALen; i++) {
                if (A[i] <= A[i+1]) {
                    return false
                }
            }
            return true
        }

    }
};
```

*法二：双指针*

推荐

```js
var validMountainArray = function(A) {
    let ALen = A.length
    if (ALen < 3) {
        return false
    } else {
        let i = 0;
        let j = ALen - 1;
        while(i < ALen - 2 && A[i] < A[i+1]) {
            i++
        }
        while(j > 1 && A[j] < A[j-1]) {
            j--
        }
        return i === j
    }
};
```


