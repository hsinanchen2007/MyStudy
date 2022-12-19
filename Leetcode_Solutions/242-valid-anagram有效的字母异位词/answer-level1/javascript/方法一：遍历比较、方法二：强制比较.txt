### 解题思路
方法一：两个字符串都转换成数组，然后嵌套遍历连个数组，比较相同的元素删去，最后看两个数组饿长度是否相等且为0.最后运行时，**特别长的用例会超出时间限制**

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
 var isAnagram = function(s, t) {
     let firstArr=s.split('');
     let secondArr=t.split('');
     if(firstArr.length!==secondArr.length){
         return false;
     }
     let len=firstArr.length;
     for(let i=len-1;i>=0;i--){
         for(let j=len-1;j>=0;j--)
         if(firstArr[i]===secondArr[j]){
             firstArr.splice(i,1);
             secondArr.splice(j,1);
         }
     }
     return firstArr.length===secondArr.length&& secondArr.length===0
 };
```
![image.png](https://pic.leetcode-cn.com/6d0e45ac0ac9b98c81b141d32547debaa901397b815fef01a23a3cf7176ce130-image.png)


### 解题思路
方法一：对两个字符传转成数组再按字符排序再转成字符串，强制比较

### 代码

```javascript
var isAnagram = function(s, t) {
    return s.split('').sort().join('')===t.split('').sort().join('')
};
```
![image.png](https://pic.leetcode-cn.com/cf04ef8240003d44246f3615d960929e0011a35a4154238607109e7f9c43a0d1-image.png)
