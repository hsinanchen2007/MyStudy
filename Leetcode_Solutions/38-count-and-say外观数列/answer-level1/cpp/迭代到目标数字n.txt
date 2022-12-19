
#    从1到n计算当前数字描述的上个字符串（统计字符中的重复数字，将重复字符个数和重复字符追加到表示字符串。一直遍历到数字n。）
string countAndSay(int n) {
        string res("1");
        if(n==1) return res;
        
        string str;
        for (int i = 2; i<= n; ++i){
            if (res.size() == 1){
                str.push_back('1');
                str.push_back(res[0]);
            }else{
                for(int j = 0,k=j+1;j<res.size() && k < res.size();){
                    if (res[j] != res[k]){
                        str.push_back(k-j+'0');
                        str.push_back(res[j]);
                        j=k;
                    }
                    ++k;
                    if (k == res.size()){
                        str.push_back(k-j+'0');
                        str.push_back(res[j]);
                        break;
                    }
                }
            }
            res = str;
            str.clear();
        }
        return res;
    }