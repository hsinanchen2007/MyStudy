```
        vector<char>  temp;
        unordered_map<char,int> mymap;
        for(auto i:s)
        {
            auto it=mymap.find(i);
            if(it==mymap.end())
            {
                mymap[i]=1;
                temp.push_back(i);
            }
            else
                it->second++;
        }
        for(int i=0;i<temp.size();i++)
            if(mymap[temp[i]]==1)
                return s.find(temp[i]);
        return -1;
```
