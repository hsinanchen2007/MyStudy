#### 思路
&emsp;&emsp;滑动窗口右侧并通过哈希表判断当前窗口是否包含small的全部元素。当前窗口包含所有元素时将窗口的左侧缩减，得到最小窗口。
#### 代码
```javascript []
var shortestSeq = function(big, small) {
    let left = -1, right = -1, retLeft = -1, retRight = -1, length = big.length + 1, cnt = 0;
    let cntObj = {}, smallSet = new Set(small);
    while(right < big.length && big.length - left > small.length){
        while(cnt == small.length){
            left++;
            if(smallSet.has(big[left]) && --cntObj[big[left]] == 0){
                cnt--;
                length = length > right - left + 1 ? 
                    (retLeft = left, retRight = right, right - left + 1) : length;
            }
        }
        right++;
        cntObj[big[right]] = cntObj[big[right]] + 1 || 1;
        if(smallSet.has(big[right]) && cntObj[big[right]] == 1){
            ++cnt;
        }
    }
    return retLeft == -1 && retRight == -1 ? [] : [retLeft, retRight];
};
```
