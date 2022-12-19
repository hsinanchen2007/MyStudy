var lengthOfLastWord = function(s) {
    var n=s.length;
    var flag=0;
    if(s==" ") return 0;
    //1、过滤尾部空格
    for(var j=n-1;j>=0;j--)
        if(s[j]!=" ")
            break;
        else{
            n-=1;
        }
    //2、剩余部分寻找最后一个单词
    for(var i=n-1;i>=0;i--)
        if(s[i]==" ")
            break;
        flag+=1;
    if(flag==n) return n;
    var res='';
    //通过slice切片来确定单词
    res=s.slice(i+1,n);
    return res.length;
};