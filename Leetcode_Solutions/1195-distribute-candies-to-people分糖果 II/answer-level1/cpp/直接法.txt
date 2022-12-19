### 解题思路
此处撰写解题思路

初学者勿喷，各位大神可以提提意见。分为两个for循环，if用的比较多，应该还有可以改进的地方，欢迎各位大神来提出意见
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {


vector<int> tar;
for(int i=1;i<=num_people;i++)   //第一轮插入
{
    if(i<=candies)
    tar.push_back(i);
    else if(i>candies&&candies>0)
    tar.push_back(candies);
    else if(candies<0)
    tar.push_back(0);
    candies-=i;
}
for(int i=num_people+1;candies>0;i++) //依次叠加
{
  int j=(i-1)%num_people;
  if(candies>i)
  tar[j]+=i;
  else
  tar[j]+=candies;
  candies-=i;
}
return tar;
    }
};
```