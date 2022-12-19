### 解题思路
先变数组排序，用双指针计算每个元素的个数，计数为偶数时可以随意加，为奇数时，只加偶数，如果是奇数就减一再相加。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let arr=s.split('').sort(),a=b=0,num=0;
    while(a<=arr.length){
        if(arr[a]!==arr[a+1]){
            if(num%2!==0){
                num+=(a-b+1)%2===0?(a-b+1):(a-b)
            }else{
                num+=(a-b+1)
            }
            b=a+1
        }
        a++
    }
    return num
};
```