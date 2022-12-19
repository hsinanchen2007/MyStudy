解题代码和思路如下
var lengthOfLastWord = function(s) {
	s=s.trim()
   var ss = s.split(" ") //通过split方法把字符串转成数组
   console.log(ss)
    if(ss.length==0){
        return 0;
    }else{
        //ss[ss.length-1]是获取数组中最后一个索引的值
        return ss[ss.length-1].length
    }
};