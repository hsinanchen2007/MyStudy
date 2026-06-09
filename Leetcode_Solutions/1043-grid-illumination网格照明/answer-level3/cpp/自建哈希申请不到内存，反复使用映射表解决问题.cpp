这个题坑太多了。第一坑，理解题意需要看英文，中文题目描述是不对的，翻译不严谨。
版本一：用一个map描述每个位置被照亮状态，key = 行号 * 边长 + 列号，每关一个灯，重算一遍照亮状态，跑到用例19就超时了，这时，边长10000；
版本二：用一个map描述每个位置被照亮次数，key = 行号 * 边长 + 列号，每关一个灯，照亮次数减一，还是只能跑到用例19；
版本三：用4个map描述每个行、列、斜线、反斜线的被照亮次数，每关一个灯，照亮次数减一，跑到用例35超时；这时，边长100000000；
版本四：把map改为hash数组，索引是行号或列号或斜线号，数组值是每个行、列、斜线、反斜线的被照亮次数，每关一个灯，照亮次数减一，跑到用例25出错，堆栈溢出，改为new也一样，也就是说申请不到这么大的空间；这时，边长100000000；
版本五：回滚到版本三，用4个map描述每个行、列、斜线、反斜线的被照亮次数，每关一个灯，照亮次数减一，再用一个map描述lamps，索引是位置号(row * N + col)，这样，不用反复扫描原lamps数组，时间复杂度降低了，终于所有用例都跑过了。

执行结果：通过
显示详情 执行用时 :584 ms, 在所有C++提交中击败了83.33%的用户
内存消耗 :113.5 MB, 在所有 C++ 提交中击败了51.35%的用户


class Solution {

private:

    unordered_map<int, int> mRow; //key是行号，范围是0~N，value表示被多少站等照亮

    unordered_map<int, int> mCol; //key是列号，范围是0~N，value表示被多少站等照亮

    unordered_map<int, int> mDiag1; //key是斜线号，范围是0~N+N-2，value表示被多少站等照亮

    unordered_map<int, int> mDiag2; //key是另一个方向的斜线号，范围是0~N+N-2，value表示被多少站等照亮



    map<long long, vector<int>> lampsMap;



    long long NN;

    vector<vector<int>> direction;



    static bool comp(const vector<int>& v1, const vector<int>& v2) 

    {

        return (v1[0] == v2[0]) ? (v1[1] <= v2[1]) : (v1[0] <= v2[0]);

    }



    int CalcDiagNo1(int row, int col)

    {

        return row + col;

    }



    int CalcDiagNo2(int row, int col)

    {

        return row + NN - 1 - col;

    }



    void Lit(vector<vector<int>>& lamps)

    {

        int n = 0;

 

        for (int i = 0; i < lamps.size(); i++) {

            n = lamps[i][0]; 

            mRow[n] += 1;

            n = lamps[i][1]; 

            mCol[n] += 1;

            n = CalcDiagNo1(lamps[i][0], lamps[i][1]); 

            mDiag1[n] += 1;

            n = CalcDiagNo2(lamps[i][0], lamps[i][1]); 

            mDiag2[n] += 1;

        }

        return;

    }



    //关一个灯

    void TurnOffOne(int row, int col)

    {

        int n = 0;

 

        mRow[row] -= 1;

        mCol[col] -= 1;

        n = CalcDiagNo1(row, col); 

        mDiag1[n] -= 1;

        n = CalcDiagNo2(row, col); 

        mDiag2[n] -= 1;

        

        return;

    }

    

    //关一个九宫格里的所有灯

    void TurnOffNine(int row, int col)

    {

        for (int i = 0; i < direction.size(); i++) {

            int r = row + direction[i][0];

            int c = col + direction[i][1];

            if (r >= 0 && r < NN && c >= 0 && c < NN) {

                long long n = r * NN + c;

                if (lampsMap.count(n)) {

                    TurnOffOne(r, c);

                    lampsMap.erase(n);

                }

            }

        }

        return;

    }

public:

    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) 

    {

        direction = 

            {

                {-1, -1}, //左上

                {-1, 0},  //上

                {-1, 1},  //右上

                {0, -1},  //左

                {0, 0},

                {0, 1},   //右

                {1, -1},  //左下               

                {1, 0},   //下

                {1, 1},   //右下    

            };



        NN = N;

        vector<int> res;



        //sort(lamps.begin(), lamps.end(), comp);

        for (int i = 0; i < lamps.size(); i++) {

            long long n = NN * lamps[i][0] + lamps[i][1];

            lampsMap[n] = lamps[i];

        }



        Lit(lamps);



        for (int i = 0; i < queries.size(); i++) {

            int row = queries[i][0];

            int col = queries[i][1];

            int n1 = CalcDiagNo1(row, col);

            int n2 = CalcDiagNo2(row, col);

            //printf("i = %d, posNo = %d, r = %d", i, posNo, m.count(posNo));

            bool state = (mRow[row] > 0) || (mCol[col] > 0) || (mDiag1[n1] > 0) || (mDiag2[n2] > 0);

            res.push_back(state);

            TurnOffNine(row, col);

        }



        return res;

    }

};