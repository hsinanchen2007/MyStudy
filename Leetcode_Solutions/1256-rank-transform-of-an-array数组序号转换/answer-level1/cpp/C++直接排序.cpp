### 解题思路
首先将位置和数转成结构体一起存起来，然后排序，先排大小，再转换成编号，再凭一起储存的原位置生成返回的数组。

### 代码

```cpp
struct node{
    int id;
    int num;
};
bool cmp(node a,node b){
    if(a.num==b.num) return a.id<b.id;
    return a.num<b.num;
}
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ar;
        vector<node> p;
        node q;
        for(int i=0;i<arr.size();i++){
            q.id=i;
            q.num=arr[i];
            p.push_back(q);
        }
        int j=1,swap=-1;
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<arr.size();i++){//编号
            if(p[i].num==swap) j--;//查重
            swap=p[i].num;
            p[i].num=j;
            j++;
        }
        for(int i=0;i<arr.size();i++){
            ar.push_back(0);
        }
        for(int i=0;i<ar.size();i++){
            ar[p[i].id]=p[i].num;
        }        
        return ar;
    }
};
```