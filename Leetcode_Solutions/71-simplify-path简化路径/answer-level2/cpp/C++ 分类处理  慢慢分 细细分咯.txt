```
class Solution {
public:
    string simplifyPath(string path) {
        string res = "/";//根
        for(int i=1; i<path.size(); ++i){
            //去除重复斜杠
            if(path[i] == '/'){
                if(res.back() == '/') continue;
                else{
                    res += path[i];
                    continue;
                }
            }
            //当前路径还是父级别
            if(path[i] == '.'){
                //父路径 或以 ..开头的路径名
                if(i+1 < path.size() && path[i+1] == '.'){
                    i += 2;
                    // ..开头的路径名
                    if(i < path.size() && path[i] != '/'){
                        res += "..";
                        while(i < path.size() && path[i] != '/'){
                            res += path[i];
                            i++;
                        }
                        i--;//保障 因path[i] = / 结束while的情况 
                    }
                    //父路径
                    else if(res.size() > 1){//不能把根删了
                        res.pop_back();//string 没有重载-=运算符噢
                        while(res.back() != '/') res.pop_back();
                    }
                    continue;
                }
                //当前路径或以 .开头的路径名
                else{
                    i++;
                    //以.开头的路径名
                    if(i < path.size() && path[i] != '/'){
                        res += '.';
                        while(i < path.size() && path[i] != '/'){
                            res += path[i];
                            i++;
                        }
                        i--;
                    }
                    //当前路径
                    continue;
                }
            }
            //以字母开头的路径名
            res += path[i];
        }
        //去除末尾的斜杠
        while(res.size()>1 && res.back() == '/') res.pop_back();
        return res;
    }
};
```
