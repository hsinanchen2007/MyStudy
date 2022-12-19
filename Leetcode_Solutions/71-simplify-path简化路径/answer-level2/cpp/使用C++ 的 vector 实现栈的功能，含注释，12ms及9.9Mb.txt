```
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vct;     // 使用栈记录最终的路径
        string temp = "", ret = ""; // temp保存压入vct中的string，ret保存函数返回值
        int count = 0;  // 计数'/'
        
        for(int i = 0; i < path.length(); ){
            while(path[i] == '/' and i < path.length()){
                ++i, ++count;
            }
            if(count > 0){
                temp += "/";
                count = 0;
            }   //将连续的'/'记录为一个'/'写入temp
                
            while(path[i] == '.' and i < path.length()){
                temp += path[i];
                ++i;
            }   //将连续的'.'写入temp
            
            while(path[i] != '/' and i < path.length()){
                temp += path[i];
                ++i;
            }   //将文件名写入temp，至此确定一次temp
            
            //按vct是否为空，分为两种情况，针对"/.."和"/."开头的情况
            //temp四种模式："/.", "/..", "/", "/*****"
            if(vct.size() > 0){
                if(temp == "/..")
                    vct.pop_back();
                else if(temp == "/." or temp == "/"){
                    temp = "";
                    continue;
                }
                else 
                    vct.push_back(temp);
            }
            else {
                if (temp == "/" or temp == "/." or temp == "/.."){
                    temp = "";
                    continue;
                }
                else
                    vct.push_back(temp);
            }                
            temp = "";  //清空本次的temp
        }
        
        if(vct.size() == 0)
            vct.push_back("/");
        for(auto s : vct)
            ret += s;
        return ret;
    }
};
```