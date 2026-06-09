### 解题思路
条件为六边长度平方分别为a,a,a,a,2a,2a(a≠0)

### 代码

```cpp
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
     vector<int> p;
     p.push_back(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));   
     p.push_back(pow(p1[0]-p3[0],2)+pow(p1[1]-p3[1],2)); 
     p.push_back(pow(p1[0]-p4[0],2)+pow(p1[1]-p4[1],2)); 
     p.push_back(pow(p2[0]-p3[0],2)+pow(p2[1]-p3[1],2)); 
     p.push_back(pow(p2[0]-p4[0],2)+pow(p2[1]-p4[1],2)); 
     p.push_back(pow(p3[0]-p4[0],2)+pow(p3[1]-p4[1],2));
     sort(p.begin(),p.end());
     return (p[1]==p[0]&&p[2]==p[0]&&p[3]==p[0]&&p[4]==p[0]*2&&p[5]==p[0]*2&&p[0]!=0); 
    }
};
```