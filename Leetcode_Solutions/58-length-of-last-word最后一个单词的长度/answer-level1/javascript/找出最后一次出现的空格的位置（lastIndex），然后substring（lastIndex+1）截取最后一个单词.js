`var lengthOfLastWord = function(s) {
    s = s.trim();
    var lastIndex = s.lastIndexOf(' ');
    var res = s.substring(lastIndex+1)
    return res.length
};`

找出最后一次出现的空格的位置（lastIndex），然后substring（lastIndex+1）截取最后一个单词，
substring（） 中参数大于1才会生效，若参数<= 0, 不对数组做任何改变并返回。