### 解题思路
滑动窗口的关键就是左右两个边界的移动，这个是固定长度，一直向右移动
用数组保存滑动窗口中的值，巧妙的利用都是小写字母这个特性，建立26大小的数组

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
// var checkInclusion = function(s1, s2) {
//     let l1 = s1.length, l2 = s2.length;
//     let dict1 = {} ,dict2= {}
//     for(let i =0; i< s1.length; i++){
//         dict1[s1[i]] = dict1[s1[i]] == null ? 1 : ++dict1[s1[i]]
//         dict2[s2[i]] = dict2[s2[i]] == null ? 1 : ++dict2[s2[i]]
//     }
//     // console.log(dict2)
//     let j = 0;
//     for(let i = l1   ; i <= l2; i++){
//        if(isEquel(dict1,dict2)) {
//            return true
//        }
//         dict2[s2[i]] = dict2[s2[i]] == null ? 1 :dict2[s2[i]]++
//         dict2[s2[j]] = --dict2[s2[j]] === 0 ?  (delete dict2.s2[j]) : dict2[s2[j]]--;
//         ++j
//     }
//     return false
// };

// var isEquel = function(obj1 ,obj2){
//     for(let c of Object.keys(obj1)){
//         // console.log(obj2)
//        if(obj1[c] !== obj2[c]) {
//            return false
//        }
//     }
//     return true
// }

var checkInclusion = function(s1, s2) {
    if(s1.length > s2.length){return false}
    let l1 = s1.length, l2 = s2.length;
    let arr1 = new Array(26).fill(0) ,arr2= new Array(26).fill(0)
    for(let i =0; i< s1.length; i++){
        ++arr1[s1[i].charCodeAt() - 'a'.charCodeAt()];
        ++arr2[s2[i].charCodeAt() - 'a'.charCodeAt()];
    }
     if(isEquel(arr1,arr2)) {
         return true
      }
    let j = 0;
    for(let i = l1  ; i < l2; i++){
         ++arr2[s2[i].charCodeAt() - 'a'.charCodeAt()];
         --arr2[s2[j].charCodeAt() - 'a'.charCodeAt()];
         ++j;
         if(isEquel(arr1,arr2)) {
            return true
         }
    }
    return false
};

var isEquel = function(obj1 ,obj2){
    for(let i =0 ;i <26; i++){
       if(obj1[i] !== obj2[i]) {
           return false
       }
    }
    return true
}
```