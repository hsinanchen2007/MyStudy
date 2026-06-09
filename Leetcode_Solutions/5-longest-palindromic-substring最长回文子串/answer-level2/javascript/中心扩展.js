### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let max=0;
    let pair1={left:0,right:0};
    let pair2={left:0,right:0};
    let pair={left:0,right:0}
    var sub1="";var sub2="";
    var len=0;
    var result="";
    if(s.length==1) return s;
    if(s.length==2) return s[0]==s[1] ? s : s[0];

    var slicePair = function(l,r,s){
        while(l>=0 && r <s.length && s[l]==s[r]){
            l--;
            r++;
        }
        return {left:l+1,right:r+1-1};
        //如果传进来的左右不回文，要还原角标，否则传进来的左右已经左右移动了
        //所以 l+1 r+1-1(slice本身需要的r位置为r+1,再减去1)
    }
    
    for(let i=0; i<s.length; i++){
        let re="";
        console.log("当前是"+i+s[i]+"字符为中心");
        if(s[i]==s[i+1]){
            pair1=slicePair(i-1,i+2,s);
            sub1=s.slice(pair1.left,pair1.right);
        }
        console.log(sub1);
        pair2=slicePair(i-1,i+1,s);
        sub2=s.slice(pair2.left,pair2.right);
        console.log(sub2);
        sub1.length>sub2.length? pair=pair1: pair=pair2;
        console.log("左右角标是:"+pair.left+" "+pair.right);
        re = s.slice(pair.left,pair.right);
        result = re.length>result.length ? re: result; 
    }

    return result;
};
```