直接按题意来一步一步走。  
具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/937.reorder_log_files)    

```
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>content;
        for(auto l : logs)
        {
            int i=0;
            while(l[i]!=' ')
                i++;
            string tmp=l.substr(i+1);
            content.push_back(tmp);
        }
       
        int second=logs.size()-1;
         int start=second-1;
        
        while(start>=0)
        {
            if(content[second][0] >='a' && content[second][0]<= 'z')         
            {
                if(content[start][0]>='0' && content[start][0] <= '9' )
                {
                    string t=content[start];
                    content[start]=content[second];
                    content[second]=t;
                     t=logs[start];
                    logs[start]=logs[second];
                    logs[second]=t;
                }
                else
                    start--;
                
            }
            else 
            {
                second--;
                if(second ==start)
                    start--;
            }
            
        }
        
        for(int i=0;i<content.size();i++)
            
        {
            if(content[i][0]>='0' && content[i][0]<='9' ) 
            {
                start=i;
                break;
            }
            }
        for(int i=0;i<start;i++)
            for(int j=i+1;j<start;j++)
            {
                if(content[i]>content[j])
                {
                    string t=content[i];
                content[i]=content[j];
                content[j] = t; 
                t=logs[i];
                logs[i]=logs[j];
                logs[j] = t; 
                }
                else if(content[i]==content[j])
                {
                    if(logs[i]>logs[j])
                    {
               string t=content[i];
                content[i]=content[j];
                content[j] = t; 
                t=logs[i];
                logs[i]=logs[j];
                logs[j] = t; 
                    }
                }
            }
        return logs;
    }
};
```

> 执行用时 : 20 ms, 在Reorder Log Files的C++提交中击败了96.79% 的用户  
内存消耗 : 16.3 MB, 在Reorder Log Files的C++提交中击败了7.50% 的用户