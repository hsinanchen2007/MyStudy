### 解题思路
观察到按照括号的深度，奇数和偶数分开即可。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
          int n=seq.size(),cnt=0;
          vector<int> re;
          int a[n];//a[n]存储各个括号的深度
          for(int i=0;i<n;i++) a[i]=0;
          for(int i=0;i<n;i++)
          {
              if(seq[i]=='(')
                {cnt++;a[i]=cnt;}
              else
                { a[i]=cnt;cnt--;}
             
          }
          for(int i=0;i<n;i++)
          {
              if(a[i]%2==0)
                re.push_back(1);
              else 
                re.push_back(0);
          }
          return re;
    }
};
```