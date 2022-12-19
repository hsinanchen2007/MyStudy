### 解题思路
等价于一个十位数的二进制数，输出取n位为1的所有情况（去除其中不符合时间表示的情况）
可以同样看做一棵树，初始化的二进制序列为“0000000000”，递归传输一个下标index和一个计数器计数目前是放第几个1，代表对某位进行放值操作，放0和放1位两种情况（相当于两颗子树）
如果放0，则访问下一个下标，但是计数器计数不变，如果放1，则访问下一个下标，计数器计数+1
就像遍历二叉树一样即可
然后得到所有的二进制结果后转为十进制结果就行了
### 代码

```cpp
class Solution {
public:
    //二进制转十进制
    int getval(string s) {
        int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum = sum << 1 | (s[i] - '0');
        }
        return sum;
    }

    //又是dfs，一共10位，按照树的遍历得到n位为1的所有情况（叶子结点），保存符合时间规则的
    //ans为传递的答案数组，str为传递进来的字符串(初始为10位0)，now_num为第几个要放的1，n为传递的目标1个数
    void dfs(vector<string> &ans, string str, int index, int now_num, int n) {
        if (now_num > n) {
            ans.push_back(str);
            return;
        }
        if (index >= 10) return;
        //如果还能放数字
        //一次此位放1
        string temp = str.substr(0, 10);
        temp[index] = '1';
        dfs(ans, temp, index + 1, now_num + 1, n);
        //一次此位放0
        dfs(ans, str, index + 1, now_num, n);

    }

    //将10位二进制数转换为十进制时钟格式
    vector<string> helper(vector<string> &ans_b) {
        vector<string> ans;
        int size = ans_b.size();
        for (int i = 0; i < size; i++) {
            int hh = getval(ans_b[i].substr(0, 4));
            int mm = getval(ans_b[i].substr(4, 6));
            if (hh > 11 || mm > 59) continue;
            else {
                string str = "";
                str += to_string(hh);
                str += ":";
                if(mm < 10) str += "0";
                str += to_string(mm);
                ans.push_back(str);
            }
        }
        return ans;
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> ans_b;
        if(num == 0) {
            ans_b.push_back("0:00");
            return ans_b;
        }
        string str = "0000000000";
        dfs(ans_b, str, 0, 1, num);
        return helper(ans_b);
    }
};
```