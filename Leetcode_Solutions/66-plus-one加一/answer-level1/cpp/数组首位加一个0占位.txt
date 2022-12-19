### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> newNum;
        // cout<<digits.zize()<<endl;
        //第一个位置补0
        digits.insert(digits.begin(),0);
        int len =digits.size();

digits[len-1]+=1;
       for(int i=len-1;i>0;i--)
       {
           int temp=digits[i];
           if(temp>=10)
           {

               digits[i]=temp%10;
               digits[i-1]+=1;
               if(digits[i-1]+1<10)
               {
                   break;
               }
           }
           else
           {
    
               digits[i]=temp;
        
           }

       } 
            if(digits[0]==0)
          digits.erase(digits.begin()+0);
        //   for(int i=0;i<digits.size();i++)
        //   {
        // cout<<digits[i]<<"  ";
        //   }
     

         return digits;
    }
};
```