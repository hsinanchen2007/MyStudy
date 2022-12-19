### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} A
 * @return {string[]}
 */
var commonChars = function(A) {
//定义一个26为大小的数组，初始化为0
    var arr=new Array(26).fill(0);
    var a=[]
    var k=0;
//对A中第一个字符串，统计每个字符出现的次数，使用数组下标代表这个字符
    for(var i=0;i<A[0].length;i++){
        var str=A[0].charCodeAt(i);
        arr[str-'a'.charCodeAt()]++;
    }
//从第二个字符串开始，也使用一个数组统计该字符串中每个字符的个数，和第一个字符串做比较，取其中的较小值
    for(i=1;i<A.length;i++){
        var temp=new Array(26).fill(0);
        for(var j=0;j<A[i].length;j++){
            temp[A[i].charCodeAt(j)-'a'.charCodeAt()]++;
        }
        for(j=0;j<26;j++){
            arr[j]=Math.min(arr[j],temp[j]);
        }
    }
//将数组中不为零的值转化为字符存到数组中
    for(i=0;i<arr.length;i++){
        if(arr[i]>0){
            for(j=0;j<arr[i];j++){
                a[k]=String.fromCharCode(i+'a'.charCodeAt());
                k++;
            }
        }
    }
    return a;
};
```