### 解题思路
先将每个字符串反转，再将整个字符数组排序；
针对排序后的字符数组中的每个字符串来说，如果它后面的串能包含它，就不计它的长度；
否则，就计它的长度+1

### 代码

```cpp
class Solution {
public:
    bool  static cmp(const string str1,const string str2){
        return str1<str2;
    } 
    bool fun(string left,string right){
        //right不能包含left,返回false.否则返回true
        //相同前缀，长的一定在右边（后边）
        int index=0,point=min(left.size(),right.size());
        while(index < point && left[index]==right[index]){
            index++;//从左边第一个字符开始遍历
        }
        return index==point;
    }
    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
        }//先反转每个字符串
        sort(words.begin(),words.end(),cmp);//再排序整个字符数组
        int sum=0;
        bool flag;
        for(int i=0;i<words.size()-1;i++){
            flag=fun(words[i],words[i+1]);
            if(flag==false)//后一个不能包含前一个
            {
                sum+=words[i].size()+1;
            }
        }
        sum+=words.back().size()+1;//不管能不能包含，最后一个肯定要加上
        return sum;
    }
};
```