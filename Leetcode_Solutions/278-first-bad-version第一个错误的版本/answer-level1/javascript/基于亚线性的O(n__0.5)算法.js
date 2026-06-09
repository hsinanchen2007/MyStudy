```
var solution = function (isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function (n) {
        /// 核心1 保证以 n ** 0.5 的速读步进
        let k = Math.floor((2 * n) ** 0.5)
        let pos = 1
        let forward = true
        while (k > 0) {
            /// 1. 找到true
            pos = forward ? pos + k : pos - k

            let checkVal = isBadVersion(pos)
            /// 2. 修改step策略从步进为k修改到步进为1
            if (forward == true) {
                if (checkVal == false) {
                    k--
    /// 核心2 保证一定能收敛到 n
                    if(n<pos+k){
                        k = Math.floor((2 * (n-pos)) ** 0.5)
                    }
                } else {
                    k = 1
                    forward = false
                }
            } else {
                if(checkVal == false){
                    /// 找到答案,终止搜索
                    k = 0
                    pos = pos + 1
                } else{
                    if(pos < 1){
                        pos = 1
                        break
                    }
                }
            }
        }
        return pos
    };
};
```
