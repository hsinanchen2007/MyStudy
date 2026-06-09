```
/**
 * @param {number[]} A
 * @return {boolean}
 */
var splitArraySameAverage = function(A) {
    const N = A.length
    if(N < 2) return false
    const half = Math.floor(N / 2)
    let s = 0
    for(let x of A) s += x
    const g = gcd(s, N)
    const nAve = `-${s / g},${N / g}`
    A = A.map(v => fracAdd(`${v},1`, nAve))


    let left = new Set()
    left.add(A[0])
    let leftSum = A[0]
    for(let i = 1; i < half; i++) {
        leftSum = fracAdd(leftSum, A[i])
        const left2 = new Set()
        left2.add(A[i])
        for(let x of left) {
            left2.add(x)
            left2.add(fracAdd(x, A[i]))
        }
        left = left2
    }
    if(left.has('0,1')) return true


    let rightSum = A[half]
    let right = new Set()
    right.add(A[half])
    for(let i = half + 1; i < N; i++) {
        rightSum = fracAdd(rightSum, A[i])
        const right2 = new Set()
        right2.add(A[i])
        for(let x of right) {
            right2.add(x)
            right2.add(fracAdd(x, A[i]))
        }
        right = right2
    }
    if(right.has('0,1')) return true
    
    for(let x of left) {
        let nX = x.split(',')
        nX[0] = -parseInt(nX[0])
        nX = nX.join(',')
        if(right.has(nX) && ( (x !== leftSum) || ( nX !== rightSum) ) ) {
            return true
        }
    }
    return false
};


function fracAdd(a, b) {
    a = a.split(',').map(v => parseInt(v))
    b = b.split(',').map(v => parseInt(v))
    let x = a[0] * b[ 1] + a[1] * b[0]
    if(x === 0) return '0,1'
    let y = a[1] * b[1]
    const g = gcd(x, y)
    x /= g
    y /= g
    if(y < 0) {
        x *= -1
        y *= -1
    }
    return x + ',' + y
}

function gcd(a, b) {
    if(b === 0) return a
    return gcd(b, a % b)
}
```
