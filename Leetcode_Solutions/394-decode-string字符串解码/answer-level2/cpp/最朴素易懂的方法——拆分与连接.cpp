看到这道题就自己尝试拆了两个例子，然后就按照大脑最直接的思维对有[]的地方进行拆分，然后再把后面的字符串连接上即可，思路很简单。

class Solution {
public:
    string decodeString(string input) {
        int locationLeft = 0;
        int locationRight = 0;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '[') {
                locationLeft = i;
                continue;
            }
            if (input[i] == ']') {
                locationRight = i;
                int count = 0;
                string numStr = "";
                string newInput = "";
                while (locationLeft - 1 + count >= 0 && input[locationLeft - 1 + count] >= '0' && input[locationLeft - 1 + count] <= '9' ) {
                    numStr += input[locationLeft - 1 + count--];
                }
                if (locationLeft > 1) {
                    newInput = input.substr(0, locationLeft + count);
                }
                reverse(numStr.begin(), numStr.end());
                for (int i = 0; i < stoi(numStr); ++i) {
                    newInput += input.substr(locationLeft + 1, locationRight - locationLeft - 1);
                }
                if (locationRight < input.size()) {
                    newInput += input.substr(locationRight + 1, input.size() - locationRight - 1);
                }
                input = newInput;
                i = -1;
            }
        }
        return input;
    }
};