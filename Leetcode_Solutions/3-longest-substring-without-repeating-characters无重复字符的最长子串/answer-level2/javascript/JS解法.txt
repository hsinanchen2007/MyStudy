### 解题思路
两种解法，都是双指针的思路；

第一种是操作字符串，定义一个字符串，判断一个就加一个或向前截取有重复字符的部分，
每增长一次比较一次长度，每次保留大的数字。

第二种是直接查找双指针下标，比较后一个字符在前面的部分是否有重复；
有重复，就把慢指针放到重复位置的下一个字符上；没重复就保留较长的长度；
需要注意的是空字符串、一个和两个空格字符串会比较特殊，需要判断。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // let a=0,l="";
    // for(let i=0;i<s.length;i++){
    //     if(!l.includes(s[i])){
    //         l+=s[i]
    //         a=Math.max(a,l.length)
    //     }else{  
    //         l=l.slice(l.indexOf(s[i])+1)+s[i]
    //     }
    // }
    // return a

    let a=0,b=1;
    if(s.length<2)return b=s.length;
    for(let i=1;i<s.length;i++){
        if(!s.slice(a,i).includes(s[i])){
            b=Math.max(b,i-a+1)
        }else{
            a+=s.slice(a,i).indexOf(s[i])+1
        }
    }
    return b
};
```