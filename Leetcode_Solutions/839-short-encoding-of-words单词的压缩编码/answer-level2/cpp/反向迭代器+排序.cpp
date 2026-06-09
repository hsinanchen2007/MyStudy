用反向迭代器排序，使得后缀相同的会从短到长排序，然后从前往后遍历，检测当前字符串是不是下一个字符串的后缀，是的话就跳过
```
//反序a和反序b比较字典序
bool reverseDictCmp(string& a, string &b) {
    auto rita = a.rbegin(), ritb = b.rbegin();
    while (rita != a.rend() && ritb != b.rend()) {
        if (*rita < *ritb)return true;
        if (*rita > *ritb)return false;
        ++rita;
        ++ritb;
    }
    return ritb != b.rend();
}
//a是b的后缀
bool isSuffix(string& a,string & b){
    auto ia=a.begin(),ib=b.end()-a.size();
    while(ib!=b.end()){
        if(*ia!=*ib)return false;
        ++ia;
        ++ib;
    }
    return true;
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //倒字典序排列？
        sort(words.begin(),words.end(),reverseDictCmp);
        int total=0,len=words.size()-1;
        for(int i=0;i<len;++i){
            int curlen=words[i].size(),nextlen=words[i+1].size();
            if(curlen<=nextlen && isSuffix(words[i],words[i+1]))continue;
            total+=curlen+1;
        }
        return total+words[len].size()+1;
    }
};
```
