```
var numDecodings = function (s) {
    let segments = [];
    let span = 0;

    if (s[0] === '0') {
        return 0;
    }

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '0') {
            if (s[i - 1] === '0' || +s[i - 1] > 2) {
                return 0;
            } else if (span > 2) {
                segments.push(--span);
            }
            span = 0;
        } else if (+s[i] > 2) {
            if (span === 0) {
            } else if (+s[i - 1] === 2 && +s[i] > 6) {
            } else {
                span++;
            }

            if (span > 1) {
                segments.push(span);
            }
            span = 0;
        } else {
            span++;
        }
    }

    if (span > 1) {
        segments.push(span);
    }

    let numOfDecodeings = 1;
    for (let n of segments) {
        numOfDecodeings *= getFibN(n);
    }

    return numOfDecodeings;
};

let getFibN = function (n) {
    switch (n) {
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 8;
        case 6:
            return 13;
        case 7:
            return 21;
        case 8:
            return 34;
        default:
            // return calculateFibN(n);
            return getFibN(n - 1) + getFibN(n - 2);
    }
}

let calculateFibN = function (n) {
    let sqrt5 = Math.sqrt(5);
    let fibn = Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1);
    return Math.round(fibn / sqrt5);
}
```