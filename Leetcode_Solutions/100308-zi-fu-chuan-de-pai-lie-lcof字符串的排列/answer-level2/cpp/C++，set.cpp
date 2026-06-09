### 解题思路
利用set进行去重，拿第一个元素和他后面的元素依次交换。

### 代码

```cpp
class Solution {
public:
    set<string> res_tmp;
    vector<string> permutation(string s) {
        vector<string> res;
        help(s,0);
        for(string str:res_tmp){
            res.push_back(str);
        }
        return res;
    }
    void help(string s,int index){ 
        for(int i=index;i<s.length();i++){
            swap(s[index],s[i]);//开始位置字符和后面字符都交换，完成一次排列
            res_tmp.insert(s);
            help(s,index+1);//完成后面字符串的排列
        }
    }
};
```