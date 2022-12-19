题目给了字符串s和行数numRows，基本思路就是按自己找到的规律扫描字符串，把原字符串中每个字符按规律存入新字符串，最后返回新字符串。
这种题之前在ccf里面做过类似的，都是慢慢去找数据之间的联系，首先考虑numRows等于1或者2的情况，作特殊情况处理，还有字符串长度小于numRows也作为特殊情况处理，接下来就是考虑numRows大于等于3的情况了，下面我们来找规律：（如图所示）
![Z字形变换题的解题思路.jpg](https://pic.leetcode-cn.com/ec6f408dfc6ad3db715829ff91ff59fc669590fd2e294d10053f1bb020b24e6c-Z%E5%AD%97%E5%BD%A2%E5%8F%98%E6%8D%A2%E9%A2%98%E7%9A%84%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF.jpg)

大概就是图片里的意思，总结一下就是，每一行后面的字符都跟该行第一个字符存在联系，接下来看代码：
```
class Solution {
public:
    string convert(string s, int numRows) {
        //首先定义一个接收字符串
        string re;
        //判断特殊情况
        if(s.size() <= numRows) return s;
        if(numRows == 1) return s;
        else if(numRows == 2) {
            //当行数等于2时，分奇偶进行存储
            for(int i = 0; i < s.size(); i += 2) {
                re.push_back(s[i]);
            }
            for(int i = 1; i < s.size(); i += 2) {
                re.push_back(s[i]);
            }
            return re;
        }
        //正式开始处理有规律的numRows大于等于3的情况
        else {
            //这个标记会在i既不是第一行也不是最后一行的时候用到
            bool flag = true;
            //开始从一行遍历
            for(int i = 0; i < numRows; i++) {
                //当目前处于第一行时
                if(i == 0) {
                    for(int j = i; j < s.size(); j += (2 * numRows - 2)) {  
//这个2*numRows-2就是我们找出来的规律，写出：numRows + numRows -2 更容易理解，比如此时行数为3，那么我们知道，第一行和最后一行都是间隔为4，
//即3 + 1， 比较行数为4和5的情况，我们知道应该写出3+3-2
                        re.push_back(s[j]);
                    }
                }
                //当目前是最后一行时
                else if(i == (numRows - 1)) {
                    for(int j = i; j < s.size(); j += (2 * numRows - 2)) {
                        re.push_back(s[j]);
                    }
                }
                //当目前处于中间任意一行时
                else {
                    int j = i;
                    //首先存储该行第一个字符
                    re.push_back(s[j]);
                    while(j < s.size()) {
                        //第一次进来要执行我们的第一类规律，就是每行都是numRows + numRows - 2 - 2*i，这个i为行数
                        if(flag) {
                            flag = false;
                            j += 2 * numRows - 2 - i * 2;
                            //每次计算出新的间隔后，要判断存值前是否还在字符串的最大范围内
                            if(j >= s.size()) break;
                            re.push_back(s[j]);
                        }
                        //执行一次有，我们跳跃的间隔要变成总间隔减去上次的间隔。这个上一次和这一次不同就是靠flag来判断的
                        else {
                            flag = true;
                            j += 2 * numRows - 2 - (2 * numRows -2 - i * 2);
                            if(j >= s.size()) break;
                            re.push_back(s[j]);
                        }
                    }
                }
                //当进行下一行时，将flag复原
                flag = true;
            }
        }
        return re;
    }
};
```

代码作了详细的注释，应该看得懂。
这个题的类型就是找规律+模拟。
