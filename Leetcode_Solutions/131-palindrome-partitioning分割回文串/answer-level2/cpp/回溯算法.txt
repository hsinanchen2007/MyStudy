```
class Solution {
public:
    //这里需要创建一个是否是回文串的函数
     vector<vector<string>>result;
     bool fun1(string s){
         if(s.size()==1) return true;
         int i=0, j=s.size()-1;
         while(i<j){
             if(s[i]!=s[j]){
                 return false;
             }
               i++,j--;
         }
         return true;
     }
     void fun2(string s,int location,vector<string>&temp){
         int n=s.size();
         if(location>=n)
                result.push_back(temp);
        for(int i=location;i<s.size();i++){
            string t=s.substr(location,i-location+1);
            if(fun1(t)){
                temp.push_back(t);
                fun2(s,i+1,temp);//这里得是i  不能使location  使用location 更新过于缓慢
                temp.pop_back();
            }
        }
     }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        if(s.size()<1) return result;
        fun2(s,0,temp);
        return result;
    }
};
```
