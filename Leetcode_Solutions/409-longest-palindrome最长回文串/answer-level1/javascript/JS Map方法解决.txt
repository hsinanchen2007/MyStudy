var longestPalindrome = function(s) {
  const arr = new Map()
  for (const k of s) {
    arr.set(k, arr.get(k) > 0 ? arr.get(k) + 1 : 1)
  }
  let p = 0
  let l = false
  arr.forEach((v, k) => {
    const _length = arr.get(k)
    if (_length > 0) {
      if (_length % 2 == 0) {
        p += _length
      } else if (_length > 2 && _length % 1 == 0) {
        p += _length - 1
        l = true
      } else {
        l = true
      }
    }
  })
  if (l) {
    p += 1
  }
  return p
}