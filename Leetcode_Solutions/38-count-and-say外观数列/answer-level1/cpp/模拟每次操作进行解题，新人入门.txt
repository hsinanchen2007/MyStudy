简单来说就是用循环来模拟每次过程，从n=1一级一级往上模拟，由于n=1和n=2比较特殊，所以可以单独用if进行判断，然后n=3开始就可以基于前面的n-1来得出结果，我们需要一个计数变量count和一个暂存字符串，下面看详细注释
```
class Solution {
public:
    string countAndSay(int n) {
        //re后面用于暂存阶段性数好的相同元素个数
        string re = "1";
        //s存n-1的字符串，最后一次也相当于存n的字符串，具体看下面循环内
        string s = "11";
        //n==1和2单独考虑，不然不好写循环
        if(n == 1) {
            return re;
        }
        else if(n == 2) {
            return s;
        }
        else {
            //开始进入循环，先对re清空，它是用来存扫描s的阶段性成果的，上面对re赋值只是为了少写一个变量
            re.clear();
            for(int i = 3; i <= n; i++) {
                //i对应的层数的结果是来自i-1层的s字符串
                int count = 1;
                for(int j = 0; j < s.size() - 1; j++) {
                    //当目前j下标的字符与下一个字符相等时，count++
                    if(s[j] == s[j+1]) {
                        count++;
                        //并且记得判断是否达到边界
                        if(j == s.size() - 2) {
                            //这里将count转为字符，记得使用ASCII码，比如count=1时要加上48，也就是49才是字符的1
                            re.push_back((char)(count+48));
                            re.push_back(s[j]);
                            break;
                        }
                    }
                    //相邻字符不等的时候，count重置为1，并保存阶段性成果，开始进行新的一轮判断
                    else {
                        re.push_back((char)(count+48));
                        re.push_back(s[j]);
                        count = 1;
                        if(j == s.size() - 2) {
                            re.push_back((char)(count+48));
                            re.push_back(s[j+1]);
                            break;
                        }
                    }
                    
                }
                //进入到下一层时，该层的s则来自于re,并提前将re清空
                s = re;
                re.clear();
            }
        }
        return s;
    }
};
```

