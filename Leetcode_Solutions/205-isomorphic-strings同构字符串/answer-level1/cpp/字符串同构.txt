哈希表交叉映射
--------------
* 建立两个哈希表
* 需要同时遍历两个哈希表
```cpp
class Solution {
public:
    //哈希交叉映射
    //比如对于tit和pap，
    //对于tit所有的t对应p，所有的i对应a
    //对于pap所有的p对应t，所有的a对应i
    //同时遍历两个字符串，就去map中寻找 该字母是否有对应值（映射），
    //如果有就去查该映射的值是否与另一个字符串中对应位字母相同，如果不同就不是同构字符串
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> sHash;
        unordered_map<char,char> tHash;
        for(int i=0;s[i]!='\0';++i){
            if(sHash.count(s[i]) && s[i]!=tHash[t[i]]){
                return false;
            }
            else if(tHash.count(t[i]) && t[i]!=sHash[s[i]]){
                return false;
            }
            else{ 
                tHash[t[i]]=s[i];
                sHash[s[i]]=t[i];
            }
        }
        return true;
    }
};
```