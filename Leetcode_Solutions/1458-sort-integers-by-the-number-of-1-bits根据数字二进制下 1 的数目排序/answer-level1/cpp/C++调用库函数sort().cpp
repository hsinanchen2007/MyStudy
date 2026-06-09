通过改写C++STL函数中排序函数sort的规则即可。
注意：sort默认是升序。
```
 bool cmp ( int a, int b ){
        int i,j; i = 0; j = 0;
        int a0 =a; int b0 = b;

        while( a != 0 && a != 1){
            if( a%2 == 1 ) i++;
            a /= 2;
        }
        if ( a == 1 ) ++i;

        while( b != 0 && b != 1){
            if( b%2 == 1 ) j++;
            b /= 2;
        }
        if ( b == 1 ) ++j;

        //if( i>j ) return false;
        if ( (i == j && a0 > b0) || i > j ) return false;
        return true;

    }

class Solution {
public:

    vector<int> sortByBits(vector<int>& arr) {
        sort( arr.begin() , arr.end() , cmp );
        return arr;
    }
};
```
