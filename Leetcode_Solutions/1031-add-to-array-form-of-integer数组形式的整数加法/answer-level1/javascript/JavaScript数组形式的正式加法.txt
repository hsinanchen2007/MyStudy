![image.png](https://pic.leetcode-cn.com/000a042384fe719944cb1b364a72fb8ce2e062cb5b8842f2d5e532ad310db6b3-image.png)

``` js
var addToArrayForm = function(A, K) {
    var i = A.length - 1;
    var carry = 0;
    var ans = new Array(A.length);
        
    while(i>=0 || K>0) {
        var sum = (A[i] || 0 )    + K % 10 + carry;
        carry = ~~(sum/10);
        
        if (i < 0) {
            ans.unshift(sum % 10);
        } else {
            ans[i] = sum % 10;
        }
                
        K = ~~(K/10);
        i--;        
    }
    
    if (carry > 0) ans.unshift(carry);
    return ans;
};
```
