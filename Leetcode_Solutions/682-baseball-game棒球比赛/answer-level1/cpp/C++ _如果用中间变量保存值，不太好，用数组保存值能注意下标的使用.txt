class Solution {
public:
    int calPoints(vector<string>& ops) {
        int index = 0;
        vector<int> stack;
        for (int i = 0; i < ops.size(); ++i) {
            int tmp;
            if (ops[i] == "C") {
                stack.pop_back();
                --index;
            }
            else {
                if (ops[i] == "+")tmp = stack[index - 1] + stack[index - 2];
                else if (ops[i] == "D")tmp = stack[index - 1] * 2;
                else tmp = stoi(ops[i]);
                stack.push_back(tmp);
                ++index;
            }
        }
        int res = 0;
        for (auto st : stack) res += st;

        return res;
    }
};