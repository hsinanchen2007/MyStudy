**题解：**
* 1）建立两个表：count表示字符表，uesd用记录字符是否已添加的表
* 2）第一遍遍历字符串，用来建立字符表
* 3）第二遍遍历字符串，用来生成无重复字符串
* 4）相关注解已给，有什么不懂的欢迎交流

**代码如下：**
```cpp
class Solution {
public:
    //count表示字符表，used用来记录已经添加过的字符
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        bool used[26];
        memset(used,false,sizeof(used));
        string s1="";

        //1、建立字符表
        for(auto c:s)
            count[c-'a']++;

        //2、用来添加字符
        for(auto c:s){
            count[c-'a']--;//无论是否添加字符c到s1中，都需要将该字符个数减1，表示能使用该字符的次数少了一次
            if(used[c-'a']) continue;//字符c已使用过了，不能重复使用

            //字符c小于s1的尾字符，其尾字符在字符表中还有剩余，所以我们需要删除尾字符，同时标记尾字符为没有使用过
            while(s1.length()>0 && c<s1[s1.length()-1] && count[s1[s1.length()-1]-'a']>0){
                used[s1[s1.length()-1]-'a']=false;
                s1.erase(s1.length()-1);
            }

            //添加字符c，并标记字符c已使用过了
            s1+=c;
            used[c-'a']=true;
        }
        return s1;
    }
};
```
