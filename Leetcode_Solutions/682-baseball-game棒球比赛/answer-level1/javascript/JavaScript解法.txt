用数组模拟栈的结题思路。尽量控制数组的pop操作，**可能**会提高性能。
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
  const calculated = []
  ops.forEach(current => {
    if (!Number.isNaN(current * 1)) {
      calculated.push(current * 1)
    }
    if (current === 'C') {
      calculated.length = calculated.length - 1
    }

    if (current === 'D') {
      calculated.push((calculated[calculated.length - 1] || 0) * 2)
    }

    if (current === '+') {
      calculated.push(
        (calculated[calculated.length - 2] || 0) +
          (calculated[calculated.length - 1] || 0),
      )
    }
  })
  return calculated.reduce((sum, now) => sum + now, 0)
};