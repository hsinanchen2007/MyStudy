![image.png](https://pic.leetcode-cn.com/2dd4b8f5111597631d9bf5acac1162cc574cb3256b9348102b75fc843942545d-image.png)

注意各种边界情况，就酱紫

```
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> p;
        string result="",tmp;
        p.push("/");
        for(int i=1;i<path.size();i++){
            if(path[i] == '/'){
                if(tmp.size()!=0)p.push(tmp);
                tmp = "";
            }else{
               tmp += path[i]; 
               if(tmp == "."){
                   i++;
                   while(i<path.size() and path[i]!='/'){
                       tmp += path[i];
                       i++;
                   }
                   i--;
                   if(tmp == "." ){
                       tmp = "";
                       cout<<tmp;
                       continue;
                   }
                   if(tmp==".."){
                       if(!p.empty()) p.pop();
                       tmp = "";
                       continue;
                   }            
                   if(i == path.size()-1) {
                       p.push(tmp); 
                       tmp = "";
                   }    
               }
            }
        }
        if(tmp.size()!=0) {
            p.push(tmp);
            tmp = "";
        }
        if(p.empty()) return "/";
        while(!p.empty()){
           tmp = p.top();
           p.pop();
           if(tmp!="/") result = tmp + result;
           if(!p.empty()) result = "/" + result;
        }
        if(result[0] !='/') result = "/" + result;
        return result;
        
    }
};
```
