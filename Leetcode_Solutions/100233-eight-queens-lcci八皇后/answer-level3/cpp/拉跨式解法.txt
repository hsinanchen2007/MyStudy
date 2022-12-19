### 解题思路
将所有皇后可能的放置位置全排列，判断所有排列是否符合题目要求。

### 代码

```cpp
class Solution {
public:
    //确保所有的皇后不在同一对角线上
    bool RightQueue(vector<int> _numList){
        for(int i=0;i<_numList.size()-1;++i){
            for(int j=i+1;j<_numList.size();++j){
                if(abs(_numList[i]-_numList[j])==j-i){
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        //断言n非负
        assert(n>0);
        //定义返回结果
        vector<vector<string>> _finalResult;
        //获得基础数字序列
        vector<int> _numList;
        for(int i=0;i<n;++i){
            _numList.push_back(i+1);
        }
        //获得数字序列的所有全排列
        vector<vector<int>> _allNumList;
        do{
            _allNumList.push_back(_numList);
        }while(next_permutation(_numList.begin(),_numList.end()));
        //判断所有全排列是否符合要求，符合要求则将数字序列转换为字符串序列
        for(int i=0;i<_allNumList.size();++i){
            if(RightQueue(_allNumList[i])==true){
                vector<string> _tmp;
                for(int j=0;j<n;++j){
                    string _tmpS="";
                    for(int k=0;k<n;++k){
                        if(k==_allNumList[i][j]-1){
                            _tmpS+="Q";
                            continue;
                        }
                        _tmpS+=".";
                    }
                    _tmp.push_back(_tmpS);
                }
                _finalResult.push_back(_tmp);
            }
        }
        return _finalResult;
    }

};
```