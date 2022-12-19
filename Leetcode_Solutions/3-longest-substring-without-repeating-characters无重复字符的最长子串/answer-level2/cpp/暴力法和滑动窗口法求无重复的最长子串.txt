第一种方法：暴力法
边遍历边查找，用res保存遍历过的字符，用result保存res数组的最大长度。每遍历s中的一个字符c，都先在res中用find函数查找第一个相同的字符所在的位置pos，如果的有相同的字符，用erase成员函数删除res字符从0到pos位置的字符。最后返回result既是最长无重复子串。
时间复杂度O(n²）   空间复杂度O(1)
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0,pos;
        string res;
        for(int i=0;i<s.size();i++)
        {
            if((pos=res.find(s[i]))!=-1)   //在res中查找与s[i]相同的第一个字符所在的位置pos
                res.erase(0,pos+1);         //删除res中0-pos的值
            res+=s[i];
            if(result<res.size())
                result=res.size();
        }          
        return result;
    }
};


```
第二种方法：滑动窗口法
用max来记录前n-1个字符的最大无重复的子串，用right来标记s的第n-1个字符，用left来标记s的另外一个字符，使得[left,right]之间是无重复的子串。若第n个字符与[left,right]之间的字符有重复，则left移动到与第n个字符重复的字符的下一个位置，right移动到第n位。若不重复，则right-left+1则表示包含第n位的不重复子串的大小，然后用max与之比较即可。
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=1;
        int right=1,left=1; 
        if(s.size()==0)
            return 0;
        unordered_map<char,int> hashmap;  //创建从字符到字符所在的位置的映射，位置从1开始
        for(int i=0;i<s.size();i++)
        {
            if(hashmap[s[i]]>=left)      //hashmap[s[i]]默认值是0，而hashmap[s[i]]>=left说明s[i]对应的字符
                left=hashmap[s[i]]+1;    //以及出现在hashmap[s[i]]对应的位置。令left=hashmap[s[i]]+1即可
            hashmap[s[i]]=i+1;           //字符s[i]对应的位置为i+1；
            right=hashmap[s[i]];         //right指向第i位
            max=(max<right-left+1)?(right-left+1):max;
        }          
        return max;
    }
};
```
ps:不知道为什么第一种方法用的平均时间要比第二种少。。。。。。

