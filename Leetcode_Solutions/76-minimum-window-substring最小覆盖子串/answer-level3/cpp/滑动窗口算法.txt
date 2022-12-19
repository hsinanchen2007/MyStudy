**题目描述**
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。


**思路**
1.设置两个字符哈希数组，map_window和map_t。map_window代表当前处理的窗口区间中的字符数量，map_t代表子串T的字符数量。
2.设置两个指针（记作指针i与指针begin）指向字符串的第一个字符。
3.i指针向后逐个扫描字符串中的字符，在这个过程中，循环检查begin指针是否可以向前移动：
    - 如果当前begin指向的字符在T中没出现，直接前移begin；
    - 如果begin指向的字符在T中出现了，但当前区间窗口中的该字符数量足够，向前移动begin，并更新map_window；
    - 否则不能移动begin，跳出检查。
4.指针i每向前扫描一个字符，即检查一下是否可以更新最终结果（找到最小的包含T中各个字符的窗口）。
在整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足题目要求（包含T中所有字符），窗口线性向前滑动，整体时间复杂度为O（n)。

**C++代码**
```
class Solution {
private:
    //用于检查某一字符串是否包含t中的所有字符
    bool is_window_ok(int map_s[],int map_t[],vector<int> &vec_t){
        for(int i=0;i<vec_t.size();++i){  //利用vec_t遍历t中出现的字符
            if(map_s[vec_t[i]]<map_t[vec_t[i]]){
                return false;  //如果s中出现该字符的数量小于t中出现该字符的数量，返回false
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        const int MAX=128; //char0-127，利用数组下标记录字符个数
        int map_s[MAX]={0}; //记录s字符串各字符个数
        int map_t[MAX]={0}; //记录t字符串各字符个数
        vector<int> vec_t;  //记录t中有哪些字符
        for(int i=0;i<s.length();++i){
            ++map_s[s[i]];  //遍历s，记录s中字符个数
        }
        for(int i=0;i<t.length();++i){
            ++map_t[t[i]];  //遍历t，记录t中字符个数
        }
        for(int i=0;i<MAX;++i){
            if(map_t[i]>0){
                vec_t.push_back(i); //遍历，将字符串t中出现的字符存储到vec_t中
            }
        }
        //判断s中是否存在这样的子串
        if(!is_window_ok(map_s,map_t,vec_t)){
            return ""; //如果不存在，返回""
        }
        //如果存在，往下执行
        int begin=0; //最小窗口起始指针
        string result=s; //结果字符串
        int map_window[MAX]={0}; //记录窗口中的字符个数
        for(int i=0;i<s.length();++i){
            ++map_window[s[i]]; //记录当前窗口中字符串的字符数量
            while(begin<i){ //检查begin指针是否需要前移
                char begin_ch=s[begin];
                if(map_t[begin_ch]==0){ //如果当前begin所指字符没有在t中出现
                    ++begin;
                }
                else if(map_window[begin_ch]>map_t[begin_ch]){//如果当前begin所指字符在当前窗口中的数量大于t中的数量
                    --map_window[begin_ch];  //更新当前窗口的字符数量
                    ++begin;  
                }
                else{
                    break; //如果没有上面的两种情况，结束此次begin的判断
                }
            }
            //检查当前窗口字符串是否符合要求
            if(is_window_ok(map_window,map_t,vec_t)){
                int new_window_len=i-begin+1;
                if(new_window_len<result.size()){ //若符合要求，且新的字符串要比之前的短，则更新结果字符串
                    result=s.substr(begin,new_window_len);
                }
            }
        }
        return result;
    }
};
```
