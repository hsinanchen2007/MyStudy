### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/729f878eaad86e2c64220da7c69f53fd2675541707a612322c56d89d154d158c-image.png)

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
       let len=digits.length-1;
            if(digits[len]+1>9){
              while(digits[len]+1>9){
                  digits[len]=0;
                  if(len==0){
                      digits.unshift(1);
                      return digits;
                  }else{
                       len--;
                  }
              }
               if(digits[len]+1<=9){
                   digits[len]+=1;
               }
            }else{
                digits[len]+=1;
            }
        
         return digits
};
```