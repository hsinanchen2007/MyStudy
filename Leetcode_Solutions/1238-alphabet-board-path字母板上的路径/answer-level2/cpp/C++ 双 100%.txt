![Screenshot from 2019-11-14 22-52-01.png](https://pic.leetcode-cn.com/78e6f8a9077f27131a30c1a5ef19134dcddde55155d04328a26f5518844e51d5-Screenshot%20from%202019-11-14%2022-52-01.png)

```c++
class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> position(26);
        for(int i = 0; i < 26; i++){
            position[i] = {i / 5, i % 5};
        }
        pair<int, int> currentPosition = {0, 0};
        string result;
        int restCount = target.size();
        for(auto c: target){
            auto nextPosition = position[c - 'a'];
            if(nextPosition.first != currentPosition.first &&
                    nextPosition.second != currentPosition.second &&
                    currentPosition.first == 5){
                result += "U";
                currentPosition.first--;
            }
            while(nextPosition.second < currentPosition.second){
                result += "L";
                currentPosition.second--;
            }
            while(nextPosition.second > currentPosition.second){
                result += "R";
                currentPosition.second++;
            }
            while(nextPosition.first < currentPosition.first){
                result += "U";
                currentPosition.first--;
            }
            while(nextPosition.first > currentPosition.first){
                result += "D";
                currentPosition.first++;
            }
            result += "!";
        }
        return result;
    }
};
```
