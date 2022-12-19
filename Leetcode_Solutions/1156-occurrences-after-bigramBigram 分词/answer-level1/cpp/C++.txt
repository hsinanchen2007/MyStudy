执行用时 :4 ms, 在所有 C++ 提交中击败了69.31%的用户
内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> vec,vec1;
        if(text.size()<3) return vec1;
        int tmp=0;
        //将text的字符串先分割好保存至vec中
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                vec.push_back(text.substr(tmp,i-tmp));
                tmp=i+1;
            }
            if(i==text.size()-1) vec.push_back(text.substr(tmp,i-tmp+1));
        }
        //直接比较
        for(int i=0;i<vec.size()-2;i++){
            if(vec[i]==first&&vec[i+1]==second) vec1.push_back(vec[i+2]);
        }
        return vec1;
    }
};
```
