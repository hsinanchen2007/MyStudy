将每个字符串反转,相同后缀就转换为相同前缀，可以直接比较大小。
将数组排序后，即可将相同前缀的数组按长度排好序
### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
      int res=0;
      for(int i=0;i<words.size();i++)//这里用了string的reverse函数
       reverse(words[i].begin(),words[i].end());
       sort(words.begin(),words.end());//直接快排
       for(int i=1;i<words.size();i++){
           if(words[i-1]!=string(words[i],0,words[i-1].length())){ //如果这个字符串包含上一个字符串，则不累加，如果不被包含，则加上上一个字符串的长度。
               res+=words[i-1].length();
               res++;
           }
       }
       res+=words[words.size()-1].length();//加上最后一个字符串
       return res+1;
    }
};
```