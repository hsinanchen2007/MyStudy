```
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int temp1,temp2;
        for(int i=1;i<=sqrt(area);i++)
        {
            if(area%i==0)
            {
                if(i>area/i)
                    break;
                else{
                    temp1=i;
                    temp2=area/i;
                }
            }
        }
        vector<int> res;
        res.push_back(temp2);
        res.push_back(temp1);
        cout<<temp1<<" "<<temp2;
        return res;
    }
};
```
![Y2G(IHL\[K582`X~7QIC@GXR.png](https://pic.leetcode-cn.com/458b47c8f968f387b849ee1e2dcab0b66323b79c29e99c7813b74237de8ea075-Y2G\(IHL%5BK582%60X~7QIC@GXR.png)
