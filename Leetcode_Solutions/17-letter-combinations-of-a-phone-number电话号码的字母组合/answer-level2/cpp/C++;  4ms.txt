### 解题思路
遍历，每次把之前所有的字符串都加上本字母对应的3或4个字母；
因为7开始没有规律，就拿出来直接加；8,9也是；
2-6则是'a'+(n-2)*3开始，分别加0,1,2；
比如：
2对应 (2-2)*3=0; 0+1,0+2,0+3
3对应 (3-2)*3=3; 3+1,3+2,3+3

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        res={""};
        for(int i=0;i<digits.size();i++){
            char now=digits[i];
            vector<string> temp;
            if(now=='7'){
                for(int j=0;j<res.size();j++){
                    temp.push_back(res[j]+'p');
                    temp.push_back(res[j]+'q');
                    temp.push_back(res[j]+'r');
                    temp.push_back(res[j]+'s');
                }
            }else if(now=='8'){
                for(int j=0;j<res.size();j++){
                    temp.push_back(res[j]+'t');
                    temp.push_back(res[j]+'u');
                    temp.push_back(res[j]+'v');
                }
            }else if(now=='9'){
                for(int j=0;j<res.size();j++){
                    temp.push_back(res[j]+'w');
                    temp.push_back(res[j]+'x');
                    temp.push_back(res[j]+'y');
                    temp.push_back(res[j]+'z');
                }
            }else {
                for(int j=0;j<res.size();j++){
                    int k=(now-'2')*3;
                    char a='a'+k;
                    char b='a'+k+1;
                    char c='a'+k+2;
                    temp.push_back(res[j]+a);
                    temp.push_back(res[j]+b);
                    temp.push_back(res[j]+c);
                }
            }
            res=temp;
        }
        return res;
    }
};
```