    string reverseVowels(string s) {
        set<char> tg = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            while((tg.find(s[i]) == tg.end())&&(i < j))
            {
                i++;
            }

            while((tg.find(s[j]) == tg.end())&&(i < j))
            {
                j--;
            }
            swap(s[i++], s[j--]);

        }
        return s;
    }