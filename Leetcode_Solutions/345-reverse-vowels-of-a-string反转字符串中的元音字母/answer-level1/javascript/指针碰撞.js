+ 使用ES6Set保存元音
+ 字符串转数组
+ 检测数组每一位元素是否在Set中
+ left ，right双指针，

```
var reverseVowels = function(s) {  
    let set  = new Set(['a','e','i','o','u','A','E','I','O','U']);
    let sArr = s.split('');
    let left = 0,right = s.length -1;
    while(left < right) {
        if((set.has(s[left]) && set.has(s[right]))) {
             [sArr[left],sArr[right]] = [sArr[right],sArr[left]];
             left++;
             right--;
        }else if(set.has(s[left]) && !set.has(s[right])) {
            right --;
        }else if (!set.has(s[left]) && !set.has(s[right]) ){
            left++;
            right--;
        }else if (!set.has(s[left])  && set.has(s[right] )){
            left++;
        }
    }
    return sArr.join('');
 
}
```
