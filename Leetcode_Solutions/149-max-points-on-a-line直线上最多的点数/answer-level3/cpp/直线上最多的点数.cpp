### 解题思路
点斜式

### 代码

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        if(points.size() == 1){
            return 1;
        }

        int ans = 0;
        for(int i = 0;i<points.size();i++){
            int duplicate = 0;
            int tempMax = 0;
            unordered_map<string,int> slope;
            for(int j = i+1;j < points.size();j++){
                
                int molecule = points[i][1] - points[j][1];
                int denominator = points[i][0] - points[j][0];

                if(molecule == 0 && denominator == 0){
                    duplicate++;
                    continue;
                }

                int gcdNum = gcd(molecule,denominator);
                cout << gcdNum << "  ";
                molecule = molecule / gcdNum;
                denominator = denominator / gcdNum;
                if((molecule > 0 && denominator <0) || (molecule<0 && denominator > 0)){
                    molecule = -abs(molecule);
                    denominator = abs(denominator);
                }else{
                    molecule = abs(molecule);
                    denominator =abs(denominator);
                }
                string strkey = to_string(molecule) + '@';
                strkey = strkey + to_string(denominator);
                cout << strkey << endl;
                if(slope.find(strkey) == slope.end()){
                    slope.insert(slope.begin(),{strkey,1});
                    tempMax = max(tempMax,1);
                }else{
                    slope[strkey]++;
                    tempMax = max(tempMax,slope[strkey]);
                }
            }
            ans = max(ans,tempMax+duplicate + 1);
        }
        return ans;
    }
};
```