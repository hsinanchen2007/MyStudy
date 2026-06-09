![TIM截图20190820172503.png](https://pic.leetcode-cn.com/f2da4f214d9d0c339034c128e0237ebb139ce1ca46667289bd1af7c173648c44-TIM%E6%88%AA%E5%9B%BE20190820172503.png)

```
var lengthOfLongestSubstring = function(s) {
    var max = 0; // 存放 没有重复字符串的最大长度
    var index = 0; //  存放当前没有重复字串的开始索引
    var length = s.length;
    var i = 1; // 当前所在的索引
    var j = index; // 大于等于 index 小于 i,
    if(length === 1) {
        return 1;
    }
    while(i < length){
        // s[i] 和 s[j] 比较找出重复的字符，如果重复 则 index 指向重复字符的下一个位置， i++ 
        if(s[i] === s[j]){
            index = j + 1;
            i++;
            j = index;
            max = max > (i - index) ? max : (i - index);
            continue;
        }
        // 如果s[i] 没有和不重复字符串每一项比较完则继续比较，否则 i++重新和不重复字符串比较
        if(j + 1 !== i) {
            j++
        }else {
            i++;
            j = index;
            max = max > (i - index) ? max : (i - index);
        }
    }
    return max;
};

```