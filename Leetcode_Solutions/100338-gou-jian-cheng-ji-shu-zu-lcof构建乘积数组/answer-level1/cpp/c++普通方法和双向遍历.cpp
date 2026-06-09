### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //普通方法
        /*int tmp;
        int multy=1;
        vector<int> arr;
        int m=1;
        for(int i=0;i<a.size();i++)
            m*=a[i];

        for(int i=0;i<a.size();i++)
        {
            tmp=a[i];
            if(tmp==1)
            {
                arr.push_back(m);
                continue;
            }

            a[i]=1;
            for(int j=0;j<a.size();j++)
                multy*=a[j];
            arr.push_back(multy);
            a[i]=tmp;
            multy=1;
        }*/
        //双向遍历
        vector<int> left;
        vector<int> right;
        vector<int> arr;
        int l=1,r=1;
        for(int i=0;i<a.size();i++)
        {
            l*=a[i];
            left.push_back(l);
            //cout<<l<<' ';
        }
        //cout<<endl;
        for(int i=a.size()-1;i>=0;i--)
        {
            r*=a[i];
            right.push_back(r);
            //cout<<r<<' ';
        }
        reverse(right.begin(),right.end());
        //cout<<endl;
        //cout<<"ok"<<endl;
        for(int i=0;i<a.size();i++)
        {
            //cout<<i<<endl;
            //cout<<right[i+1]<<endl;
            if(i==0)arr.push_back(right[i+1]);
            else if(i==a.size()-1)arr.push_back(left[a.size()-2]);
            else arr.push_back(left[i-1]*right[i+1]);
        }
        return arr;
    }
};
```