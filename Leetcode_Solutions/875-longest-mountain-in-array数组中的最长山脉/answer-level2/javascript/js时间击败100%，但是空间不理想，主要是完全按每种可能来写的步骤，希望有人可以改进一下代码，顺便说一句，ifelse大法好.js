var longestMountain = function (A) {
    if (A.length < 3) return 0;
    let max = 0;
    let len = 1;
    let top = null;

    for (let i = 1; i < A.length; i++) {
        if (A[i - 1] < A[i]) {
            if (top == null) {
                len++;
            } else {
                max = max > len ? max : len;
                top = null;
                len = 2;
            }
        } else if (A[i - 1] > A[i]) {
            if (top == null) {
                if (len > 1) {
                    top = A[i - 1];
                    len++;
                } else {
                    len = 1;
                }
            } else {
                len++;
            }
        } else {
            if (top == null) {
                len = 1;
            } else {
                max = max > len ? max : len;
                top = null;
                len = 1;
            }
        }
    }
      if (top != null) {
        return max > len ? max : len;
    }
    if (top == null) {
        return max;
    }

    if (max == 0) {
        return 0;
    }
};