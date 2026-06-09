题目本身是很直观的 我们只需要把内容提取出来 顺序压入stack
遇到“ .”跳过 
遇到“..” 返回目录上一级 也就是弹出

问题在于中间有很多的”//////“ 怎么把”/“中的内容提取出来呢？ 
看了一些解答 各路神仙各路方法
在这里我给出一种string流的方法 即把/换成” “ 把替换完以后的string绑定到一个istringstream中 
用类似cin的方法提取内容～ ：
while（cin>>string）
详细请参考代码，如果有问题请留言 看到必回复
 ```
string simplifyPath(string path) {
    std::vector<string> stack;      //声明一个stack
    std::string res;                //结果
    for(auto & x : path)            //替换为空格
        if(x=='/') x=' ';
    istringstream out(path);        //声明并且绑定一个输入流
    string buf;                     //输入流读入的临时缓存  
    while(out>>buf)
        if(buf==".."&&!stack.empty()) stack.pop_back();
        else if(buf!=".."&&buf!=".") stack.push_back(buf);
    for(const auto &x: stack)       //把简化后的路径依次按照 “/” + “内容” 的形式拼接
        res=res+"/"+x;              //注意 简化后路径如果是空的 那么返回结果是一个根目录～
    return res;
}
```
