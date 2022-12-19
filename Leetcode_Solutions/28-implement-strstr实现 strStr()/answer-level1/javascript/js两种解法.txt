一般解法
![image.png](https://pic.leetcode-cn.com/c38cdc5f469eaa0dd51b4386af84cc86dd3e04b73c96d7237095c1b3018afb5f-image.png)

```
var strStr = function(haystack, needle) {
    if(!needle) return 0;  //字符串为空时返回0
    if(needle.length>haystack.length) return -1;//目标字符串长度大于查找字符串的长度时返回-1
    let len=needle.length;
    let result=-1;
    for(let i=0;i<haystack.length-len+1;i++){//注意比较次数是查找字符串长度-目标字符串长度+1
        let str=haystack.slice(i,i+len);
        if(str===needle){
            result= i;
            break;
        }
    }
    return result;
};
```
Sunday解法
![image.png](https://pic.leetcode-cn.com/fc51e08ab48ac287527b48f6b5d622ec98b1dd30edae3a307373b477ff1d1505-image.png)

```
var strStr = function(haystack, needle) {
    if(!needle) return 0;
    if(needle.length>haystack.length) return -1;
    let len=needle.length;
    let obj={};
    //为了定位目标字符串中每个字符的位置，将每个字符存在对象中，值为该字符最后一次出现的索引
    for(let i=0;i<len;i++){
        obj[needle[i]]=i;
    }
    let result=-1;
    let i=0;
    while(i<haystack.length-len+1){
        let str=haystack.slice(i,i+len);
        if(str===needle){
            result= i;
            break;
        //若对比字符串的后一位字符haystack[i+len]存在于目标字符串，则它在目标字符串中的索引为obj[haystack[i+len]]
        //则指针后移(目标字符串的长度—后一位字符在目标字符串中的索引)位
        }else if(haystack[i+len] in obj){
            i=i+(len-obj[haystack[i+len]])
        }else{  //若后一位字符在目标字符串没有找到，指针直接后移目标字符串的长度位
            i=i+len;
        }

    }
    return result;
};
```

看了前面大神的Sunday思路写出来的，对比普通解法，时间只快了一点点，反倒是内存消耗增加了很多，是不是俺哪里写的不对 