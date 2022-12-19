1. 路径的结构和栈的结构非常像
2. 当向下进入子目录时，等同于入栈的操作
3. 当向上返回一层目录时，相当于出栈的操作
4. 用"/"符号分割字符串得到每次是入栈还是出栈
5. C++代码如下：
```
string simplifyPath(string path) 
    {
        vector<string> dir = {};
        int loc = 0;
        while(loc < path.size())
        {
            string name = "";
            while(loc<path.size() && path[loc] != '/')
            {
                name += path[loc];
                loc++;
            }
            if(name != "" && name != ".." && name != ".")
                dir.push_back(name);
            if(name == ".." && dir.size()>0)
                dir.pop_back();
            loc++;
        }
        /*
        for(int i=0;i<dir.size();i++)
            cout<<dir[i]<<" ";
        cout<<endl;
        */
        string dirpath = "/";
        if(dir.size() == 0)
            return dirpath;
        for(int i=0;i<dir.size()-1;i++)
        {
            dirpath += dir[i];
            dirpath += "/";
        }
        dirpath += dir[dir.size()-1];
        return dirpath;
    }
```
