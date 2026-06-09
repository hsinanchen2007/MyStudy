
![image.png](https://pic.leetcode-cn.com/2d82097afd9660b30284cce45fd851b4349e6c132a91a1e5cc3544df5511dd72-image.png)

```
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        //i j 写成列表，走斜线
        vector<string> res;
        int L1  = list1.size(), L2 = list2.size();
        for(int k = 0; k< L1+L2-1; k++)
        {
            bool foundFlag = false;
            for(int i = 0; i<=k; i++)
            {
                if(i >= L1)continue;
                if(k-i >= L2)continue;
                if(list1[i] == list2[k-i])
                {
                    res.push_back(list1[i]);
                    foundFlag = true;
                }
            }
            if(foundFlag == true) break;
        }
        return res;
    }
};
```
