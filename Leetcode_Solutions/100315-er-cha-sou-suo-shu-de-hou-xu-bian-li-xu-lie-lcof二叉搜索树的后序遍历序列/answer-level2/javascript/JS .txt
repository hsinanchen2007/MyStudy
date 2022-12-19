### 代码

```javascript
var verifyPostorder = function(postorder) {
    if(postorder == null || postorder.length < 1) return true;
    return judge(postorder, 0, postorder.length - 1)
};
const judge = (postorder, left, right) => {
    if(left >= right) return true;
    let node = postorder[right];
    let index = right;
    for(let i = left; i < right - 1; i++) {
        if(postorder[i] > node){
            index = i;
            i++;
            while(i <= right - 1){
                if(postorder[i] < node){
                    return false
                }
                i++;
            }
        }
    }
    return judge(postorder, left, index - 1) && judge(postorder, index, right - 1)
}
```