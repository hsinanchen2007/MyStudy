```javascript
/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
  let sEnd = S.length - 1;
  let tEnd = T.length - 1;
  let sStart = 0;
  let tStart = 0;

  // 注意，只要有一个还没有结束，就继续下去
  // 内部有判断 0 逻辑
  while (sEnd >= 0 || tEnd >= 0) {
    while (sEnd >= 0) {
      if (S.charAt(sEnd) === '#') {
        sEnd--;
        // 通过sStart代表一个位删除
        // 为什么会移动两位(sStart + 1，sEnd - 1)
        // 因为算上 # 本身，实际上移除了两位字符
        sStart++;
      } else if (sStart > 0) {
        // 向左滑动窗口到左对其
        // 右边代表已经删完了
        sStart--;
        sEnd--;
      } else break;
    }

    while (tEnd >= 0) {
      if (T.charAt(tEnd) === '#') {
        tEnd--;
        tStart++;
      } else if (tStart > 0) {
        tStart--;
        tEnd--;
      } else break;
    }
    
    // 有一个 end 已经出界了，-1
    // 如果两个都出界了，那就结束循环了，相等
    if ((sEnd >= 0) && (tEnd >= 0)) {
      return false;
    }

    if (S.charAt(sEnd) !== T.charAt(tEnd)) {
      return false;
    }

    // 没触发跳出，说明最右边一位相等
    // 继续向左比较
    sEnd--;
    tEnd--;
  }

  return true;
};
```
