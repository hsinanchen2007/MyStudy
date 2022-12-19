根据题意，实际上我们要求解的问题可以等价于：

对于small中的每一个字符模式，找到其在字串big中匹配的所有位置。

即典型的字符串模式匹配问题，可以使用KMP算法达到线性的时间复杂度。KMP算法的本质就是构造一个有限状态机。

# 构造有限状态机

如下代码，就是构造出有限状态机的部分，我在这里将其抽象为一个类，将构建出有限状态机的方法作为menber function：

```
class DPA{
public:
    DPA(){

    }

    void Set_pattern(const string &pat){
        string tmp(pat);
        swap(pattern,tmp);
    }

    vector<int> createDPA(){
        if(pattern.empty()) return {};
        int n = pattern.size();
        vector<int> DPA(n+1,0);
        int prefix = 0;
        int pos = 1;

        while(pos < n){
            while(pattern[pos] != pattern[prefix] && prefix > 0) prefix = DPA[prefix];
            if(pattern[pos] == pattern[prefix]) prefix++;
            DPA[++pos] = prefix;
        }

        return DPA;
    }

private:
    string pattern;
};
```
其中,私有数据成员pattern就是我们所说的“模式”。

set_pattern方法是将参数设置为当前的模式。

核心在于createDPA方法，也就是KMP算法的精髓所在。

这里声明了一个长为n+1的数组DPA，DPA[i]表示“已匹配前缀长度为i的情况下，上一状态对应的已匹配长度”。

什么叫“上一状态的已匹配长度”呢？举个例子：

比如当前我们有字符串 ABAC，如果目前已匹配的前缀长度是3，也就是“ABA”这部分，那么如果当前位置的字符不是"C"，我们就只能将匹配前缀转移到上一个可能的状态。而这个“上一个可能的状态”也就是“能够匹配最长前缀 的 后缀”，也就是字符“A”。而对于字符A，其对应的已匹配前缀长度就是1。所以
DPA[3] = 1。即如果在已匹配长度为3的情况下，遇到当前字符不匹配，我们就转移到已匹配长度为1的情况再对比，以此类推。


# 开始匹配

一旦构建好了有限状态机，我们就可以接着进行模式匹配了

```
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int n = big.size();    
        int m = smalls.size();
        if( m <= 0) return {};
      
        vector<vector<int>> res;
        DPA MyDpa;

        for(auto i : smalls){
            MyDpa.Set_pattern(i);
            //开始进行KMP算法匹配
            vector<int> tmpres;
            int border = i.size();
            
            if(border <= 0){
                res.push_back({});
                continue;
            }

            int match = 0;
            vector<int> DPA = MyDpa.createDPA();
            for(int j = 0 ; j < n ; ++j){
                while(match > 0 && big[j] != i[match]) match = DPA[match];
                if(big[j] == i[match]) match++;
                if(match == border){
                    tmpres.push_back(j - match + 1);
                    match = DPA[match];
                }
            }
            res.push_back(tmpres);
        }

        return res;
    }
};
```

关于匹配的核心代码其实就只有这一段：
```
for(int j = 0 ; j < n ; ++j){
    while(match > 0 && big[j] != i[match]) match = DPA[match];
    if(big[j] == i[match]) match++;
    if(match == border){
        tmpres.push_back(j - match + 1);
        match = DPA[match];
        }
    }
```
即我们不断沿着字符串big前进,如果遇到当前字符不匹配,就转移到“可能的上一个状态”。

一旦匹配长度为模式长度,说明当前已经出现了匹配点,我们将匹配的起始位置压入临时容器中。

而由于是要寻找所有可能的匹配位置，所以当已经出现了完整匹配后，我们要寻找的是下一个可能匹配的状态，所以要将match转移到上一个状态。



















