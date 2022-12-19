

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
      //建立一个map key 是string value是vector<string>
      map<string,vector<string>> save;

      for(auto i : strs){
          auto tmp=i;
          sort(tmp.begin(),tmp.end());
          //如果在里面不能找到
          if(save.find(tmp)==save.end()){
                vector<string>  t;
                t.push_back(i);
                save[tmp]=t;
          }else{
                //如果在里面能找到
                save[tmp].push_back(i);
          }
          
      }  
      vector<vector<string>> result;
      for(auto i=save.begin();i!=save.end();i++){
          result.push_back((*i).second);
      }
      return result;
    }
};
```