![image.png](https://pic.leetcode-cn.com/c438244ad1919df3b2c1d22e2f0c2c5d2e2fc7c993ecac7aca25a3065825868f-image.png)

//遍历字符数组是否在同一键盘行;

```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<char> vct_first{'q','w','e','r','t','y','u','i','o','p'};
		vector<char> vct_second{'a','s','d','f','g','h','j','k','l'};
		vector<char> vct_third{'z','x','c','v','b','n','m'};
		
		vector<string> vct_str;
		for(int i = 0; i < words.size(); i++)
		{
            string strTemp = words[i];
            std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);

			int nFlag = 0;
            int n = 0;
			for(int j = 0; j < words[i].size(); j++)
			{
				if(count(vct_first.begin(), vct_first.end(), words[i][j]) != 0)
				{
					nFlag += 1;
                    n = 0;
				}
				else if(count(vct_second.begin(), vct_second.end(), words[i][j]) != 0)
				{
					nFlag += 2;
                    n = 1;
				}
				else if(count(vct_third.begin(), vct_third.end(), words[i][j]) != 0)
				{
					nFlag += 3;
                    n = 2;
				}
			}
			
			if((nFlag == words[i].length() && n == 0) || (nFlag == words[i].length()*2 && n == 1) || (nFlag == words[i].length()*3 && n == 2))
			{
				vct_str.push_back(strTemp);
			}
		}
		
		return vct_str;
    }
};
```
