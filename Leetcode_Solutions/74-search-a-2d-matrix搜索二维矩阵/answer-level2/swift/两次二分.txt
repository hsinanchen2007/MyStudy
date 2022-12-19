class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.count == 0 {
            return false
        }
        var left = 0, right = matrix.count - 1
        var ret = false
        while left <= right {
            let mid = left + ((right - left) >> 1)
            if (target == (matrix[mid].first ?? 0)) || (target == (matrix[mid].last ?? 0)) {
                ret = true
                break
            }
            if (target > (matrix[mid].first ?? 0)) && (target < (matrix[mid].last ?? 0)) {
                var m_left = 0, m_right = matrix[mid].count - 1
                while m_left <= m_right {
                    let m_mid = m_left + ((m_right - m_left) >> 1)
                    if target == matrix[mid][m_mid] {
                        ret = true
                        break
                    }
                    if target > matrix[mid][m_mid] {
                        m_left = m_mid + 1
                    }else {
                        m_right = m_mid - 1
                    }
                }
                break
            }
            if target < (matrix[mid].first ?? 0)  {
                right = mid - 1
            }
            if target > (matrix[mid].last ?? 0)  {
                left = mid + 1
            }
        }
        return ret
    }
}