### 解题思路
![2020-02-10 18-42-26 的屏幕截图.png](https://pic.leetcode-cn.com/64cb0f0c74df9223369f2193e7288eed959183a0c45de502567b6373ff24a385-2020-02-10%2018-42-26%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)
思路就是全部用数组来存储字母频率，而不是每次都用findd或者map来保存数据。
然后一边读取一边比较，遇到不合适就break进入下一个单词的比较。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
     int ans=0,count=0;
     int len=words.size();
     int m[1000][26]={0};//words中字母出现频率是二维数组
     int n[26]={0};//chars是一维
     for(auto b:chars) n[b-'a']++;//记录chars的字母频率
     for(int i=0;i<len;i++){
        for(auto c:words[i]) m[i][c-'a']++;//依次读取第i个单词每一个字母，在一个for循环中记录第i个单词的字母频率
        for(int j=0;j<26;j++){
            if(m[i][j]>n[j])
            break;//只要出现一个不满足就break，节约时间
            count++;
        }
        if(count==26) ans=ans+words[i].size();//从a到z都符合
        count=0;
     }
     return ans;
    }
};
```