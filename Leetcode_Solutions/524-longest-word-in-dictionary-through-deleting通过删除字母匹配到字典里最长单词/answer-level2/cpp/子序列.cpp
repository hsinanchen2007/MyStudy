### 解题思路
双指针找字符串子序列

### 代码

```cpp

class Solution {
public:
    //前提是可以通过删除s中得字符，直接得到target，说明顺序相同，只是插入了其他字母
    string findLongestWord(string s, vector<string>& d) {
        //定义变量储存最大值
        string longestStr="";
        //遍历容器
        for(int i=0;i<d.size();i++){
            //如果比当前最长已经匹配的单词还短，一定不是
            if(longestStr.size()>d[i].size()){
                continue;
            }
            //如果一样长，//且更大，一定不是
            if(d[i].size()==longestStr.size() && longestStr.compare(d[i])<0){
                continue;
            }
            //如果是子序列，储存最大
            if(SubString(s,d[i])){
                longestStr=d[i];
            }
        }
        return longestStr;
    }
    //双指针判断是否死子序列
    bool SubString(string s,string target){
        int i=0,j=0; 
        while(i<s.length()&&j<target.length()){  
            //相同两个指针都后移一位
            if(s[i]==target[j]){
                j++;   
            }
            //如果不相同，删除相当于s后移一位指针
            i++;  
        }
        if(j==target.length()){
            return true;
        }
        return false;
    }

};
```