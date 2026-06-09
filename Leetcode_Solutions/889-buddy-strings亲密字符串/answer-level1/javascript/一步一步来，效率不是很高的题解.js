第一次写题解哈，有错误请大家及时纠正，谢谢。

![QQ图片20191204165225.png](https://pic.leetcode-cn.com/d4643ddc67f885063ffd81256f7ec5e7e549f0e1a6123b9e4d5fe3e3d3458e17-QQ%E5%9B%BE%E7%89%8720191204165225.png)

```
var buddyStrings = function(A, B) {
    if(A.length==B.length){
        let count=0;
        let Adiff=[];
        let Bdiff=[];
        for(let i=0;i<A.length;i++){
            if(A[i]!=B[i]){
                count++;
                Adiff.push(A[i]);
                Bdiff.push(B[i]);
            }
        }
        if(A==B){
            if(/(.).*?\1/.test(A)){
                return true;
            }else{
                return false;
            }
        }
        if(count==2&&Adiff[0]==Bdiff[1]&&Adiff[1]==Bdiff[0]){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
};
```
大概思路如下，有几种情况
1.A的长度==B的长度 
(1)A里面超过2个字母和B里面的不一样 = > false
(2)A和B完全一样，如果A里面有大于等于2个字母重复 = > true,反之 false
(3)A和B刚好有2个字母不同，如果A[0]=B[1]&&A[1]=B[0] = > true,反之 false
2.A的长度!=B的长度 = > false
