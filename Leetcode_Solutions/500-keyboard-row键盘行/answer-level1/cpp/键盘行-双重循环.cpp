flag = 1表示在第一行；
flag = 2第二行；
flag = 3第三行；
flag在123之间改变，表明不在同一行，结束当前单词；   
 vector<string> findWords(vector<string>& words) {
        set<char> dic1 = {'Q','W','E','R','T','Y','U','I','O','P'};
        set<char> dic2 = {'A','S','D','F','G','H','J','K','L'};
        set<char> dic3 = {'Z','X','C','V','B','N','M'};
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++)
        {
            //transform(words[i].begin(),words[i].end(),words[i].begin(),::toupper);
            int flag = 0;
            for(int j = 0; j < words[i].size(); j++)
            {
                if(dic1.find(toupper(words[i][j])) != dic1.end() && flag != 2 && flag != 3 )
                    flag = 1;
                else if(dic2.find(toupper(words[i][j])) != dic2.end() && flag != 1 && flag != 3)
                    flag = 2;
                else if(dic3.find(toupper(words[i][j])) != dic3.end() && flag != 1 && flag != 2)
                    flag = 3;
                else
                {
                    flag = 0;
                    break;
                }
            }
            if(flag != 0)
                ans.push_back(words[i]);
        }

        return ans;