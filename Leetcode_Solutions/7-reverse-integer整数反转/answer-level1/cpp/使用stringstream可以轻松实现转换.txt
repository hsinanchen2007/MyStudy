由于stringstream时c++中十分常见的字符串与数字相互转换的方式，完全可以直接使用。
```
class Solution {
public:
    int reverse(int x) {
    stringstream p;
    string s;
    p<<x;
    p>>s;
    string temp;
    if(s[0]=='-'){
        temp.push_back(s[0]);
        for(int i=s.length()-1;i>0;i--){
            temp.push_back(s[i]);
        }
    }
    else{
        for(int i=s.length()-1;i>=0;i--){
            temp.push_back(s[i]);
        }
    }
    //清空缓冲区
    p.clear();
    p<<temp;
    p>>x;
    if(x==INT_MAX || x==INT_MIN) return 0;
    return x;
}
};
```
