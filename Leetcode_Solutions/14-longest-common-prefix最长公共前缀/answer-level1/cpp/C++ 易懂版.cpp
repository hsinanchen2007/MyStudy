# C++
效率一般，但感觉清晰易懂
![image.png](https://pic.leetcode-cn.com/dc34e7e5a912619c23541a7d95b45395856dde94627f06f0a0eb3cd02fc5e9bc-image.png)


核心思想：从0开始逐个字母比较，下列2种情况返回已经找到的最长前缀
1. 如果有字串到了末尾
2. 如果有字串出现不同字母
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int lenVec = strs.size();
        if(lenVec==0)
            return "";// 如果vector中没有string，返回空串
        if(lenVec==1)
            return strs.at(0);//如果vector中有一个string，直接返回该串
        
        int j = 0;//记录最大公共前缀长度
        while(1){
            for(int i=0; i<lenVec; i++){
                if(j >= strs.at(i).size())
                    return strs.at(i).substr(0,j);//如果遇到字串结束，返回已找到的前缀
                
            char c = strs.at(0).at(j);    
                if(c != strs.at(i).at(j))
                    return strs.at(i).substr(0,j);//如果遇到字串中字母不相等，返回已找到的前缀
            }
            j++;
        }
        
    }
};
```
