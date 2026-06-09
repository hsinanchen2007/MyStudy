### 解题思路
此处撰写解题思路

### 代码

```cpp
template<class T>
ostream & operator<<(ostream & os , vector<vector<T>> vec){
    for( auto line : vec){
        for (auto cell :line){
            os<<cell<<"\t";
        }
        cout<<endl;
    }
    return os;
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1= word1.size() , l2 = word2.size();
        vector<vector<int>> mat(l1+1,vector<int>(l2+1,0)) ; 
        // initial the boundary condition
        for( int i = 0 ; i <= l1 ; ++i ) mat[i][0]=i;
        for( int i = 0 ; i <= l2 ; ++i ) mat[0][i]=i;
        for( int i = 1 ; i <= l1 ; ++i ){
            for( int j = 1 ; j <= l2 ; ++j ){
                if(word1[i-1]==word2[j-1]){
                    mat[i][j]= 1+min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]-1});
                }else{
                    mat[i][j]= 1+min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]});
                    //if ( i==1 && j ==1 ) cout<< mat[1][1]<<endl;
                }
            }
        }
        return mat[l1][l2];
    }
};
```