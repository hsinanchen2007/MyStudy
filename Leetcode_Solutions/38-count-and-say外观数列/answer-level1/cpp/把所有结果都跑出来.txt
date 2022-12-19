### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
string countnum(string str){
    int len =str.size();
    int j=0;
    string temp;
    for(int i=0;i<len;i++)
    {
        j=i+1;
        int num=1;
        while(str[i]==str[j]&&j<len)
        {
            j++;
            num++;
        }
        temp+=(num+'0');//几个
        temp+=str[i];//数字

        i=j-1;
        num=1;
    }
    return temp;
}
string countAndSay(int n) {
    //生成序列
    vector<string> data;
    data.emplace_back("1");
    for(int i=0;i<30;i++)
    {
        data.push_back(countnum(data[i]));
    }
    // for(int i=0;i<data.size();i++)
    // {
    //     cout<<"--------"<<i<<"-------"<<endl;
    //     cout<<data[i]<<endl;
    // }
    return data[n-1];
}
};
```