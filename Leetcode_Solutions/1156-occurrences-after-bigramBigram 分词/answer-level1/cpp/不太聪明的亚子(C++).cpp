```
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string>res;
        vector<string>temp;
        string str = "";
        text += ' ';// 为了方便转换成vector<string>
        for(int i = 0; i < text.size(); i++){// 转换成vector<string>方便处理
            if(text[i] == ' '){
                temp.push_back(str);
                str = "";
                continue;
            }else{
                str += text[i];
            }
        }
        for(int i = 1; i < temp.size(); i++){// 线性查找
            if(temp[i - 1] == first && temp[i] == second){
                if(i+1 < temp.size()){
                    res.push_back(temp[i+1]);
                }
            }
        }
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/fa66babee53f4ff3c90010170e625e42881c7a875d59feaf8521b9249b190a27-1.png)
