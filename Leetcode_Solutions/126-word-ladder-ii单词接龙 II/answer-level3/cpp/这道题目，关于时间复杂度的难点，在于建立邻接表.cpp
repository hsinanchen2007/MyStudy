### 解题思路

建表，对字符串进行对比的复杂度是O(m * n^2)
而bfs或者dfs，实际只是O(n)
所以很没意思= =


### 代码

```cpp
class Solution {
public:
    int bfsD(int n,int startI, int endI, int* sind, int* eind, vector<vector<int>>& dis)
    {
        int tp;
        int index;
        bool find;
        int result;
        queue<int> vstp;
        queue<int> vetp;
        vstp.push(startI);
        vetp.push(endI);
        sind[startI] = 1;
        eind[endI] = 1;
        index = 1;
        find = false;
        result = 0;
        while(vstp.size() > 0 || vetp.size() > 0)
        {
            //cout << index << endl;
            while(vstp.size() > 0)
            {
                tp = vstp.front();
                if(sind[tp]>index) break;
                vstp.pop();
                //cout << " " << tp;

                for(int j : dis[tp])
                {
                    if(sind[j] == 0)
                    {
                        vstp.push(j);
                        sind[j] = index+1;
                        if(!find && eind[j] != 0)
                        {
                            find = true;
                            result = eind[j] + index;
                        } 
                    }                  
                }
            }
            //cout << endl;
            if(find) break;

            while(vetp.size() > 0)
            {
                tp = vetp.front();
                if(eind[tp]>index) break;
                vetp.pop();
                //cout << " " << tp;

                for(int j : dis[tp])
                {
                    if(eind[j] == 0)
                    {
                        vetp.push(j);
                        eind[j] = index+1;
                        if(!find && sind[j] != 0)
                        {
                            find = true;
                            result = sind[j] + index;
                        } 
                    }                   
                }
            }
            //cout <<endl;
            if(find) break;  
            ++ index;          
        }
        return result;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int tl;
        int tp;
        int wlen;
        //int* dist;
        vector<vector<int>> dist;
        //unordered_map<int,vector<int>> dist;
        int startIndex;
        int endIndex;
        vector<vector<string>> result;
        queue<vector<int>> tempre;
        vector<string> tempstr;
        vector<int> temp;
        int *startI, *endI;
        
        int minPathLen;
        int indexEnd;
        int sizetp;

        tl = wordList.size();
        wlen = wordList[0].length();
        startIndex = -1;
        endIndex = -1;
        for(int i=0;i<tl;++i)
        {
            if(startIndex == -1 && strcmp(beginWord.c_str(),wordList[i].c_str()) == 0) startIndex = i;
            if(endIndex == -1 && strcmp(endWord.c_str(),wordList[i].c_str()) == 0) endIndex = i;
            if(startIndex != -1 && endIndex != -1) break;
        }
        cout << startIndex << " " << endIndex << " " << tl << endl;
        if(endIndex==-1) return result;
        if(startIndex == -1)
        {
            wordList.push_back(beginWord);
            startIndex = tl;
            ++tl;
        }

        //dist = new int[tl*tl];
        //memset(dist,0,tl*tl*4);
        for(int i=0;i<tl;++i)
        {
            temp.clear();
            for(int j=0;j<i;++j)
            {
                tp = 0;
                for(int k=0;k<wlen;++k)
                {
                    if(wordList[i][k] != wordList[j][k]) ++tp;
                }
                if(tp == 1) 
                {
                    temp.push_back(j);
                    dist[j].push_back(i);
                }
            }
            dist.push_back(temp);
        }

        //for(int i=0;i<tl;++i)
        //{
        //    cout << i << ":";
        //    for(int j:dist[i])
        //        cout << " " << j;
        //    cout << endl;
        //}

        cout << "count end!" <<endl;

        startI = new int[tl];
        memset(startI,0,tl*4);
        endI = new int[tl];
        memset(endI,0,tl*4);
        minPathLen = bfsD(tl,startIndex,endIndex,startI,endI,dist);
        cout << minPathLen << endl;
        //cout << endl << "start bfs ans" << endl;
        //for(int i=0;i<tl;++i)
        //    if(startI[i]!=0)
        //        cout << i << " " << wordList[i] << " " << startI[i] << endl;

        //cout << endl << "end bfs ans" << endl;
        //for(int i=0;i<tl;++i)
        //    if(endI[i] != 0)
        //        cout << i << " "<< wordList[i] << " " << endI[i]  << endl;
        
        if(minPathLen == 0) return result;
        
        temp.clear();
        temp.push_back(startIndex);
        tempre.push(temp);
        while(true)
        {
            temp = tempre.front();
            sizetp = temp.size();
            if(sizetp == minPathLen) break;
            tempre.pop();
            indexEnd = temp[sizetp-1];
            for(int i : dist[indexEnd])
            {
                if(startI[i] == 1+startI[indexEnd] ||(startI[i]==0 && endI[i]+1 == endI[indexEnd] )) 
                {
                    temp.push_back(i);
                    if(temp.size()<minPathLen || i==endIndex)
                        tempre.push(temp);
                    temp.pop_back();
                }
            }
        }
        while(tempre.size()>0)
        {
            temp = tempre.front();
            tempstr.clear();
            for(int i=0;i<temp.size();++i)
            {
                tempstr.push_back(wordList[temp[i]]);
            }
            result.push_back(tempstr);
            tempre.pop();
        }

        return result;
    }
};
```