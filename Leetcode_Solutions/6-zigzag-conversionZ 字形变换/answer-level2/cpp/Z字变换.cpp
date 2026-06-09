执行用时 :12 ms, 在所有 C++ 提交中击败了92.24%的用户
内存消耗 :10.3 MB, 在所有 C++ 提交中击败了86.71%的用户
按Z字型的规律走就可以了，第2到numRows-1行会有2个数，每两个数的下标之和会为2*numRows-2。
```
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int len = s.size();
        int index = 0;
        int index2 = 0;
        if(len ==1) return s;
        if(numRows == 1) return s;
        
        while(index<len)
        {
            ans+=s[index];
            index=index+(2*numRows-2);
    
            
        }
        for(int i = 2;i<numRows;i++)
        {
            index = i-1;
            index2 = 2*numRows-2-index;
            while(index<len||index2<len)
            {
                ans+=s[index];
                if(index2<len)
                ans+=s[index2];   
                index+=(2*numRows-2);
                
                index2+=(2*numRows-2);
            }

        }
        index = numRows-1;
        while(index<len)
        {
            ans+=s[index];
            index +=(2*numRows-2);
        }
        return ans;
    }
};
```
数据有毒。数据有
"A" 1
和
"AB" 1
这样的输入，-_-||