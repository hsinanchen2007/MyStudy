//n个数中取k个数
//参考：https://blog.csdn.net/hf19931101/article/details/79452799  
递归写法：

```
class Solution {
public:
  
    vector<string> results;
    int minMap[10] = {8,4,2,1,32,16,8,4,2,1};  
    void dfs(int pos, int cnt, int n, int k,bool visited[]) {
        //已标记了k个数，输出结果
        if (cnt == k) {
            int tmpMin = 0;
            int tmpHour =0;
            for (int i = 0; i < 4; i++){
                if (visited[i]){
                    tmpHour+=minMap[i];
                     if(tmpHour> 11){
                         return;
                     }
                };
            }
            for (int i = 4; i < 10; i++){
                if (visited[i]){
                    tmpMin+=minMap[i];
                     if(tmpMin> 59){
                         return;
                     }
                };
            }
            

            if(tmpMin<10){
                results.push_back(to_string(tmpHour)+":0"+to_string(tmpMin));    
            }else{
                results.push_back(to_string(tmpHour)+":"+to_string(tmpMin));    
            }
            return;
        }

        //处理到最后一个数，直接返回
        if (pos == n) return;

        //如果a[pos]没有被选中
        if (!visited[pos]) {
            //选中a[pos]
            visited[pos] = true;
            //处理在子串a[pos+1, n-1]中取出k-1个数的子问题
            dfs(pos + 1, cnt + 1, n, k,visited);
            //回溯
            visited[pos] = false;   
        }
        //处理在子串a[pos+1, n-1]中取出k个数的问题
        dfs(pos + 1, cnt, n, k, visited);
    }

    vector<string> readBinaryWatch(int num) {
        if(num == 0){
            return vector<string>(1,"0:00");
        }
        int i, n, k;
        n=10;
        k=num;
        
       
        bool *visited = new bool[n];
        for (i = 0; i < n; i++)
        {
            
            visited[i] = false;
        }
        dfs(0, 0, n, k, visited);
       
        delete[] visited;
            
        return results;
    }
};
```

非递归写法：
```
class Solution {
public:
    
    int minMap[10]{8,4,2,1,32,16,8,4,2,1};
    void convertStr(vector<string>& result,vector<bool>& visited){
        int tmpMin = 0;
        int tmpHour =0;
        for (int i = 0; i < 4; i++){
            if (visited[i]){
                tmpHour+=minMap[i];
                if(tmpHour> 11){
                    return;
                }
            };
        }
        for (int i = 4; i < 10; i++){
            if (visited[i]){
                tmpMin+=minMap[i];
                if(tmpMin> 59){
                    return;
                }
            };
        }
        

        if(tmpMin<10){
            result.push_back(to_string(tmpHour)+":0"+to_string(tmpMin));    
        }else{
            result.push_back(to_string(tmpHour)+":"+to_string(tmpMin));    
        }
    }
    vector<string> dfs(int* arr,int n,int k){
        vector<string> result;
        if(k==0){
            result.push_back("0:00");
            return result;
        }
        vector<bool> visited(n,0);
        stack<int> stack;
        stack.push(0);
        int cnt = 0;
        while(!stack.empty()){
            int tmpIndex = stack.top();
            bool popFlag = false;
            if(visited[tmpIndex]){
               popFlag = 1; 
            }else{
                cnt++;
                visited[tmpIndex]=1;
                if(cnt == k){
                    convertStr(result,visited);
                    popFlag = 1;
                }
            }

            if(popFlag){
                cnt--;
                visited[tmpIndex]=0;
                stack.pop();
            }
            if(tmpIndex+1 < n){
                stack.push(tmpIndex+1);
            }
        }
        return result;

    }
    vector<string> readBinaryWatch(int num) {
        return dfs(minMap,10,num);
    }
};
```
