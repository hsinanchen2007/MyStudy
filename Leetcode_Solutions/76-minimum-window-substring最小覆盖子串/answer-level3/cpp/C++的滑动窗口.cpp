看到还没有c++的做法所以写一下。
思路在官方题解里面写得很清楚，这里我是把“知道了思路该如何写成代码”，以及，“在写代码的时候我所遇见的问题”做一个简单的总结。
```
class Solution {


public:
    string minWindow(string s, string t) {
        string str,temp;
        int exist[1000],count=0;//exist数组是来观察T中是否存在S没有的字符，即题目是否无解
        memset(exist,0,sizeof(exist));
        for(int i=0;i<s.size();i++)
            exist[s[i]]++;
        for(int i=0;i<t.size();i++)
            if(exist[t[i]]==0)
                return str;//如果T中存在S不存在的元素返回空字符串
        int min=1000000000,begin=0,end=0;//记录个数
        unordered_map<char,int> tmap,findmap;
        for(int i=0;i<t.size();i++){//t中每个字符的个数
            if(tmap.count(t[i])==0)
                tmap[t[i]]=1;
            else
                tmap[t[i]]++;
        }
        while(tmap.count(s[begin])==0){//找到第一个可以t中字符
                begin++;
                end++;
        }
        //sliding window
        while(end<s.size()){
            while(count<t.size()&&end<s.size()){//这边和外面的条件相同，里面放宽运行错误，外面放宽无限循环
                temp+=s[end];
                if(tmap.count(s[end])!=0){
                    if(findmap.count(s[end])==0)
                        findmap[s[end]]=1;
                    else
                        findmap[s[end]]++;
                    if(findmap[s[end]]<=tmap[s[end]])//收集到有效字符
                        count++;
                 }
                end++;
            }
            while(count==t.size()){//当t中的元素全部在窗口里了，begin右滑，找到第一个不符合规定的位置
                if(tmap.count(s[begin])!=0){
                    findmap[s[begin]]--;
                    if(findmap[s[begin]]<tmap[s[begin]]){
                        //begin++;
                        count--;
                    }
                }//这里很容易移动窗口了，但这样的话后面不好判断
                if(temp.size()<min){//每次滑动窗口之后判断
                    min=temp.size();
                    str=temp;
                }
                begin++;
                temp.erase(temp.begin());//这两句话要永远在一起
            }
            while(tmap.count(s[begin])==0&&begin<end){//找到下一个符合标准的位置
                begin++;
                temp.erase(temp.begin());
            }
        }
        return str;
    }
};
```

