```
// 思路很简单 关键是有些容易错的东西
// erase（）和 vector 长度可变之间的微秒关系
// 首先， 在 vec.push_back()之前获得的iterator可能会变成野指针
//         因为随着vec的元素增多，原来的物理内存空间放不下了就要找其他位置的来放
//         那么在这之前的 iterator 指向的位置就有问题了
// 那么， erase（）呢？ 
//         小心使用的话还好， iter = vec.erase(iter)  获得新的迭代器
//          所以下面一遍遍历过去按照规则 还是安全的走完了
//      但是，在删除多余的‘（’的时候可不是在乱删的，位置必须是从后往前（恰好和stack的顺序一样）
//          因为erase（）一个元素以后 后面的元素向前移一位
// 那问题来了， 如果我在 erase（）之前入栈的 迭代器岂不是指向有问题了？因为元素前移了嘛
//      是的，如果是在erase 之前入栈 并且！ erase操作移动了哪些迭代器指向的元素
// 仔细想想，下面的过程其实没有影响到
//      因为，即使erase移动了后面的元素，但是后面的元素还没遍历到，也就还没保存迭代器呢， 那肯定没事
//      而已经入了栈保存的， 又不会被移动， 挺好
// 这里提出来是要 惊醒下次未必是如此。
// 
// ！！！ push_back()  之前的不要迭代器
// ！！！ erase() 需谨慎


// 思路： 合法的括号必定是： 右括号必须要有已经遍历了的 左括号匹配  没什么好讲的
//         最后在还有没匹配的左括号肯定是 多余的 去掉即可

// 缺点： 速度慢，老是erase来erase去的
//
// 本来尝试用增量的办法，结果发现  pushu_back 后迭代器野指针的问题
// 所以可以先建好空间，这样空间够，所以不会变动内存物理位置，指针能保持不变
// 效果比原来的好一些，好像还不够快啊（最后多余的那些左括号都处于 最左侧，每次erase还是费劲）
// 但是又无法提前知道是不是多余的
// 要不干脆直接记下所有的要删去的位置， 一次遍历生成最终的数组， 多数情况下都比 erase来来去去的好
// 果然， 这样好些，从40ms变成 28ms
// 不过破坏了原来的string 有需要可以考虑备份


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<string::iterator> left;
        int size = s.size();
        string::iterator ps = s.begin();
        string ans;
        
        if (size == 0)
            return s;
        
        while(ps != s.end()){
            if (*ps == '(' ){
                left.push(ps);
            }
            else if (*ps == ')' ){
                if (left.empty()){
                    *ps = '#';      // '#' 作为待删除标记
                }
                else
                    left.pop();
            }
            ps ++;
          
        }
        
        
        while (!left.empty()){
            *(left.top()) = '#';
            left.pop();
        }
        
        ps = s.begin();
        while (ps != s.end()){
            if (*ps != '#')
                ans.push_back(*ps);
            ps ++;
        }
        
        return ans;
    }
};

/*  原始方案

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<string::iterator> left;
        int size = s.size();
        string::iterator ps = s.begin();
        
        if (size == 0)
            return s;
        
        while(ps != s.end()){
            if (*ps == '(' ){
                left.push(ps);
            }
            else if (*ps == ')' ){
                if (left.empty()){
                    ps = s.erase(ps);
                    continue;
                }
                else
                    left.pop();
            }
            ps ++;
          
        }
        
        
        while (!left.empty()){
            s.erase(left.top());
            left.pop();
        }
        
        return s;
    }
};
*/
```
