数组num存储的是各个位置的‘)’个数，确定数组的排序即可得到所有的解；
'(' num[0] '(' num[1] '(' num[2] '(' num[3] ... '(' num[n] 

eg: n = 4

'(' num[0] '(' num[1] '(' num[2] '(' num[3]
      0          0          0          4        =>(      (      (       ( `))))`
      0          0          1          3        =>(      (      ( `)`   ( `)))`
      0          0          2          2        =>(      (      ( `))`  ( `))`
      0          0          3          1        =>(      (      ( `)))` ( `)`
      0          1          0          3        =>(      ( `)`  (       ( `)))`
      0          1          1          2        =>(      ( `)`  ( `)`   ( `))`
      0          1          2          1        =>(      ( `)`  ( `))`  ( `)`
      0          2          0          2        =>(      ( `))` (       ( `))`
      0          2          1          1        =>(      ( `))` ( `)`   ( `)`
      1          0          0          3        =>( `)`  (      (       ( `)))`
      1          0          1          2        =>( `)`  (      ( `)`   ( `))`
      1          0          2          1        =>( `)`  (      ( `))`  ( `)`
      1          1          0          2        =>( `)`  ( `)`  (       ( `))`
      1          1          1          1        =>( `)`  ( `)`  ( `)`   ( `)`

通过数组的规律可以方便的生成每一次结果，具体见下面code；code写的不规整，但不影响理解

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了98.20%的用户

class Solution {
public:
    inline int tatal(int num[], int t)
    {
        int result = 0;
        for(int i = 0; i < t; i++)
            result += num[i];
        return result;
    }
    inline bool equal(int num[], int t)
    {
        for(int i = 0; i < t; i++)
        {
            if(num[i] != 1)
                return false;
        }
        return true;
    }
    inline string once(int num[], int t)
    {
        string temp;
        for(int i = 0; i < t; i++)
        {
            temp += '(';
            for(int j = 0; j < num[i]; j++)
            {
                temp += ')';
            }
        }
        return temp;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n <= 0)
        {
            string temp0 = "";
            result.push_back(temp0);            
            return result;
        }
        int *num = new int[n];
        for(int i = 0; i < n; i++)
            num[i] = 0;
        num[n-1] = n;
        if(n >= 1)
        {
            string temp0 = once(num, n);
            result.push_back(temp0);
        }
        if(n < 2)
        {
            delete [] num;
            return result;
        }
            
        while(true)
        {
            if(num[n-1] > 1)
            {
                num[n-1]--;
                num[n-2]++;
                string temp0 = once(num, n);
                result.push_back(temp0);
                if(equal(num, n))
                    break;
                else
                    continue;
            }
            for(int i = n - 2; i >= 0; i--)
            {
                num[i] += 1;
                if((num[i] > i + 1)||(tatal(num,i+1) > i + 1))
                {
                    num[i] = 0;
                }
                else
                {
                    break;
                }
            }   
            num[n-1] = n - tatal(num,n-2);
            string temp1 = once(num, n);
            result.push_back(temp1);
            if(equal(num, n))
                break;
        }
        
        delete [] num;
        return result;
    }
};