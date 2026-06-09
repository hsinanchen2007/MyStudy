// 【思路1】
// 1. 用vector<int>pos记录下字符起始位置的下标，求出缩水数组长度;
// 2. 若需要进行缩水，那么对原来的S从后往前进行:
// - 根据pos保存的值，找到字符位置pos[j];
// - 计算这个字符重复次数cnt=pos[j+1]-pos[j]，即：pos中保存的下一个字符起点-当前字符起点;
//     - 注意：👆对于最后一个字符，为了记录其重复次数，所以pos保存的时候需要保存一下S.size()对应的数值，也就是不存在的“下一个字符起点”;
// - 保留字符起点，删除它之后的cnt-1个字符;
// - 在pos[j]+1之前插入代表重复次数的字符cnt。
// - 然后j--找下一个字符，重复上述操作，直到pos遍历结束。

// 【下面是代码】
// ```
class Solution {
public:
    string compressString(string S) {
        vector<int> pos;
        int ss = (int)S.size();
        for(int i = 0; i < ss ; i++){
            if(pos.empty()){ pos.push_back(i); }
            else if(S[i] != S[i-1]){ pos.push_back(i); }
        }
        int sp = (int)pos.size(); // 多少个不同字符
        int len = sp*2; // 缩水后总长度
        pos.push_back(ss); // 为了确定最后一个字符重复多少个，所以需要添加结尾
        if(ss > len){// 若原字符串长，则需要缩水写法
            for(int j = sp-1; j >= 0; j--){ // 找到最后一个字符，从后往前置换
                int cnt = pos[j+1]-pos[j];
                S.erase(pos[j]+1, cnt-1); //从pos[j]+1这个位置开始，删除cnt-1个字符
                S.insert(pos[j]+1, to_string(cnt)); //在指定位置前面插入字符
            }
        }
        return S;
    }// end_compressString
};

// ```
// 【效果】
// 执行结果：通过 显示详情
// 执行用时 :12 ms, 在所有 C++ 提交中击败了86.18%的用户
// 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户

// 【思路2】
// 这是我最初的想法，求出缩水后的字符串，再比较，但是超出内存限制，当时没想出问题在哪儿，现在知道了。
// 【旧代码】
// ```
class Solution {
public:
    string compressString(string S) {
        string res = "";
        int cnt = 0;
        for(int i=0; S[i]; i++){
            if(res.empty()){
                cnt++;
                res.push_back(S[i]);
            }else if(S[i]==S[i-1]){
                cnt++;
            }else{
                res = res+to_string(cnt);
                cnt = 1;
                res.push_back(S[i]);
            }
        }// end_for
        res = res+to_string(cnt);
        int nres = (int)res.size();
        int ns = (int)S.size();
        res = nres<ns ? res: S;
        return res;
    }// end_compressString
};
// ```
// 【改进】
// 看了题解，发现res = res+to_string(cnt)会超出内存限制，但是改成+=就不会：
// 为什么呢？以a=a+b和a+=b为例：
// - a = a + b; 意味着取a的值，取b的值，**然后把a和b求和的结果放到寄存器里**，再把寄存器里的值给了a
// - a += b;  意味着取a的值，取b的值，然后把a和b求和的结果给了a

// 【最终代码】
// ```
class Solution {
public:
    string compressString(string S) {
        string res = "";
        int cnt = 0;
        for(int i=0; S[i]; i++){
            if(res.empty()){
                cnt++;
                res.push_back(S[i]);
            }else if(S[i]==S[i-1]){
                cnt++;
            }else{
                res += to_string(cnt);
                cnt = 1;
                res.push_back(S[i]);
            }
        }// end_for
        res = res+to_string(cnt); // 这里哟
        int nres = (int)res.size();
        int ns = (int)S.size();
        res = nres<ns ? res: S;
        return res;
    }// end_compressString
};

// ```
// 【效果】
// 执行用时 :8 ms, 在所有 C++ 提交中击败了97.61%的用户
// 内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户
