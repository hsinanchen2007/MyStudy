

> 执行用时 :4 ms, 在所有 C++ 提交中击败了69.70%的用户
> 内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户

这里使用了两个`map<string,string>`，分别存储pattern->str, str->pattern。


```c++
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //两个map， 分别是 pattern->str, str->pattern
        unordered_map<string,string> m1,m2;
        int last_pos = 0; // 标记str本次分割单词的起始位置。
        for(int i=0;i<pattern.size();i++){
            if(last_pos>= str.size()) // pattern > str
                // 分割标志已经到了末尾，说明pattern字母数量 > pattern单词数量。
                return false;
            int gap = str.find(' ',last_pos);
            if(gap ==-1){ //最后一个单词
                gap = str.size();
            }
            //截取str中第i个单词。
            string sub = str.substr(last_pos, gap - last_pos); 
            last_pos = gap +1;
            
            //截取pattern第i个字母
            string p_sub{pattern[i]};
            
            auto r = m1.find(sub);
            if(r!= m1.end()){
                // 存在从str到pattern的映射，但是值不对。
                if(r->second != p_sub) return false;
            }else{
                if(m2.find(p_sub)!= m2.end()){
                    return false; 
                    // 不存在从str到pattern的映射，却存在从pattern到str。
                }else{
                    m1[sub] = p_sub;
                    m2[p_sub] = sub;
                }
            }
        }
        if(last_pos < str.size()) // pattern < str
            //last_pos 没有指到末尾，说明str单词数 > pattern字母数。
            return false;
        return true;
    }
};
```