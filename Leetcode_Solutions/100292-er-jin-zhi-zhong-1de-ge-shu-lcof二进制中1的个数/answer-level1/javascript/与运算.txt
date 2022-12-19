### 解题思路
1. 除0之外，每个正整数的二进制至少有一个1
2. 每次&操作后，二进制数中最右边的1都被消除1个。


```
   0111(7) 
&  0110(6)
-------------    
   0110(6)
     ↓       --6-1=5    
   0110(6) 
 & 0101(5)
-------------    
   0100(4)    
      ↓       --4-1=3    
   0100(4) 
&  0011(3)
 -------------   
   0000(0)    →退出循环

引用：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/golang-zi-fu-chuan-tong-ji-yu-wei-yun-suan-liang-c/

```

3.消除3次，result结果就是3（循环次数就是1的次数）


### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let result  = 0;
    while(n != 0){
        n = n & (n-1)
        result = result + 1
    }

    return result
};
```