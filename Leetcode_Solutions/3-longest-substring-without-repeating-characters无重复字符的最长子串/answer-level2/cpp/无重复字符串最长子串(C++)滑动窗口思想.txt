具体的滑动串口解释,见官方解题的详细解析,我这里提供C++的代码.


```c++ []
//对应官方答案思想里面的方案2,3.
// 滑动串口解法1   
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0,j = 0, n = 0, ans= 0;
        set<char> cont;
        n = s.size();
        set<char>::iterator iter;
        
        while(i< n && j<n){          
            if( (iter=cont.find(s[j])) != cont.end() ){     
                cont.erase(s[i++]);    
            }
            else {
                    
                cont.insert(s[j++]);
                ans = max(ans, j-i);
            }
            
        }
        return ans;
    }
};

//滑动窗口解法2(优化了方法1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> Map_tmp;
        map<char, int>::iterator iter; 
        int i= 0, ans = 0;
        
        for(int j = 0; j<n; j++){
           if( (iter = Map_tmp.find(s[j])) != Map_tmp.end() ){
               i = max(i, iter->second);
           } 
            ans = max(ans, j-i+1);
            Map_tmp[(s[j])] = j+1;
        }
        return ans;
    }
};
```