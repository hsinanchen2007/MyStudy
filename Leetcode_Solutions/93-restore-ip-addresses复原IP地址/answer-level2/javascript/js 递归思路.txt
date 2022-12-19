```
var restoreIpAddresses = function(str) {
//  判断最大边界
    if(str.length > 12) return []
  // 保存所有符合条件的IP地址
  let r = []
  // 分四步递归处理ip分段
  let search = (cur, sub) => {
    // 边界条件
    if (cur.length === 4 && cur.join('') === str) {
        //  过滤 001 010等情况 
        if(cur[3].length > 1 && cur[3][0] == 0){
            return false
        }
      r.push(cur.join('.'))
    } else {
      // 正常的处理过程
      for (let i = 0, len = Math.min(3, sub.length), tmp; i < len; i++) {
        tmp = sub.substr(0, i + 1)
        //  过滤 001 010等情况           
        if (tmp.length > 1 && tmp[0] == 0) {
            return false
        }
        if (tmp < 256) {
          search(cur.concat([tmp]), sub.substr(i + 1))
        }
      }
    }
  }
  search([], str)
  return r
}

```

