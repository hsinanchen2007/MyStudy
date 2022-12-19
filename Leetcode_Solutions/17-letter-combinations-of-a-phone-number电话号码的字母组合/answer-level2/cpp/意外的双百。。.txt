### 解题思路
看到题第一想法就是dfs深度优先搜索，写了个递归，莫名其妙得了双百也是很意外。
![image.png](https://pic.leetcode-cn.com/3db96dbb30f4d547aabc6d0266f5eb55fb8ff39aeead90da1922ed8ded359af4-image.png)


### 代码

```cpp
class Solution {
public:
    char letters[8][4]={{'a','b','c'},
                      {'d','e','f'},
                      {'g','h','i'},
                      {'j','k','l'},
                      {'m','n','o'},
                      {'p','q','r','s'},
                      {'t','u','v'},
                      {'w','x','y','z'}      
                      };
    void combinate(char* digits,int length,int index,string str,vector<string>& combinations){
        if(index==length){
            combinations.push_back(str);
            return;
        }
        int n=3;
        if(digits[index]=='9'||digits[index]=='7') n=4;
        int num=digits[index]-'0'-2;
        index++;
        for(int i=0;i<n;i++){
            string temp=str;
            temp+=letters[num][i];
            combinate(digits,length,index,temp,combinations);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        
        string str;
        combinate((char*)digits.c_str(),digits.length(),0,str,ans);
        return ans;
    }
};
```