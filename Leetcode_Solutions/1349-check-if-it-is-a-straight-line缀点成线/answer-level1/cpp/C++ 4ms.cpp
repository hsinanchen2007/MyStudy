使用求斜率的方法来进行题解就好。首先记录第一个和第二个点的斜率，然后用遍历的方法从第二、三个点开始，每两个点进行一次斜率的计算，和最开始的斜率进行比较，如果不一致，直接返回。这样的话，如果数据够好，时间复杂度应该会降低到O(1)。最慢可能也就是O(n).

bool checkStraightLine(vector<vector<int> > & coordinates) {
    float k = 0.0, tmp_k = 0.0;
    if((coordinates[1][0] - coordinates[0][0]) == 0)
        k = 1 << 31;
    else
        k = (float)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
    tmp_k = k;

    for(int i = 2; i < coordinates.size(); ++i)
    {
        if((coordinates[i][0] - coordinates[i-1][0]) == 0)
            k = 1 << 31;
        else
            k = (float)(coordinates[i][1] - coordinates[i-1][1]) / (coordinates[i][0] - coordinates[i-1][0]);

        if(k != tmp_k)
            return false;
    }

    return true;
}