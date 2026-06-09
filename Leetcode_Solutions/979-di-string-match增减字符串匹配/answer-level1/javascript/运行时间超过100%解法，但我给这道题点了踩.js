![截图](https://pic.leetcode-cn.com/19079118307236bd7d4cc18ac41e5bae1c25cdde0f3ac9260d7d365baf4e2a14-TIM%E6%88%AA%E5%9B%BE20191108042649.png)
通过观察，只要把“D”对应的元素从大到小排列，“I”对应的元素从小到大排列，即可满足题目条件。
![截图](https://pic.leetcode-cn.com/73752e5b386545392c13792e79586bce5b58f48b709429dc47eecce380cd0a4b-TIM%E6%88%AA%E5%9B%BE20191108044046.png)

然而事实上，数学的证明是无法完成的，因为显然答案并不是唯一的；
对于“IDID”这个字符串，除了[0, 4, 1, 3, 2]满足条件，至少还有[1, 3, 2, 4, 0]也满足题目条件；
也就是说，这道题的“标准答案”只是其中一个特解而不是通解，而其他特解则不算“正确”；
难道其他特解是错误的吗？反复阅读题目之后，我认为不是这样的，所以我踩了这道题。
![题目](https://pic.leetcode-cn.com/a1047ec5534cbb29a2fe9347a94e967360e8ed26e774c0b509690ab60cd7d08f-TIM%E6%88%AA%E5%9B%BE20191108044736.png)

[@LeetCode](/u/leetCode/) 
不知道这样有用没，欢迎纠错打脸。

```js
/**
 * @param {string} S
 * @return {number[]}
 */
var diStringMatch = function(S) {
    var arr = new Array(S.length);
    var increase = 0, decrease = S.length;
    for(let i = 0; i < S.length; i++) {
        if(S[i] == "I") {
            arr[i] = increase;
            increase++;
        } else {
            arr[i] = decrease;
            decrease--;
        }
    }
    arr[S.length] = S[S.length - 1] == "I" ? arr[S.length - 1] + 1 : arr[S.length - 1] - 1;
    return arr;
};
```
