### 解题思路
1. 字符串的长度必须在 [4,12] 

2. IP地址的特点： 一串长度介于4-12的数字中增加三个点，隔成四个数，每个数的大小在[0,255]

3. 注意：不能出现前导零，单独的零可以出现。
   如0.0.0.0正确，  但0.0.0.001、0.0.0.01、0.0.0.000等不正确

4. 回溯：dfs(string s,剩下需要插入字符串的点的个数，当前最后一个点的位置)
【1】如果剩下需要插入字符串的点的个数为0 :
1）最后一个点到字符串结束之间的数的大小符合条件，加入结果，并返回
2）最后一个点到字符串结束之间的数的大小不符合条件，直接返回
【2】从上一个点的后一个位置开始依次遍历可以插入点的地方
满足条件就插入点，继续递归。递归退出需要删去上一个点

5. dfs中需要注意的边界：见代码注释

6. string 函数：
- erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
- erase(position);删除position处的一个字符(position是个string类型的迭代器)
- erase(first,last);删除从first到last之间的字符（first和last都是迭代器）
- string &insert(int p0, const char *s);——在p0位置插入字符串s
- string &insert(int p0, const char *s, int n);——在p0位置插入字符串s的前n个字符
- string &insert(int p0,const string &s);——在p0位置插入字符串s
- string &insert(int p0,const string &s, int pos, int n);——在p0位置插入字符串s从pos开始的连续n个字符
- string &insert(int p0, int n, char c);//在p0处插入n个字符c
- iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置
- void insert(iterator it, const_iterator first, const_iteratorlast);//在it处插入从first开始至last-1的所有字符
- void insert(iterator it, int n, char c);//在it处插入n个字符c


### 代码

```cpp
class Solution {
public:
    vector<string> res;

    bool judge(string s,int i,int j){   //判断string[i,j]中的数是否满足条件
        long int sum = s[i] - '0';      //开得大一点
        if(sum == 0 && j > i) return false;  //消去前导零的情况（第一个为0，且后面还有数字）
        while(i != j){
            ++ i;
            sum = sum * 10 + s[i] - '0';
        }
        if(sum >= 0 && sum <= 255)
           return true;
        return false;
    }

    void dfs(string s,int dot,int pre){
        if(dot == 0){
            if(judge(s,pre + 1,s.size() - 1))   //边界
               res.push_back(s);
            return;
        }
        for(int i = pre + 1;i < s.size() - 1;i ++){  //边界：最后一个点一定在s[s.size()-1]前
            if(judge(s,pre + 1,i)){
                s.insert(s.begin() + i + 1,'.');
//              cout<<s<<" "<<dot<<endl;
                dfs(s,dot - 1,i + 1);
                s.erase(s.begin() + i + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return res;
        dfs(s,3,-1);
        return res;
    }
};
```