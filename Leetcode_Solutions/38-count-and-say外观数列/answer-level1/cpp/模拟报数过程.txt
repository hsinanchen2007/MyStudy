
执行用时 :4 ms, 在所有 cpp 提交中击败了91.21%的用户
内存消耗 :8.6 MB, 在所有 cpp 提交中击败了94.01%的用户

    string result="1",temp;
    int i,j,k;
    for(i=1;i<n;i++){
        temp="";
        for(j=0;j<result.size();j++){
            for(k=1;j<result.size()-1&&result[j]==result[j+1];j++,k++){
                ;
            }
            temp+=to_string(k);
            temp.push_back(result[j]);
        }
        result=temp;
    }
    return result;