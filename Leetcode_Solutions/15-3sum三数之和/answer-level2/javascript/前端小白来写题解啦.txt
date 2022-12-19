这题看画解算法大佬的题解之后还是会有一些不明白的地方，其实主要就是如何直接排除重复。

其实就是在更新第一个数、第二个数和第三个数的位置的时候检测一下就好了，记得用while循环。
其中第一个数和第二个数都是检测与前一位的关系是否相等，因为他们都是从左往右移动的，
而第三个数是检测与后一位的关系是否相等，因为他是从右往左移动的。
具体代码如下，也标出了更新的注意细节：

```js
var threeSum = function(array) {
    let length = array.length;
    if(length < 3) return [];
    let ret = [];
    let src = array.sort((a,b)=> a-b)
    for(let i = 0; i<length - 2; i++){
        if(src[i] > 0) break;
        // 第一个数更新处
        while(src[i] === src[i-1]) i++;
        
        let l = i+1, r = length-1;
        while(l<r) {
            let mid = src[i] + src[l] + src[r];
            if(mid === 0) {
                ret.push([src[i], src[l] , src[r]]);
                l++;
                // 第二个数更新处
                while(src[l] === src[l-1]) l++;
                // 第三个数更新处
                r--; 
                while(src[r] === src[r+1]) r--;

            } else if(mid > 0) {
                // 第三个数更新处
                r--;
                while(src[r] === src[r+1]) r--;
            } else {
                l++;
                // 第二个数更新处
                while(src[l] === src[l-1]) l++;
            }
        }

    }

    return ret;
}
```
