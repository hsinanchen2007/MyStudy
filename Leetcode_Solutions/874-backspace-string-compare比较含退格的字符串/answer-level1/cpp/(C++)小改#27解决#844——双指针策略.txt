我是根据标签练题，本题与#27移除元素有相似之处。先上代码为敬
# code
```c++ []
class Solution {
public:
    int remove (string& S){
        int index=0;
        for(auto i:S){
            if(i!='#'){
                S[index++]=i;
            }else{
                index==0?0:--index;
            }
        }
        return index;
    }
    bool backspaceCompare(string S, string T) {
        int findex=remove(S);
        int sindex=remove(T);
        if(findex!=sindex) return false;
        else{
            S=S.substr(0,findex);
            T=T.substr(0,findex);
            if(S.compare(T)==0)return true;
            else return false;
        }
    }
};
```
# 主体思路
*   发现“#”慢指针后移。
*   如果后移到0位置，则不变（code    index==0?0:--index;）
*   没有发现“#”就拷贝快指针到慢指针位置（code   S[index++]=i;）
*   重新截取str（code   S=S.substr(0,findex);）
*   比较new S和new T，返回结果

remove函数就是利用“#27移除元素”改写的“退格策略”。
# 成绩
![捕获.PNG](https://pic.leetcode-cn.com/4391c9ab6923aa74c6d3accbb07566fd7b5a393632028934917a534fc23a0fbd-%E6%8D%95%E8%8E%B7.PNG)

(PS:第一次自写 0ms，开心，一起加油！！)
