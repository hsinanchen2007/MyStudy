### 解题思路
比较简单，复杂一点的就是类似999的情况，用count统计一下9的数目等于数组长度，在数组前插1

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length=digits.size();
        if(digits[length-1]==9&&digits[0]!=9){
            for(int i=length-1;i>=0;--i)
            {
                if(digits[i]==9){digits[i]=0;}
                else{
                    digits[i]++;
                    break;
                }

            }
            return digits;
        }
        if(digits[length-1]==9&&digits[0]==9){
            int count=0;
            for(int i=length-1;i>=0;--i)
            {
                if(digits[i]==9){++count;digits[i]=0;}
                else{
                    digits[i]++;
                    break;
                }
                if(count==length){
                    digits.insert(digits.begin(),1);
                }

            }
            return digits;
        }
        digits[length-1]++;
        return digits;

    }
};
```