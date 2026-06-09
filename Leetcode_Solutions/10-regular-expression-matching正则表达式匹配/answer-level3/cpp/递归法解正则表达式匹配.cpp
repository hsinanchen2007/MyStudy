程序调用自身的编程技巧称为递归（ recursion）。递归做为一种算法在程序设计语言中广泛应用。 一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。递归的能力在于用有限的语句来定义对象的无限集合。一般来说，递归需要有边界条件、递归前进段和递归返回段。当边界条件不满足时，递归前进；当边界条件满足时，递归返回。

```
class Solution {
public:
    bool isMatch(string s, string p) {

    }
};
```

# 题目分析
假设我们有：
s = "abadddffghi"
p = "a.ad*.*gh."

我们去分析s,p是否match时，会从左往右依次比较，对于当前比较的两个char来说，p中的字符是我们需要重点关注的，因为特殊字符只会出现在p中； [1]p中如果是普通字符（或 .），直接比较是否与s对应的相等，不相等直接返回false，判断结束；[2]p如果遇到*，处理起来就比较麻烦了。比较好的一种方法是利用递归。
1,将*当0处理，则直接从将p的当前位置向后移动一位与s当前位置进行比较；
2,将*当任意非零数字处理，则需要判断该符号前的元素重复需要的次数后是否能与s对应匹配，这里如果用逻辑判断或比较麻烦，应该用递归的方法去做。举例如下：

![img1.jpg](https://pic.leetcode-cn.com/cf4a6eea33d2163f6e898ffcd1a6434aeb06552519a2f5c44b4dcd72b6bf63e2-img1.jpg)

```
class Solution {
public:
    bool isMatch(string s, string p) {
        //cnt++;
        //cout<<"cnt "<<cnt<<endl;
        //cout<<"s:"<<s[0]<<" p:"<<p[0]<<endl;
        if (p.empty()) return s.empty();    //判断是否为空

        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.'); //比较s,p当前指向s[0],p[0];

        if (p.length() >= 2 && p[1] == '*') {   //特殊情况下的处理，这个是关键
            //对应特殊情况下的两个选择
            //return isMatch(s,p.substr(2))表示跳过*去匹配
            //return first_match && isMatch(s.substr(1),p)表示p借助*去匹配s中的重复元素
            //采用将s首元素不断右移的方法，递归处理
            //用||连接，起到很巧妙的作用
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)); //调用次数问题
            //如果first_match已经为false，那么  &&后面的isMatch还会被继续调用么？
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};
```


上面的解法确实可以通过所有的case解决问题，但是考虑到其内存消耗和运行时间，并不是一个好的程序。其实，算法本身并不是很复杂，虽然使用了递归，但递归并不是制约运行时间和内存消耗的关键。最主要的原因是程序中大量调用了string中的substr函数，它的形式是：
```
s.substr(pos,n)
返回一个string，包含s中从pos开始的n个字符的拷贝
```
因此在调用过程中会涉及很多字符串的拷贝，需要减少这个拷贝的步骤。应该拒绝使用这个substr函数，优化后后的代码如下：

```
class Solution {
public:
    bool isMatch(string s, string p) {
        int index1 = 0, index2 = 0;
        bool ret = matchTwo(s,index1,p,index2);
        return ret;
    }
private:
    bool matchTwo(string &s,int index1,string &p,int index2){   //使用引用
       
        int ls = s.length(),lp = p.length(); //记录总长度，并与当前比较
        if(index2 >= lp){
            return index1 >= ls;
        }

        bool firstMatch = (index1 < ls) && (s[index1] == p[index2] || p[index2] == '.');
        cout<<"firstMatch "<<firstMatch<<endl;
        if((lp - index2 >= 2) && p[index2 + 1] == '*'){
            return matchTwo(s,index1,p,index2+2) || (firstMatch && matchTwo(s,index1+1,p,index2));
        }else{
            return firstMatch && matchTwo(s,index1+1,p,index2+1);
        }

    }
};

```

