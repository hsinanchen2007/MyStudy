### 解题思路
双指针start从头到尾遍历，end从尾到头
每当start找到奇数，end找到偶数二者交换
任意时刻start<end循环结束，返回数组A

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    let start = 0, end = A.length-1
    while(start < end){
        // while(start<A.length-1 && A[start]%2 ==0) start++  
        // while(end>=0 && A[end]%2 !==0) end--         // 刚开始没看别人的答案，这样写执行用时会高出不少

        while(start<end && A[start]%2 ==0) start++
        while(start<end && A[end]%2 !==0) end--
        if(start < end){
            let tmp=A[start]
            A[start]=A[end]
            A[end]=tmp
            start++
            end--
        }  
    }
    return A
};
```