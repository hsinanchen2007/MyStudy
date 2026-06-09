## 算法
- 我们在数组中使用两个指针，一个放在开始，一个置于末尾。
- 在每一步中，我们将指向较短线段的指针向较长的线段那端移动；
- 同时，我们记录下所有步骤里最大的面积: *maxSquare*。
- 时间复杂度 O(N)，双指针遍历一次底边宽度 N 。空间复杂度 O(1)，指针使用常数额外空间。

## 证明
我们将所有情况用一棵递归树列出，如下：

![在这里插入图片描述](https://pic.leetcode-cn.com/d717491eb1121ca69da653a4fd286556514259ff4957e5842a02ceb9849f8f19.png)

以 *m , n* 表示前后指针，*H[m]* 表示位置 *m* 处的高度，*n* 是输入的数据长度。*S(m,n) = min(H[m],H[n]) *  (n-m)* 是 *(m,n)* 对的面积。*h[m,n]* 表示当前位置的树高, *h = n-m* 。

红色圈出部分为双指针法可能的一条路径（路径并不唯一）。

> 这意味着：在双指针路径的红圈外任意一个情况的 *S(m,n)* 均小于 *maxSquare*。

下面我们来证明是否一定如此。

#### 反证法
假设，存在一个双指针路径之外的 *S(m,n)* > *maxSquare*。则：
$$
S\left(m,n\right)\;=\;\left\{\begin{array}{l}H(m)\ast h\;\;H(m)<H(n)\\H(n)\ast h\;\;H(n)<H(m)\end{array}\right.
$$
我们观察递归树可以发现，当 *(m,n)* 在双指针路径的左边时，在路径上必定存在 *(m,X)*  （可能会有多个），且 *(m,X)* 在 *(m,n)* 的上方；同理，当 *(m,n)* 在双指针路径的右边时，在路径上也必定存在 *(X,n)* ，且 *(X,n)* 在 *(m,n)* 的上方。

(1)  对于 *(m,n)* 在路径左边的情况

根据观察，由于路径上存在 *(m,X)* ，且 *(m,X)* 在 *(m,n)* 的上方，即：*h[m,X]>h[m,n]*。

**❗** 由于若对任意一个 *(m,X)* ，*H(X)<H(m)* 恒成立的话，*(m,n)* 将不会在路径的左边，而是在路径中。故在路径上必定存在一个且仅且一个 *(m,α)* 满足： *H(α)>H(m)* ，*S(m,α) = H(m) * h[m,α]*。

由于*h[m,α]>h[m,n]* ，而若 *H(m)<H(n), S(m,n) = H(m) * h[m,n] < S(m,α) = H(m) * h[m,α]*，这与我们的假设 *S(m,n)* > *maxSquare* 不符合。

所以我们可以得到：*H(α)>H(m)>H(n)* ，*S(m,n) = H(n) * h(m,n)* 。而 *h[m,α]>h[m,n]*，即：*S(m,α)>S(m,n)*，仍然与我们的假设 *S(m,n)* > *maxSquare* 不符合。故假设不成立！

(2) 对于 *(m,n)* 在路径右边的情况

同理就略了...

由此，我们可以确定**双指针方法是正确的**。代码如下：

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let i = 0, j = height.length-1;
    let square, max = 0;
    while(j-i >= 1){
        if(height[i]>height[j]){
            square = height[j] * (j-i);
            j--;
        }else{
            square = height[i] * (j-i);
            i++;
        }
        max = Math.max(square,max);
    }
    return max;
};
```