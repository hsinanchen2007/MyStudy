### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i,j,carry;
        string p="1";
        i=num1.size();
        j=num2.size();
        carry=0;
            if(i>=j)
            {while(j>0)
                {if(carry==1)       {num1[i-1]=num1[i-1]+1;carry=0;}   
                if(num1[i-1]>57)  {num1[i-1]=num1[i-1]-10;carry=1;}
                num1[i-1]=num1[i-1]+num2[j-1]-48;
                if(num1[i-1]>57)  {num1[i-1]=num1[i-1]-10;carry=1;}
                j--;i--;
                }
                cout<<num1;
            while(i>0) 
                {if(carry==1)       {num1[i-1]=num1[i-1]+1;carry=0;}   
                if(num1[i-1]>57)  {num1[i-1]=num1[i-1]-10;carry=1;}
                i--;
                }
                if(carry==1)    {p+=num1;return p;}
                else    return num1;
            }
            else
            {while(i>0)
                {if(carry==1)       {num2[j-1]=num2[j-1]+1;carry=0;}   
                if(num2[j-1]>57)  {num2[j-1]=num2[j-1]-10;carry=1;}
                num2[j-1]=num2[j-1]+num1[i-1]-48;
                if(num2[j-1]>57)  {num2[j-1]=num2[j-1]-10;carry=1;}
                j--;i--;
                }
            while(j>0) 
                {if(carry==1)       {num2[j-1]=num2[j-1]+1;carry=0;}   
                if(num2[j-1]>57)  {num2[j-1]=num2[j-1]-10;carry=1;}
                j--;
                }
                if(carry==1)    {p+=num2;return p;}
                else    return num2;
            }




    }
};
```