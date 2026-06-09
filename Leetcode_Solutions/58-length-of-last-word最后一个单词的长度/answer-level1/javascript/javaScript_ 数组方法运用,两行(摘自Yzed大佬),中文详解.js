var lengthOfLastWord = function(s) {
    var arr = s.trim().split(' ');      //trim删除头尾空格,用split方法分割为多个数组
    return arr[arr.length - 1].length;  //返回数组中,索引为1的长度
};