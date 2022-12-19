### 解题思路
这题我之前一直都没有通过，原因在于我一直是通过paths点对的数量来决定最终各个花园的植花种类，
一直没有用到N，后来参考别人解法才发现最后返回的数组应该是有N个元素的，
于是我一开始就定义了vector<int> res(N,1);并在后面对它进行修改。
我分四种情况进行讨论，避免相邻的花园种植同样的花。
没有相邻情况的就是默认的种植第一种花了。

我的思路应当灰常好理解。

### 代码

```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N,1);
        if(paths.size()==0) return res;
        map<int,vector<int>> data;//存储花园编号，该花园种的花，与花园连接的公园编号。后者迁就前者即花色相同时改变后者编号
        //即 data[int 当前花园编号，vector<int>[当前花园种植的花编号，相邻花园1，相邻花园2].最多只有两个相邻花园。
        for( int i=0; i<paths.size();++i ){
            if( data[ paths[i][0] ].size()==0 && data[ paths[i][1] ].size()==0 ) {
                data[ paths[i][0] ].push_back(1); //存储花编号，因为之前从没有出现该花园，且当前与其配对的花园也没出现过
                data[ paths[i][1] ].push_back(2); //存储花编号，先不与前一个冲突即可，后面再行调整
                data[ paths[i][0] ].push_back(paths[i][1]); //当前与其相邻的花园，注意这个花园花编号不与前者相同 
                data[ paths[i][1] ].push_back(paths[i][0]);
                
             }
             //传入的邻接花园有一个已经存在，一个不存在。不存在的应避免与已存在的花色冲突
             else if( data[ paths[i][0] ].size()==0 && data[ paths[i][1] ].size()!=0 ){
                for(int j=1;j<=4;++j){ 
                    if( j!=data[ paths[i][1] ][0] ){ data[paths[i][0]].push_back(j);break; } 
                    }
                data[ paths[i][0] ].push_back(paths[i][1]);
                data[ paths[i][1] ].push_back(paths[i][0]);//添加相邻成员                    
             }

             else if( data[ paths[i][0] ].size()!=0 && data[ paths[i][1] ].size()==0 ){
               for(int j=1;j<=4;++j){ 
                    if( j!=data[ paths[i][0] ][0] ){ data[paths[i][1]].push_back(j);break;} 
                    }
                data[ paths[i][0] ].push_back(paths[i][1]);
                data[ paths[i][1] ].push_back(paths[i][0]);//添加相邻成员 
             }

             //都不等于0的情况下，即传入的邻接花园之前有安排花编号了，要判断这两种花色之前是否互相冲突了
             else if( data[ paths[i][0] ].size()!=0 && data[ paths[i][1] ].size()!=0 ){

                if( data[ paths[i][1] ][0] == data[ paths[i][0] ][0] ) {//改变后面一个的花色，且不与已有的冲突
                   if( data[ paths[i][1] ].size()==2 ){
                       for(int j=1;j<=4;++j){
                           if( j!=data[ paths[i][0] ][0]&&j!=data[data[ paths[i][1] ][1] ][0] ) {data[ paths[i][1] ][0]=j;break;}
                           }
                   }//有1个已知成员
                   else if( data[ paths[i][1] ].size()==3 ){
                        for(int j=1;j<=4;++j){ 
                           if( j!=data[ paths[i][0] ][0]&& j!=data[data[ paths[i][1] ][1] ][0] &&j!=data[data[ paths[i][1] ][2] ][0])                                {data[ paths[i][1] ][0]=j;break;}
                           }
                   }//至多只能有2个已知成员
                }

                //如果两个的花色值不相等，直接互相加入对方相邻接成员列表即可
                data[ paths[i][0] ].push_back(paths[i][1]);
                data[ paths[i][1] ].push_back(paths[i][0]);//添加相邻成员
             }
        }
        map<int,vector<int>>::iterator itr= data.begin();
        while(itr!=data.end()){
            res[itr->first-1]=itr->second[0];
            ++itr;
        }

        return res;
    }
};
```