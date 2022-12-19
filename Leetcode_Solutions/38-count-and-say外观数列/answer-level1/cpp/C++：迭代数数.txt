思路：迭代n-1次，通过统计上一次（即第n-1个元素）字符出现的次数，然后加进字符串返回（即为第n个元素）。
```
class Solution {
public:
    string countAndSay(int n) {
        string tempStr, preStr = "1";
        int count, pointer;

        for(int i=1; i<n; i++){
            tempStr = "";
            count = 0;
            pointer = 0;

            for(int j=0; j<preStr.size(); j++){
                if(preStr[j] == preStr[pointer])
                    ++count;
                else{
                    tempStr += to_string(count);
                    tempStr += preStr[pointer];
                    pointer = j;
                    count = 1;
                }
                if(j == preStr.size()-1){
                    tempStr += to_string(count);
                    tempStr += preStr[pointer];
                }
            }
            preStr = tempStr;
        }

        return preStr;
    }
};
```
