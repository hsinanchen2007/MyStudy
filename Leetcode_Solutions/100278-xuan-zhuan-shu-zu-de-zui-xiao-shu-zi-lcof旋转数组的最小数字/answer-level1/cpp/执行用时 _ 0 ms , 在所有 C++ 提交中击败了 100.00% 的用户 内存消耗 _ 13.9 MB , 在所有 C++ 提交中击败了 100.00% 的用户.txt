### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
       int n=numbers.size()-1;int sum=0;
       if(n==0)
            sum=numbers[0];
        else{
       for(int i=0;i<n;i++)
       {
           if(numbers[i]>numbers[i+1])
           {
               sum=numbers[i+1];
               break;
           }
           else{
                sum=numbers[0];}
       }}
       return sum;
    }
};
```