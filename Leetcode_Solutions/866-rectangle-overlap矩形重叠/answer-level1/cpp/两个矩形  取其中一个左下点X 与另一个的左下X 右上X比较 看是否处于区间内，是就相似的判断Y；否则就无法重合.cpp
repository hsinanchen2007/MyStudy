### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       
        if(rec1[0]<=rec2[0])
        {
            if(rec1[2]<=rec2[0])
               {cout<<"false"<<endl;return false;}
            else if(rec1[2]>rec2[0])
            {
                if(rec2[3]>rec1[1]&&rec2[1]<rec1[3])
                   { cout<<"true"<<endl;return true;}
                else
                {
                    cout<<"false"<<endl;return false;
                }
            }      
        }
        else
        {
            if(rec2[2]<=rec1[0])
               { cout<<"false"<<endl;return false;}
            else if(rec2[2]>rec1[0])
            {
                if(rec1[3]>rec2[1]&&rec1[1]<rec2[3])
                   { cout<<"true"<<endl;return true;}
                else
                {
                    cout<<"false"<<endl;return false;
                }
            }      
        }
        return 0;
    }
};
```