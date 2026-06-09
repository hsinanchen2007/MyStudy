### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {

        if ( num1 == "" || num2 == "" ) {
            return "";
        }

        if ( num1 == "0" || num2 == "0" ) {
            return num1 == "0" ? num2 : num1;
        }

        //用三个栈就解决了
        stack<char> snum1;
        stack<char> snum2;
        stack<char> sret;

        for ( int i = 0; i < num1.size(); ++i ) {
            snum1.push( num1[i] );
        }

        for ( int i = 0; i < num2.size(); ++i ) {
            snum2.push( num2[i] );
        }

        bool bextra = false;
        while( !snum1.empty() && !snum2.empty() ) {
            char c1 = snum1.top();
            char c2 = snum2.top();
            int ret = c1 - '0' + c2 - '0';
            if ( bextra ) {
                ret += 1;     //进位操作
                bextra = false;
            } 

            if ( ret >= 10 ) {
                ret -= 10;
                bextra = true;
            }
           
            sret.push( ( '0' + ret ) );
            snum1.pop();
            snum2.pop();
        }

        auto func = [&sret]( stack<char>& source, bool& bextra ) mutable {
            while( !source.empty() ) {
                int c = source.top() - '0';
                if ( bextra ) {
                    c += 1;
                    bextra = false;
                }
                if ( c >= 10 ) {
                    c -= 10;
                    bextra = true;
                }
                sret.push( '0' + c );
                source.pop();
            } 
        };

        func( snum1, bextra );
        func( snum2, bextra );

        string ret = "";

        if ( bextra ) {
            ret = "1";
        }

        while( !sret.empty() ) {
            ret += sret.top();
            sret.pop();
        }
    
        return ret;

    }
};
```