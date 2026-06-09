### 解题思路
见注释
### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if(S.length <= 0) return "";
    let ans = "";
    let temp = S[0];  // 记录第一个字符
    let count = 0;    // 记录字符的数量，初始化为0
    for(let i=0;i<S.length;i++) {
        if(S[i] === temp) {  // 统计字符的数量
            count+=1;
        } else {
            // 以abbccd为例，此时S[i]为b,不等于temp=a,所以将temp=a及其数量count拼接到ans中
            // 因为字符变了，所以我们要更新temp为新字符b，同时将其数量记为1
            ans+=S[i-1] + count;
            temp = S[i];
            count = 1;
        }
    }
    // 遍历到最后一个字符时，数量统计完毕，然后跳出了循环，导致最后一个字符的统计没有拼接到ans中
    ans+=S[S.length-1]+count;
    return ans.length < S.length ? ans:S;
};
```