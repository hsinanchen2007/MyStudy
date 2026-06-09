### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {

        int sum=0;

        for(auto cur : A)
        {
            sum+=cur;
        }
        cout<<"sum:"<<sum<<endl;
        if(sum%3!=0)
        return false;
        else{
            int i=0;
            int temp=0;
            while(i<A.size())
            {
                temp+=A[i];
                if(temp==sum/3)
                break;
                ++i;
            }
            cout<<"i:"<<i<<endl;
            if(temp!=sum/3)
            return false;
            else{
                int j=i+1;
                temp=0;
                while(j+1<A.size())
                {
                    temp+=A[j];
                    if(temp==sum/3)
                    return true;
                    ++j;
                }
                cout<<"j:"<<j-1<<endl;
                
                
            }
        }
        return false;

    }
};
```