### 解题思路
此处撰写解题思路
首先排除两种特殊情况：
（1）当为一个空的数组时，则返回一个空的字符串即可；
（2）当数组中只有一个字符串时，则返回这个字符串；

接下来考虑一般情况：
（1）先计算出整个数组中字符串长度最小值min_length；
（2）以第一个字符串作为基准，将后面的字符串的前min_length个字符和第一个字符串的前min_length个字符进行比较，如果碰到不相同的，则直接返回所得到的字符串即可；

具体的代码和解释如下代码：
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
      string result;//存储结果的字符串，起始值为空
      int size = strs.size();//计算字符串数组的长度
      if(size==0) return result;//如果是一个空的数组，则没有公共前缀，直接返回空的字符即可
      if(size==1) return strs[0];//如果数组中只有一个字符串，则返回这个字符串
      int min_length;//用来存储最短的字符串的长度，防止越界
      for(int i=0; i<size-1; i++)//计算最小长度
      {
         if(strs[i].length()>strs[i+1].length())
            min_length = strs[i+1].length();
         else
            min_length = strs[i].length();
      }  

      string first = strs[0];//以第一个字符串为基准
      for(int j=0; j<min_length; j++)//遍历第一个字符串的前min_length个字符
      {
          char c = first[j];//将正在遍历的字符存储在字符c中
          bool b = true;//设置循环标志
          int n = 1;//从第二个字符串开始和第一个字符串的字符进行比较
          while(b)
          {             
              string str = strs[n];//将第n+1个字符串存储在str中
              if(c!=str[j]) b = false;//一旦发现字符不相同，则可结束循环
              else if(n==size-1) break; //当将整个数组遍历完成后，说明这个字符满足要求
              n++;                    
          }
          if(b==false) break; //退出程序，返回结果
          else if(b==true) result.push_back(c); //符合要求，加入到结果字符串，继续遍历
      }
    return result;
    }
};
```