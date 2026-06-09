```
var buddyStrings = function (A, B) {
    if (A.length !== B.length || !A.trim() || !B.trim()) return false;
    let temp = 0, arr = [], tempObj = {}, isReapt = false;
    for (let i = 0; i < A.length; i++) {
        if (A[i] != B[i]) {
            temp++;
            arr.push(i)
            if (temp > 2) return false;
        } else if (!isReapt && !tempObj[A[i]]) {
            tempObj[A[i]] = true;
            continue;
        } else {
            isReapt = true;
        }
    }
    if (temp === 2 && (A[arr[0]] === B[arr[1]] && B[arr[0]] === A[arr[1]]) || (A === B && isReapt)) {
        return true;
    }
    return false;
};
```