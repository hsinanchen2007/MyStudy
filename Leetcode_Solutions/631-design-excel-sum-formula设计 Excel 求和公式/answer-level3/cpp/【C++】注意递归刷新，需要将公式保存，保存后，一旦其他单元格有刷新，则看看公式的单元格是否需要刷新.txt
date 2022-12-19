```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/12
 */

class Excel {
public:
    typedef map<pair<int, int>, vector<string>> SumExpInfoContainer;
    Excel(int H, char W)
    {
        int row = H;
        int col = W - 'A' + 1;
        vector<vector<int>> newSheet(row, vector<int>(col, 0));
        this->sheet = newSheet;
    }

    void set(int r, char c, int v)
    {
        int row = r - 1;
        int col = c - 'A';
        pair<int, int> expInfoKey{ row, col };
        SumExpInfoContainer::iterator finder = sumExpInfos.find(expInfoKey);
        if (finder != sumExpInfos.end()) {
            sumExpInfos.erase(finder);
        }
        set(row, col, v);
    }

    int get(int r, char c)
    {
        int row = r - 1;
        int col = c - 'A';
        return this->sheet[row][col];
    }

    int sum(int r, char c, vector<string> strs)
    {
        int row = r - 1;
        int col = c - 'A';
        pair<int, int> expInfoKey{ row, col };
        SumExpInfoContainer::iterator finder = sumExpInfos.find(expInfoKey);
        if (finder == sumExpInfos.end()) {
            sumExpInfos.insert(make_pair(expInfoKey, strs));
        } else {
            this->sheet[row][col] = 0;
            finder->second = strs;
        }
        return sum(strs, row, col);
    }

private:

    void set(int row, int col, int v)
    {
        this->sheet[row][col] = v;
        for (SumExpInfoContainer::const_iterator iter = sumExpInfos.begin();
                iter != sumExpInfos.end();
                ++iter) {
            if (iter->first.first == row && iter->first.second == col) {
                continue;
            }
            vector<string> strs = iter->second;
            bool needRefresh = isNeedRefresh(strs, row, col);
            if (needRefresh) {
                sum(strs, iter->first.first, iter->first.second);
            }
        }
    }

    bool isNeedRefresh(vector<string> &strs, int row, int col)
    {
        bool needRefresh = false;
        for (vector<string>::const_iterator iter = strs.begin();
                iter != strs.end();
                ++iter) {
            string exp = *iter;
            size_t pos = exp.find(":");
            if (pos != string::npos) {
                string from = exp.substr(0, pos);
                string to = exp.substr(pos + 1);
                int cellRowFrom = calcRow(from);
                int cellColFrom = from.at(0) - 'A';
                int cellRowTo = calcRow(to);
                int cellColTo = to.at(0) - 'A';
                if (row >= cellRowFrom && row <= cellRowTo && col >= cellColFrom && col <= cellColTo) {
                    needRefresh = true;
                    break;
                }
            } else {
                int cellRow = calcRow(exp);
                int cellCol = exp.at(0) - 'A';
                if (cellRow == row && cellCol == col) {
                    needRefresh = true;
                    break;
                }
            }
        }
        return needRefresh;
    }

    int sum(vector<string> &strs, int row, int col)
    {
        int v = 0;
        for (vector<string>::const_iterator iter = strs.begin();
                iter != strs.end();
                ++iter) {
            string exp = *iter;
            size_t pos = exp.find(":");
            if (pos != string::npos) {
                string from = exp.substr(0, pos);
                string to = exp.substr(pos + 1);
                int cellRowFrom = calcRow(from);
                int cellColFrom = from.at(0) - 'A';
                int cellRowTo = calcRow(to);
                int cellColTo = to.at(0) - 'A';

                for (int i = cellRowFrom; i <= cellRowTo; ++i) {
                    for (int j = cellColFrom; j <= cellColTo; ++j) {
                        v += this->sheet[i][j];
                    }
                }
            } else {
                int cellRow = calcRow(exp);
                int cellCol = exp.at(0) - 'A';
                v += this->sheet[cellRow][cellCol];
            }
        }

        set(row, col, v);
        return v;
    }

    int calcRow(string &from)
    {
        int row = 1;
        stringstream ss;
        ss << from.substr(1);
        ss >> row;
        return row - 1;
    }

private:
    vector<vector<int>> sheet;
    SumExpInfoContainer sumExpInfos;
};

/**
* Your Excel object will be instantiated and called as such:
* Excel* obj = new Excel(H, W);
* obj->set(r,c,v);
* int param_2 = obj->get(r,c);
* int param_3 = obj->sum(r,c,strs);
*/
```
