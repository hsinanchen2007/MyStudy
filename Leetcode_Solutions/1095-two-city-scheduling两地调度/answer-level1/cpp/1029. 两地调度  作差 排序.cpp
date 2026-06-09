### 解题思路
此处撰写解题思路

### 代码

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
//brutal

//第一个小的去第一个，
//第二个小的去第二个
//作差，排序，select

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> myVec;
        vector<vector<int>>::iterator first = costs.begin();
        for(vector<vector<int>>::iterator ite = costs.begin(); ite != costs.end(); ++ite){
            //myVec.push_back(*ite[0] - *ite[1]);
            pair<int,int> tmpPair;
            tmpPair.first = distance(first, ite);
            tmpPair.second = (*ite)[0] - (*ite)[1];
            myVec.push_back(tmpPair);
        }
        //可以自己定义compare,第三个参数不写的话则是从小到大
        sort(myVec.begin(), myVec.end(), compare);
        int costCnt = 0;
        for( int i = 0; i < myVec.size()/2; i++){
            costCnt += costs[myVec[i].first][0];
        }
        for(int i = myVec.size()/2; i < myVec.size(); i++){
            costCnt += costs[myVec[i].first][1];
        }

        return costCnt;
    }

};



```

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
//brutal

//第一个小的去第一个，
//第二个小的去第二个
//作差，排序，select

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> myVec;
        vector<vector<int>>::iterator first = costs.begin();
        for(vector<vector<int>>::iterator ite = costs.begin(); ite != costs.end(); ++ite){
            //myVec.push_back(*ite[0] - *ite[1]);
            pair<int,int> tmpPair;
            tmpPair.first = distance(first, ite);
            tmpPair.second = (*ite)[0] - (*ite)[1];
            myVec.push_back(tmpPair);
        }
        //可以自己定义compare,第三个参数不写的话则是从小到大
        sort(myVec.begin(), myVec.end(), compare);
        int costCnt = 0;
        int halfSize = myVec.size()/2;
        for( int i = 0; i < myVec.size()/2; i++){
            costCnt += costs[myVec[i].first][0] + costs[myVec[i+halfSize].first][1];
        }

        return costCnt;
    }

};



```