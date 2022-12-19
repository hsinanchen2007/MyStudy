### 解题思路
从最开始，每次添加一对括号。
感觉我是不是废了，想不到其他的.......

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> resA;//原数组
      vector<string> resB;//加一对括号后的字符串数组
      string tempstr="()";
      string temp;
      int flag=1;
      resA.push_back(tempstr);//初始在原数字中添加一对括号
      for(int i=1;i<n;i++)//添加括号的次数
      {
          for(int j=0;j<resA.size();j++)//在原数组字符串中添加
          {
              int size=resA[j].size();
              for(int k=0;k<size;k++)
              {
                 temp=resA[j];
                 tempstr=temp.insert(k, "()");//在原数组字符串中第k个位置添加
                 flag=1;
                 for(int s=0;s<resB.size();s++)//检查resB中是否有一样的字符串
                {
                    if(resB[s]==tempstr)flag=0;
                }   
                if(flag)resB.push_back(tempstr);//如果没有在末尾加入该字符串
              }
          }
          resA=resB;
          resB.clear();//清空resB待下次使用
      }
      return resA;
    }
};
```