    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<int> a, b;
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            if (words[i] == word1) {
                a.push_back(i);
            } else if (words[i] == word2) {
                b.push_back(i);
            }
        }
        int sizeA = a.size();
        int minNum = 1000000;
        if (word1 == word2) {
            for (int i = 1; i < sizeA; ++i) {
                minNum = min(minNum, abs(a[i] - a[i - 1]));
            }
            return minNum;
        }
        int sizeB = b.size();
        for (int i = 0; i < sizeA; ++i) {
            for (int j = 0; j < sizeB; ++j) {
                minNum = min(minNum, abs(b[j] - a[i]));
                if (b[j] > a[i]) {
                    break;
                }
            }
        }
        return minNum;
    }