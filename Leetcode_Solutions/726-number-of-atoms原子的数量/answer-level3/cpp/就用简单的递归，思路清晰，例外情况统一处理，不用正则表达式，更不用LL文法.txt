[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)
本题就是带括号表达式求值的一种。

难点在于如何处理括号和求括号内部的表达式。

# 解法一 递归求解括号中的表达式
整体分成三大部分：

1. 在没有遇到括号前，逐个解析原子名称和数量。
2. 在遇到左括号时，递归解析表达式，将结果存入一个哈希表中。例如，(SO3)2，遇到左括号，递归解析SO3。
3. 递归返回之后，看右括号后边有没有数字。当有数字时，要取出当倍数。例如：(SO3)2，右括号后边的数字2是括号内部表达式的倍数。

**先看，原子名称的解析。**

原子名称从一个大写字母开始，到下一个大写字母或数字或括号为止。

显然，名称的第一个大写字母不能放入判断条件，否则所有的名称就只能是一个大写字母。

因此，提取名称的思路：
```
位置p是一个大写字母;
位置p++;
while (位置p有效  并且  位置p处的字符a是小写字母){
    位置p++;
}
此时位置p或者无效，或者位置p处字符a，要么是数字，要么是大写字母，要么是括号;
原子名称 = 第一个大写字母的位置到位置p-1的全部字符;
```
代码实现：
```
int beg_of_name = p;
//是个大写字母，跳过
++p;

//后面是小写字母时，全部跳过，直到数字或大写字母或'()'
while(p < s.size() && isalpha(s[p]) && islower(s[p])){
	p++;
}
string name=s.substr(beg_of_name,p-beg_of_name);
```
用到了isalpha判断字符，islower判断小写。substr取子串。

**再取，名称的个数。**
名称后面跟着数字的，将数字串转成整数。没有跟着数字的个数就是1.

重点在，数字串转成整数。
```
count = 0;
while (位置p有效 且 位置p处的字符a是数字字符){
    count = 10*count + 字符a的数字值。
}
if (count为0){
    //名称后面没跟数字串
    count = 1;
}
```
代码：
```
//获取个数
long long count = 0;
while(p < s.size() && isdigit(s[p])){
	count = count * 10 + (s[p]-'0');
	p++;
}
if(count == 0) count=1;
```
用到isdigit判断数字字符。

**碰到左括号要递归。**
子递归完成名称和个数的提取。

递归返回后，要提取括号后边的倍数。提取方法与上面提取个数的方法完全一致。

递归部分的逻辑：
```
if(位置p处的字符为左括号){
    位置p++;
    递归(位置p);
    位置p跳过右括号;
    取括号后的倍数f;
    括号内部的个数全部扩充f倍；
}else if(位置p处的字符为右括号) 返回；
```
代码：
```
if(s[p] == '('){
	unordered_map<string,long long> sub;
	int next_p = dfs(s,++p,sub);
	//更新p到')'的下一个位置
	p = next_p + 1;
	//括号后是否有倍数
	long long f = 0;
	while(p < s.size() && isdigit(s[p])){
		f = 10*f + (s[p]-'0');
		p++;
	}
	if(f==0) f=1;
	//累加括号内的计数
	for(auto & x : sub){
		out[x.first] += x.second * f;
	}
}
else if(s[p]==')'){
	break;
}
```
此处，用哈希表记录递归解析的结果。

将上面的步骤合起来整理为表达式解析的过程，结果存入哈希表：
```
int dfs(const string& s,int beg,unordered_map<string,long long>& out){
	int p=beg;
	while(p<s.size()){
		
		//第一个是否是大写字母
		if(s[p] == '('){
			unordered_map<string,long long> sub;
			int next_p = dfs(s,++p,sub);
			//更新p到')'的下一个位置
			p = next_p + 1;
			//括号后是否有倍数
			long long f = 0;
			while(p < s.size() && isdigit(s[p])){
				f = 10*f + (s[p]-'0');
				p++;
			}
			if(f==0) f=1;
			//累加括号内的计数
			for(auto & x : sub){
				out[x.first] += x.second * f;
			}
		}
		else if(s[p]==')'){
			break;
		}
		else{
			int beg_of_name = p;
			//不可能是数字开头，一定是个大写字母，跳过
			++p;
		
			//后面是小写字母时，全部跳过，直到数字或大写字母或'()'
			while(p < s.size() && isalpha(s[p]) && islower(s[p])){
				p++;
			}
			string name=s.substr(beg_of_name,p-beg_of_name);
			//获取个数
			long long count = 0;
			while(p < s.size() && isdigit(s[p])){
				count = count * 10 + (s[p]-'0');
				p++;
			}
			if(count == 0) count=1;
			//cout << name <<","<<count<<endl;
			out[name] += count;
		}
	}
	return p;
}
```
由于结果要求名称字典排序。要将其从哈希表导入vector。并定义一个新的节点node，方便vector排序。
```
    struct node{
        string who;
        int cnt;
        node(const string& _who="",int _cnt=0):who(_who),cnt(_cnt){}
        bool operator<(const node& o)const{
            return who < o.who;
        }
    };
    string countOfAtoms(string formula) {
        unordered_map<string,long long> sub;
        //表达式解析
        int r=dfs(formula,0,sub);
        //排序
        vector<node> v;
        for(auto & x : sub){
            v.push_back(node(x.first,x.second));
        }
        sort(v.begin(),v.end());
        stringstream ss;
        for(auto & x : v){
            ss << x.who;
            if(x.cnt > 1){
                ss << x.cnt;
            }
        }
        return ss.str();
    }
```
## AC的代码:
```
class Solution {
public:
    struct node{
        string who;
        int cnt;
        node(const string& _who="",int _cnt=0):who(_who),cnt(_cnt){}
        bool operator<(const node& o)const{
            return who < o.who;
        }
    };
    string countOfAtoms(string formula) {
        unordered_map<string,long long> sub;
        int r=dfs(formula,0,sub);
        //排序
        vector<node> v;
        for(auto & x : sub){
            v.push_back(node(x.first,x.second));
        }
        sort(v.begin(),v.end());
        stringstream ss;
        for(auto & x : v){
            ss << x.who;
            if(x.cnt > 1){
                ss << x.cnt;
            }
        }
        return ss.str();
    }
    
    int dfs(const string& s,int beg,unordered_map<string,long long>& out){
        int p=beg;
        while(p<s.size()){
            
            //第一个是否是大写字母
            if(s[p] == '('){
                unordered_map<string,long long> sub;
                int next_p = dfs(s,++p,sub);
                //更新p到')'的下一个位置
                p = next_p + 1;
                //括号后是否有倍数
                long long f = 0;
                while(p < s.size() && isdigit(s[p])){
                    f = 10*f + (s[p]-'0');
                    p++;
                }
                if(f==0) f=1;
                //累加括号内的计数
                for(auto & x : sub){
                    out[x.first] += x.second * f;
                }
            }
            else if(s[p]==')'){
                break;
            }
            else{
                int beg_of_name = p;
                //不可能是数字开头，一定是个大写字母，跳过
                ++p;
            
                //后面是小写字母时，全部跳过，直到数字或大写字母或'()'
                while(p < s.size() && isalpha(s[p]) && islower(s[p])){
                    p++;
                }
                string name=s.substr(beg_of_name,p-beg_of_name);
                //获取个数
                long long count = 0;
                while(p < s.size() && isdigit(s[p])){
                    count = count * 10 + (s[p]-'0');
                    p++;
                }
                if(count == 0) count=1;
                //cout << name <<","<<count<<endl;
                out[name] += count;
            }
        }
        return p;
    }
};
```