思路：首先找到words里的第一个单词的所有位置，然后从这个单词开始，往左或者往右添加words里的单词，看string里有没有相等的。
```
class Solution
{
public:
    vector<int> findSubstring(string s,vector<string>& words)
    {
        if(0 == s.length() ) return {};
        if(0 == words.size() ) return {};
        int lens=s.length(),lenws=words.size(),lw=0,rep=0;
        string word{words.at(0)};
        lw = word.length();
        rep = lw;
        for(int i = 1; i < lw; i++)
        {
            if(word.at(i) == word.at(0) )
            {
                rep = i;
                break;
            }
        }
        int j = 0, k = 0;
        vector<pair<int,int> > vp0;
        // 寻找words里第一个单词在string中的位置
        while(j < lens)
        {
            while(s.at(j) == word.at(k) )
            {
                if( k + 1 >= lw)
                {
                    vp0.push_back( {j-k,j} );
                    k = -1;
                }
                if( j + 1 >= lens ) break;
                j++;
                k++;
            }
            if(k != 0)
            {
                j = j - k + rep;
                k = 0;
            }
            else j++;
        }

        if(vp0.size() == 0) return {};
        vector<pair<int,int> > vp{vp0};
        vector<unordered_set<int> > vus(vp.size() );
        for(int i = 0; i < vp.size(); i++)
        {
            vus.at(i).insert(0);
        }
        // 往左往右寻找，是否有剩下的单词
        for(int i = 1; i < lenws; i++)
        {
            vector<pair<int,int> > vptmp;
            vector<unordered_set<int> > lustmp;
            for(int m = 0; m < vp.size(); m++)
            {
                for(int n = 1; n < lenws; n++)
                {
                    if( vus.at(m).find(n) != vus.at(m).end() ) continue;
                    int lengw = words.at(n).size();
                    if( (vp.at(m).first-lengw>=0) && (s.substr(vp.at(m).first-lengw,lengw)==(words.at(n)) ) )
                    {
                        vptmp.push_back( {vp.at(m).first-lengw,vp.at(m).second} );
                        unordered_set<int> ustmp{vus.at(m) };
                        ustmp.insert(n);
                        lustmp.push_back( ustmp );
                    }
                    if( (vp.at(m).second+lengw+1<s.length()) && (s.substr(vp.at(m).second+1,lengw)==(words.at(n)) ) )
                    {
                        vptmp.push_back( {vp.at(m).first,vp.at(m).second+lengw} );
                        unordered_set<int> ustmp{vus.at(m) };
                        ustmp.insert(n);
                        lustmp.push_back( ustmp );
                    }
                }
            }
            vp = vptmp;
            vus = lustmp;
        }
        vector<int> vt;
        unordered_set<int> uns;
        for(int i = 0; i < vp.size(); i++)
        {
            if(uns.find(vp.at(i).first) != uns.end() ) continue;
            uns.insert(vp.at(i).first);
            vt.push_back(vp.at(i).first );
        }
        return vt;
    }
};
```
