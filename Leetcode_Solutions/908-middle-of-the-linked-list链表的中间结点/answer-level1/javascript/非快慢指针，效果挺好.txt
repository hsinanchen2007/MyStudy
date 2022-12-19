思路：1.先让右指针探底，然后双向逼近
      2.为了符合题目要求，偶数返回右侧的，所以左边指针先动。
    ，，很像快排的指针移动。结果还可以优化。ifelse拖了一点效率

![image.png](https://pic.leetcode-cn.com/f79c2d88e9010795d671e520e056e2a6b1190709b9da84a20c2ba212f940a0de-image.png)
附上代码
var middleNode = function (head) {
    if (head === null) return null;;
    let left = 0;
    let right = 0;
    let p = head;
    while (p.next !== null) {
        right++;
        p = p.next;
    }
    while (p !== head && right !== left) {
        left++;
        head = head.next;
        if (left === right) {//可以优化，毕竟right一直会--
            return head
        } else {
            right--;
        }
    }
    return head
};
