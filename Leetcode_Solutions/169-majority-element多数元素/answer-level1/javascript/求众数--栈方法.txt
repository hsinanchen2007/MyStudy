/**
 * 
 * @param {*} nums 
 * top=-1 栈开始的位置
 * 
 * 为空的时候：入栈
 * 栈顶 == 当前元素的时候 =》入栈
 * 其他情况：出栈；
 * 
 * 然后返回第一个元素
 */
function majorityElement(nums) {
  let top = -1;
  const stack = new Array(nums.length).fill(0);

  for (let i = 0, len = nums.length; i < len; i++) {
    if (top == -1) {
      stack[++top] = nums[i];
    } else if (stack[top] == nums[i]) {
      stack[++top] = nums[i];
    } else {
      top--;
    }
  }
  return stack[0];
}

console.log(majorityElement([3, 2, 3]));