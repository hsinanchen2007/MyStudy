

```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string rela[] = {"1", "2", "abc", "def", "ghi", "jkl", "mon", "pqrs", "tuv", "wxyz"};
        queue<string> rqueue;
        for (int i = 0; i < digits.length(); i++) {
            int number = digits[i] - '0';
            string str = rela[number];
            string value = "";

            int size = rqueue.size();
            if (size == 0) {
                for (int k = 0; k < str.length(); k++) {
                    rqueue.push(value + str[k]);
                }
            }
            else {                
                for (int j = 0; j < size; j++) {
                    value = rqueue.front();
                    rqueue.pop();
                    for (int k = 0; k < str.length(); k++) {
                        rqueue.push(value + str[k]);
                    }
                }
            }
        }

        int size = rqueue.size();
        for (int l = 0; l < size; l++) {
            result.push_back(rqueue.front());
            rqueue.pop();
        }

        return result;        
    }
};

```
