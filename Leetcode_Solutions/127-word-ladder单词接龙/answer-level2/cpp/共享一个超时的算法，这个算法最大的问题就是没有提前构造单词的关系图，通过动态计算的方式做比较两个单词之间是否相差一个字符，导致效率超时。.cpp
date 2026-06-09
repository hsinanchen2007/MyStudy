 bool justOneCharDiff(string a, string b) {
        int cnt = 0;
        if (a.length() != b.length()){
            return false;
        }

        for (int i = 0; i < a.length();i++) {
            if (a.at(i) != b.at(i)){
                cnt++;
            }
        }

        return cnt == 1 ? true : false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> res;
        int pathlen = 0;
        bool *mark = new bool[wordList.size() + 1];
        memset(mark,0,sizeof(bool)*(wordList.size() + 1));
        res.push(beginWord);
        
        while (!res.empty())
        {
            int size = res.size();
            pathlen++;

            while (size > 0) {
                size--;
                string word = res.front();
                res.pop();

                for (int i = 0; i < wordList.size();i++) {
                    if (!justOneCharDiff(word, wordList[i])) {
                        continue;
                    }

                    if (endWord.compare(wordList[i]) == 0) {
                        return pathlen+1;
                    }

                    if (mark[i]){
                        continue;
                    }
                    
                    res.push(wordList[i]);
                    mark[i] = true;
                }
            }

        }

        return 0;
    }