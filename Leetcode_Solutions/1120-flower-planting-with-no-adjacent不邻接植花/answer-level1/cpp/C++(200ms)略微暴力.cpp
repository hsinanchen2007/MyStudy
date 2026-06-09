```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        for(int i=0;i<paths.size();i++)//使paths[i][0]始终比paths[i][1]小
            if(paths[i][0]>paths[i][1])
                swap(paths[i][0],paths[i][1]);
        vector<int> a(N,0);
        while(1){
            int t=1;
            for(int i=0;i<paths.size();i++)
                if(a[paths[i][0]-1]==a[paths[i][1]-1]){
                    a[paths[i][1]-1]=a[paths[i][0]-1]+1;
                    a[paths[i][1]-1]%=4;
                    t=0;
                }
            if(t)//若上面的循环数组没有改变过则跳出
                break;
        }
        for(int i=0;i<N;i++)
            a[i]++;
        return a;
    }
};
```
