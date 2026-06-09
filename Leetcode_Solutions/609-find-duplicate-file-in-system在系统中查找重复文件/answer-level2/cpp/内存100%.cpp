```
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        map<string,vector<string>> dic;
        string path;
        for(int i=0;i<paths.size();++i)
        {
            int pos = paths[i].find(' ',0);
            string path = paths[i].substr(0,pos);//文件路径
            int l,r=0;
            int temp;
            string tempPath(path);
            while(r != (int)(paths[i].size()-1))
            {
                temp = pos;
                path = tempPath;
                l = paths[i].find('(',pos+1);
                r = paths[i].find(')',pos+1);
                string file = paths[i].substr(l+1,r-l-1);//文件内容
                string name = paths[i].substr(pos+1,l-pos-1);//文件名称
                path += '/';
                path +=name;
                if(dic.count(file)>0)
                {
                    dic[file].push_back(path);
                }
                else
                {
                    vector<string> p;
                    p.push_back(path);
                    dic.insert(map<string,vector<string>>::value_type(file,p));
                }
                pos = paths[i].find(' ',temp+1);
            }
        }
        for(auto it=dic.begin();it!=dic.end();++it)
        {
            if(it->second.size() >= 2)
                res.push_back(it->second);
        }
        return res;
     }
};
```
