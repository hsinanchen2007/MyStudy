### 解题思路
    思路摘自其他大佬的解法   以中心方式  向左右两边延伸判断值是否相同 返回以当前为回文中心时最长的回文串
    

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(!s || s.length < 2){
        return s
    }

    let start = 0;
    let end = 0;
    let lent = s.length;
    
    //输入中心点  找出回文串的最长长度   此函数为该方法主要函数
    let getCenterLentF = (left,right) => {
        while(left >= 0 && right < lent && s[left] == s[right]){
            left--;
            right++;

        }
        return (right - 1) - (left + 1) + 1
    }

    for(let i = 0; i < lent ; i++){
        //type1  类型1 最长回文串以（自己）为中心  aba
        let lent1 = getCenterLentF(i,i);
        //type2  类型2 最长回文串以（自己  和 下一个 -> 即两者相同）为中心   baab
        let lent2 = getCenterLentF(i,i + 1);

        let maxLent = Math.max(lent1,lent2);
        let  lastMax = end - start;
        if(maxLent > lastMax){//如果以当前下表为回文串中心得到的最长长度 比 上一个长度还长
            //则回文串的起始下表为当前i值的左边 再减回文串长度的一半 
            // 若回文串长度为单数 刚好以i中心 长度则为  左：(maxLent - 1) / 2   右：(maxLent - 1) / 2 
            // 若回文串长度为偶数 以 i 和 i + 1 为中心  左：(maxLent - 2) / 2   右：maxLent / 2；
            if(maxLent % 2 != 0 ){
                start = i - (maxLent - 1) / 2;
                end = i + (maxLent - 1) / 2;
            }else{
                start = i - (maxLent - 2) / 2;
                end = i + maxLent / 2;
            }
            // => start = i - ((maxLent - 1) >> 1);
            // => end = i + (maxLent >> 1);
        }
    }

    return s.substring(start,end + 1 )

};


```