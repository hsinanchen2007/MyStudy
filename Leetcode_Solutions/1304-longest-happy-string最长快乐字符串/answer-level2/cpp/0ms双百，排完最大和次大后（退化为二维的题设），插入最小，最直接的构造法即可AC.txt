### 解题思路
先排序，利用pair，减小分类讨论量
然后给出一种构造方式即可。
笔者的方法是先排好a,b最后插c（假设a>=b>=c）
由于a>(b+c+1)*2时，多出来的部分无处安置，是无效的，固舍掉这部分
排a,b就退化为了二维问题，一个最直接的构造思路，a比b大时，两个a加一个b，减到或初始就一样多时，一个a一个b，这样可能会产生末位余a的问题，我们只需要从后向前每隔两个插c即可（2*c<(a+b)所以不会越界)
### 代码

```cpp
class Solution {
public:
    static bool cmp(pair<int,string>a,pair<int,string>b){
        return a.first>b.first;
    }
    string longestDiverseString(int a, int b, int c) {
       vector<pair<int,string>> v;
       v.push_back(make_pair(a,string ("a")));
       v.push_back(make_pair(b,string ("b")));
       v.push_back(make_pair(c,string ("c")));
       sort(v.begin(),v.end(),cmp);
       string s;
       if(v[0].first>(v[1].first+v[2].first+1)*2) v[0].first=2*(v[2].first+v[1].first+1);//长度上限
       while(v[0].first>1&&v[1].first>0&&v[0].first>v[1].first){
           s+=v[0].second+v[0].second,v[0].first-=2;
           s+=v[1].second,v[1].first--;   
       }
       while(v[0].first>0&&v[1].first>0){
           s+=v[0].second,v[0].first--;
           s+=v[1].second,v[1].first--;
       }
       while(v[0].first>0){
            s+=v[0].second,v[0].first--;
       }
       int len=s.size()-2;
       while(v[2].first>0){
           s.insert(len,v[2].second),v[2].first--;
           len-=2;
       }
       return s;
    }
};
```