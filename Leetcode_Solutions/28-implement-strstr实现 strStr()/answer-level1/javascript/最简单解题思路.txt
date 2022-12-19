方法一：
依次遍历haystack的第i~i+n个字符，与needle比较，相同返回i；
最后不存在返回-1；
去除几种特殊情况，needle长度为0，haystack长度为0，两者相等
var strStr = function(haystack, needle) {
    //方法一：
    if (needle.length==0 || haystack==needle) return 0;
    if (haystack.length==0) return -1;
    var n=needle.length;
    var res=-1;
    for(var i=0;i<haystack.length-n+1;i++){
        if(haystack.slice(i,i+n)==needle)
            return i;
    }
    //方法二： var res=haystack.indexOf(needle);
    return res;
    
};