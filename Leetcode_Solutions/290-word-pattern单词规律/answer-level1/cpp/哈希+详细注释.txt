![1585997936(1).jpg](https://pic.leetcode-cn.com/937596750c26a5d3ed338b1ba2e5c943989f8e317884567582efab515d63781f-1585997936\(1\).jpg)

可能有表述不到位 或者可以优化的地方，欢迎提出宝贵意见~_~。
```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vtr;
        int t=-1;
        for(int i=1;i<str.size();i++){//将str中的字符块保存到vtr中，方便使用索引
            if(str[i]==' '){
                t=t+1;
                vtr.push_back(str.substr(t,i-t));
                t=i;
            }
        }
        vtr.push_back(str.substr(t+1,str.size()-1));//因为最后一个字符块后面没有空格符，所以最后单独加这一步
        int n=pattern.size(),m=vtr.size();
        if(n!=m) return false;//两个对应大小不等，直接返回false
        map<char,int> map1;//记录pattern的关系
        map<string,int> map2;//记录str（vtr）的关系
        for(int i=0;i<n;i++) if(!map1[pattern[i]]) map1[pattern[i]]=i+1;//如果map1里面没有这个key，这将这个key与其索引值+1加入map1中
        for(int i=0;i<m;i++) if(!map2[vtr[i]]) map2[vtr[i]]=i+1;//同理维护map2
        for(int i=0;i<n;i++) if(map1[pattern[i]]!=map2[vtr[i]]) return false;//比较若key的对应值不相等，则说明不一一映射，返回false
        return true;//所有的都满足，返回true
    }
};
```
