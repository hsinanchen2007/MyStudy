观察发现，对于输入字符串给定行数，当行数大于等于3时，会有中间↗的出现，出现的字符个数为numRows-2（即不算第一行和最后一行），所以我们对于numRows>=3的情况，可以numRows个字符一组，numRows-2个字符一组，将输入字符串分割，插入vector divide中。

然后通过for循环，对于每一行进行遍历，在每一个devide[i]中选择相应的字符，加入结果。观察可知，当numRows>=3时，devide[i]的下标i如果是偶数，就对应numRows个字符一组的情况，如果是奇数就对应numRows-2个字符一组的情况，前者就正常根据每一行的索引加入对应字符，后者加入的字符是与正常索引相反的顺序（从第2行开始，因为从0开始遍历，第二行的索引row是1，可以观察到，对于↗中，加入第二行的字符索引是numRows-2-1-（row+1））。

```
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> divide;
        int n = s.size();
        // 划分，numRows 1组，numRows-2 1组，间隔插入
        for(int i=0;i<s.size();){
            int count;
            if(i+numRows-1 <= n-1){
                count = numRows;
                divide.push_back(s.substr(i, count));
                i = i + count;
            }else{
                count = n-1-i+1;
                if(count != 0){
                    divide.push_back(s.substr(i, count));
                    i = i + count;
                }
            }
            if(numRows >= 3){
                if(i+numRows-2-1 <= n-1){
                    count = numRows-2;
                    divide.push_back(s.substr(i, count));
                    i = i + count;
                }else{
                    count = n-1-i+1;
                    if(count != 0){
                        divide.push_back(s.substr(i, count));
                        i = i + count;
                    }
                }
            } 
        }

        // for(auto i:divide){
        //     cout<< i<<endl;
        // }
        string temp = "";

        for(int row=0;row<numRows;row++){
            // 第几行
            for(int i=0;i<divide.size();i++){
                if(numRows >=3){
                    if(i % 2 == 0){// 0 2 4 是numRows 的组，|↗|中的|
                        if(row <= divide[i].size()-1){
                            temp += divide[i].substr(row,1);
                        }
                    }else{// 1 3 5 是numRows-2 的组 |↗|中的↗
                        if(row == 0 || row == numRows-1){
                            continue;
                        }else{
                            // 不是第一行也不是最后一行
                            if(numRows-2-1-(row-1) <= divide[i].size()-1){
                                temp += divide[i].substr(numRows-2-1-(row-1), 1);
                            }
                        }
                    }
                }else{
                    // 如果没有↗层，那么就都是|层
                    if(row <= divide[i].size()-1){
                        temp += divide[i].substr(row,1);
                    }
                }
                
            }

        }
        return temp;
    }
};
```
