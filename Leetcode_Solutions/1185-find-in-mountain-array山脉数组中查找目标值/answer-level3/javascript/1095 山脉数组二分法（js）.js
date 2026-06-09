var findInMountainArray = function (target, mountainArr) {
  const length = mountainArr.length()
  const get = mountainArr.get
  let start = 0
  let end = length
  let mid
  let top = 0
  let loopSafe = 1
  while (start <= end) {
    loopSafe ++ 
    if(loopSafe == 33) return 'eoor'
    mid = ~~((start + end) >> 1)
    if(mid == 0) mid = 1 
    let getMid = get(mid)
    let leftMid = get(mid - 1)
    let rightMid = get(mid + 1)
    if(getMid > rightMid && getMid > leftMid) {
      start = 0
      end = mid
      top = mid
      break
    }
    else if(getMid < rightMid) start = mid + 1
    else if(getMid < leftMid) end = mid - 1
  }
  while (start <= end) {
    mid = ~~((start + end) >> 1)
    let getMid = get(mid)
    if(getMid > target) end = mid - 1
    else if(getMid < target) start = mid + 1
    else return mid 
  }
  start = top
  end = length
  while (start <= end) {
    mid = ~~((start + end) >> 1)
    let getMid = get(mid)
    if(getMid < target) end = mid - 1
    else if(getMid > target) start = mid + 1
    else if(getMid === undefined) return -1
    else return mid
  }
  return -1
};
