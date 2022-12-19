```
func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.count == 0 || matrix[0].count == 0 {
            return false
        }
        let lv = 0, rv = matrix.count - 1, lh = 0, rh = matrix[0].count - 1
        if matrix[rv][rh] < target {
            return false
        }
        return binarySearch(matrix, target, lv, rv, lh, rh)
    }
    
    func binarySearch(_ matrix: [[Int]], _ target: Int, _ lv: Int, _ rv: Int, _ lh: Int, _ rh: Int) -> Bool {
        if rv > lv && rh > lh {
            let mv = lv + (rv - lv) >> 1, mh = lh + (rh - lh) >> 1
            if matrix[mv][mh] == target {
                return true
            }
            if matrix[mv][mh] > target {
                return binarySearch(matrix, target, lv, mv, lh, mh) || binarySearch(matrix, target, mv + 1, rv, lh, (mh > lh) ? mh - 1 : lh) || binarySearch(matrix, target, lv, (mv > lv) ? mv - 1 : lv, mh + 1, rh)
            } else {
                let i = (lv == mv ? mv + 1 : mv)
                let j = (lh == mh ? mh + 1 : mh)
                return binarySearch(matrix, target, i, rv, j, rh) || binarySearch(matrix, target, mv + 1, rv, lh, j - 1) || binarySearch(matrix, target, lv, i - 1, mh + 1, rh)
            }
        } else if (rv == lv && rh > lh) {
            var l = lh , r = rh
            while l <= r {
                let m = l + (r - l) >> 1
                if (matrix[lv][m] > target) {
                    r = m - 1
                } else if (matrix[lv][m] < target) {
                    l = m + 1
                } else {
                    return true
                }
            }
            return false
        } else if (rh == lh && rv > lv) {
            var l = lv , r = rv
            while l <= r {
                let m = l + (r - l) >> 1
                if (matrix[m][lh] > target) {
                    r = m - 1
                } else if (matrix[m][lh] < target) {
                    l = m + 1
                } else {
                    return true
                }
            }
            return false
        } else if (rv == lv && rh == lh) {
            if (matrix[lv][lh] == target) {
                return true
            } else {
                return false
            }
        } else {
            return false
        }
    }
```
