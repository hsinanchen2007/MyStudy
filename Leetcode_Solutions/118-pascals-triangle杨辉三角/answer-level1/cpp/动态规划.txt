可能都写得差不多。。。
第二个for循环把之前的temp.size()-1改成了i运行时间从20%提高到100%  

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(temp);
        }
        return result;
    }