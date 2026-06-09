利用凸包的ToLeft测试，具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/836.rectangle_overlap)

```
class Solution {
//To Left Test; line: px, py, qx,qy;point: sx,sy;
  //p.x * q.y - p.y* q.x + q.x * s.y - q.y * s.x + s.x * p.y - s.y * p.x;
bool toLeft(vector<int>rec1,int px, int py,int qx, int qy)
{
    vector<long int> tmp(4,0);
    int start=0;
    for(int i=0;i<3;i+=2)
        for(int j=1;j<4;j+=2)
        {
            int sx=rec1[i];
            int sy=rec1[j];
            tmp[start++] = (long)px*qy-(long)py*qx +(long)qx*sy -(long)qy*sx + (long)sx*py -(long)sy *px ;  
            }
   // cout<< px <<"   "<<py<<"   "<<qx<<"   "<<qy<<endl;
//   cout<<tmp[0] <<" "<< tmp[1] <<" "<<tmp[2] <<" "<< tmp[3]<<endl;
    if( tmp[0]<=0 && tmp[1]<=0 && tmp[2]<=0 && tmp[3]<=0) return true;
    return false;

}
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
            return !(toLeft(rec1,rec2[0],rec2[1],rec2[2],rec2[1]) || toLeft(rec1,rec2[2],rec2[1],rec2[2],rec2[3]) || toLeft(rec1,rec2[2],rec2[3],rec2[0],rec2[3] ) || toLeft(rec1,rec2[0],rec2[3],rec2[0],rec2[1]));
        
    }
};
```


> 执行用时 :4 ms, 在所有 C++ 提交中击败了75.38%的用户                                                                  
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了92.54%的用户