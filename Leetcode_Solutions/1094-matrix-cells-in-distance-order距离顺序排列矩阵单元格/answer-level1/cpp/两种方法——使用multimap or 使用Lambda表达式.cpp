1.使用multimap实现

```
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        
        int distance = 0;
        
        multimap<int, vector<int>> map;//因为存在距离相同的情况，所以用multimap
        vector<vector<int>> output;
        
        for(int i=0; i<R; i++){//遍历元矩阵，依次求各个单元格到指定单元格的曼哈顿距离，将坐标和距离插入multmap
            
            for(int j=0; j<C; j++){
                
                distance = abs(i-r0) + abs(j-c0);
                
                vector<int> temp;
                
                temp.push_back(i);
                temp.push_back(j);
                
                map.insert(pair<int, vector<int>>(distance, temp));
                

            }
        }
        
        multimap<int, vector<int>>::iterator i;

        for(i=map.begin();i!=map.end();i++){//遍历multmap输出答案
            
            output.push_back((*i).second);
        }

        
        return output;
    }
};
```

2，先录入再排序

```
class Solution {
public:
    

    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        
        int distance = 0;
        
        vector<vector<int>> output;
        
        for(int i=0; i<R; i++){//遍历元矩阵，将坐标插入容器
            
            for(int j=0; j<C; j++){
                
                distance = abs(i-r0) + abs(j-c0);
                
                output.push_back({i,j}); 
            }
        }
        
        sort(output.begin(), output.end(), [&](vector<int>& A, vector<int>& B){return(abs(A[0]-r0) + abs(A[1]-c0) < abs(B[0]-r0) + abs(B[1]-c0));});//按曼哈顿距离排序 这里的sort用到了Lambda表达式
        //[&]表示函数体内可以使用 Lambda 所在范围内所有可见的局部变量，并且是引用传递方式


        
        return output;
    }
};
```
