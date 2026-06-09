``` c++
int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<pair<int, char>>> path(len1 + 1, vector<pair<int, char>>(len2 + 1, pair<int, char>({ 0, '*' })));

    for (int i = 0; i < len1 + 1; i++) path[i][0] = { i, 'd' }; // 对word1执行删除
    for (int i = 0; i < len2 + 1; i++) path[0][i] = { i, 'i' }; // 对word1执行插入

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i-1] == word2[j-1]) { // 相同则跳过
                path[i][j].first = path[i - 1][j - 1].first;
                path[i][j].second = 's';
            }
            else {
                // 对word1执行替换 
                int min = path[i - 1][j - 1].first + 1;
                path[i][j].first = min;
                path[i][j].second = 'e';

                // 对word1执行插入（插入和word2的j-1一样的字符），word2的指针由j-1移向j
                if (path[i][j - 1].first + 1 < min) {
                    min = path[i][j - 1].first + 1;
                    path[i][j].first = min;
                    path[i][j].second = 'i';
                }

                // 对word1执行删除，word1的指针由i-1移向i
                if (path[i - 1][j].first + 1 < min) {
                    min = path[i - 1][j].first + 1;
                    path[i][j].first = min;
                    path[i][j].second = 'd';
                }
            }
        }
    }
    // 回溯操作
    int i = len1, j = len2;
    stack<char> ops;
    char op;
    while (i != 0 || j != 0) {
        op = path[i][j].second;
        ops.push(op);
        if (op == 'i') j--;
        else if (op == 'd') i--;
        else { i--; j--; }
    }

    // 按照操作从前向后做一遍
    i = 0;
    j = 0;
    queue<string> states;
    string state = word1;
    states.push(state);
    while (ops.empty() == false) {
        switch (ops.top()) {
        case 's':
            break;
        case 'd':
            state = state.substr(0, i) + state.substr(i + 1, state.size());
            j--;
            break;
        case 'i':
            state = state.substr(0, i) + word2[j] + state.substr(i, state.size());
            break;
        case 'e':
            state[i] = word2[j];
        }
        i++;
        j++;
        ops.pop();
        states.push(state);
    }
    // 打印步骤
    while (states.empty() == false) {
        cout << states.front();
        states.pop();
        if (states.empty() == false) cout << " -> ";
    }
    return path[len1][len2].first;
}
```
