```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //s是否为t的子序列，s很短，t很长

        //index1指向s，index2指向t
        //按i1所指元素，逐个查找t，如果找到了最后一个元素，return true
        int index1=0,index2=0;
        while(index1<s.size()&&index2<t.size())
        {
            if(s[index1]==t[index2])
            {index1++;index2++;}
            else {index2++;}

        }
        if(index1==s.size()){return true;}
        else {return false;}




    }
};
```
